#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#define MAX_PRODUCER 3
#define QUEUE_NAME "/praktikum_5_queue"
#define MAX_MESSAGES 10


volatile sig_atomic_t stop_signal = 0;
static volatile sig_atomic_t production_active = 1;
static volatile sig_atomic_t pause_report_pending = 0;

typedef struct {
    int min_x;
    int max_x;
    int min_y;
    int max_y;
    int initialized; 
} ProducerStats;


typedef struct {
    int x;
    int y;
    int producer_id;
} Item;

typedef struct {
    int producer_id;
    mqd_t mq;
} ProducerArgs;

typedef struct {
    mqd_t mq;
} ConsumerArgs;

static void print_producer_stats(const ProducerStats stats[MAX_PRODUCER]) {
    for (int i = 0; i < MAX_PRODUCER; i++) {
        if (stats[i].initialized) {
            printf("P%d | X[min=%d max=%d] Y[min=%d max=%d]\n",
                   i + 1,
                   stats[i].min_x,
                   stats[i].max_x,
                   stats[i].min_y,
                   stats[i].max_y);
        }
    }
}



void* producer_func(void* arg) {
    ProducerArgs* data = (ProducerArgs*)arg;
    int producer_id = (*data).producer_id;
    mqd_t mq = (*data).mq;

    unsigned int product = (unsigned int)(time(NULL) ^ getpid() ^ (producer_id * 67));
    unsigned int production_time = product + 1;

    while (!stop_signal) {
        /* bei vorübergehender Pause warten, aber Thread nicht beenden */
        while (!production_active && !stop_signal) {
            usleep(100000);
        }
        Item item;
        item.x = rand_r(&product) % 10001;
        item.y = rand_r(&product) % 10001;
        item.producer_id = producer_id;

        if (mq_send(mq, (const char*)&item, sizeof(Item), 0) == -1) {
            perror("mq_send");
        } else {
            printf("Producer %d sendet X = %d, Y = %d\n", producer_id, item.x, item.y);
        }

        usleep((rand_r(&production_time) % 4) * 1000000);
    }

    return NULL;
}

void* consumer_func(void* arg) {
    ConsumerArgs* data = (ConsumerArgs*)arg;
    mqd_t mq = (*data).mq;
    ProducerStats stats[MAX_PRODUCER] = {0};
    unsigned int consumer_seed = (unsigned int)(time(NULL) ^ getpid() ^ (unsigned long)pthread_self());

    while (!stop_signal) {
        Item item;
        struct timespec timeout;
        timeout.tv_sec = time(NULL) + 1;
        timeout.tv_nsec = 0;

        ssize_t bytes = mq_timedreceive(mq, (char*)&item, sizeof(Item), NULL, &timeout);

        if (bytes == -1) {
            if (errno == ETIMEDOUT) {
                if (pause_report_pending) {
                    print_producer_stats(stats);
                    pause_report_pending = 0;
                }
                continue;
            } else {
                perror("mq_timedreceive");
                break;
            }
        }
        int producer_index = item.producer_id - 1;
        if (!stats[producer_index].initialized) {
            stats[producer_index].min_x = item.x;
            stats[producer_index].max_x = item.x;
            stats[producer_index].min_y = item.y;
            stats[producer_index].max_y = item.y;
            stats[producer_index].initialized = 1;
        } else {
            if (item.x < stats[producer_index].min_x) {
                stats[producer_index].min_x = item.x;
            }
            if (item.x > stats[producer_index].max_x) {
                stats[producer_index].max_x = item.x;
            }
            if (item.y < stats[producer_index].min_y) {
                stats[producer_index].min_y = item.y;
            }
            if (item.y > stats[producer_index].max_y) {
                stats[producer_index].max_y = item.y;
            }
        }

        if (pause_report_pending) {
            print_producer_stats(stats);
            pause_report_pending = 0;
        }

        usleep((rand_r(&consumer_seed) % 1000) * 1000);
    }

    if (pause_report_pending) {
        print_producer_stats(stats);
        pause_report_pending = 0;
    }


    return NULL;
}



void* signal_thread_func(void* arg) {
    sigset_t *set = (sigset_t*)arg;
    int s;

    while (!stop_signal) {
        if (sigwait(set, &s) != 0) {
            perror("sigwait");
            continue;
        }

        if (s == SIGUSR1) {
            production_active = !production_active;
            if (production_active) {
                printf("Produktion gestartet\n");
            } else {
                pause_report_pending = 1;
                printf("Produktion unterbrochen\n");
            }
        } else if (s == SIGUSR2) {
            production_active = 0;
            stop_signal = 1;
            printf("Beenden angefordert (SIGUSR2)\n");
        }
    }

    return NULL;
}

int main() {
    static sigset_t signal_set;
    
    pthread_t producer_thread[MAX_PRODUCER];
    pthread_t consumer_thread;
    pthread_t signal_thread;
    ProducerArgs producer_args[MAX_PRODUCER];
    ConsumerArgs consumer_args;
    struct mq_attr attr;

   

    /* block signals in all threads and prepare set for sigwait thread */
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGUSR1);
    sigaddset(&signal_set, SIGUSR2);
    pthread_sigmask(SIG_BLOCK, &signal_set, NULL);

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = sizeof(Item);
    attr.mq_curmsgs = 0;
    
    mq_unlink(QUEUE_NAME);

    /* blockierende Queue: Producer warten, wenn 10 Nachrichten schon belegt sind */
    mqd_t mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    consumer_args.mq = mq;
    printf("PID: %d\n", getpid());

    if (pthread_create(&signal_thread, NULL, signal_thread_func, &signal_set) != 0) {
        perror("pthread_create signal handler fehlgeschlagen");
        mq_close(mq);
        mq_unlink(QUEUE_NAME);
        return 1;
    }

    if (pthread_create(&consumer_thread, NULL, consumer_func, &consumer_args) != 0) {
        perror("pthread_create consumer fehlgeschlagen");
        mq_close(mq);
        mq_unlink(QUEUE_NAME);
        return 1;
    }



    for (int i = 0; i < MAX_PRODUCER; i++) {
        producer_args[i].producer_id = i + 1;
        producer_args[i].mq = mq;

        if (pthread_create(&producer_thread[i], NULL, producer_func, &producer_args[i]) != 0) {
            perror("pthread_create producer fehlgeschlagen");
            mq_close(mq);
            mq_unlink(QUEUE_NAME);
            return 1;
        }
    }

    /* Auf Stop-Signal warten (z.B. SIGUSR2) */
    while (!stop_signal) {
        usleep(100000);
    }

    /* Produktion stoppen und Producer-Threads beenden lassen */
    production_active = 0;

    for (int i = 0; i < MAX_PRODUCER; i++) {
        pthread_join(producer_thread[i], NULL);
    }

    /* Consumer beendet sich selbst, wenn stop_signal gesetzt ist und Queue leer ist */
    pthread_join(consumer_thread, NULL);
    pthread_join(signal_thread, NULL);

    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    return 0;
}