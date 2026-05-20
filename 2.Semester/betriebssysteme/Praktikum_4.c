#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>

volatile int running = 0;
int counter = 0;
volatile int stop_signal = 0;




void on_signal(int signum) {
    printf("Signal erhalten: %d\n", signum);
    if (signum == SIGUSR1) {
        running = !running;
        if (running) {
            printf("Inkrementierung gestartet\n");
        } else {
            printf("Inkrementierung unterbrochen\n");
        }
    }
    if (signum == SIGUSR2) {
        stop_signal = 1;
    }
}

void* timer_handler(void* arg) {
    while (!stop_signal) {
        sleep(1);
        
        if (running) {
            printf("Counter: %d\n", counter);
            counter++;
        }
    }
    return NULL;
}

    

int main() {
  sigset_t signal_set;
    int sig;
    pthread_t timer_thread;
    sigemptyset(&signal_set);
    sigaddset(&signal_set, SIGUSR1);
    sigaddset(&signal_set, SIGUSR2);
    pthread_sigmask(SIG_BLOCK, &signal_set, NULL);

    pthread_create(&timer_thread, NULL, timer_handler, NULL);


    printf("PID: %d\n", getpid());



    while (!stop_signal) {
        sigwait(&signal_set, &sig);
        if (sig == SIGUSR1) {
            running = !running;
            if (running) {
                printf("Inkrementierung gestartet\n");
            } else {
                printf("Inkrementierung unterbrochen\n");
            }
        }
        if (sig == SIGUSR2) {
            stop_signal = 1;
        }

    }
    pthread_join(timer_thread, NULL);
   


}