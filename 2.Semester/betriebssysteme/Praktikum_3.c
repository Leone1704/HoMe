#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <pthread.h>
static const char *SHM_NAME = "/praktikum_2_zaehler";

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker (void *arg) {
    int *counter = (int *)arg;
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);
        (*counter)++;
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread finished: Wert=%d, Adresse=%p\n", *counter, (void *)counter);
    return NULL;
}

void child_funktion_aufgabe_1(int *zaehler_ptr, sem_t *semaphore) {
    for (int i = 0; i < 10000; i++) {
        sem_wait(semaphore);
        *zaehler_ptr = *zaehler_ptr + 1;
        sem_post(semaphore);
    }

    printf("Child PID=%d (SHM): Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);
}

int aufgabe_1() {
    shm_unlink(SHM_NAME);
    sem_unlink("/praktikum_2_semaphore");
    sem_t *semaphore = sem_open("/praktikum_2_semaphore", O_CREAT, 0600, 1);
    if (semaphore == SEM_FAILED) {
        perror("sem_open fehlgeschlagen");
        return 1;
    }

    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);
    if (shm_fd == -1) {
        perror("shm_open fehlgeschlagen");
        sem_close(semaphore);
        sem_unlink("/praktikum_2_semaphore");
        return 1;
    }

    if (ftruncate(shm_fd, sizeof(int)) == -1) {
        perror("ftruncate fehlgeschlagen");
        close(shm_fd);
        shm_unlink(SHM_NAME);
        sem_close(semaphore);
        sem_unlink("/praktikum_2_semaphore");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork fehlgeschlagen");
            close(shm_fd);
            shm_unlink(SHM_NAME);
            sem_close(semaphore);
            sem_unlink("/praktikum_2_semaphore");
            return 1;
        }

        if (pid == 0) {
            int child_shm_fd = shm_open(SHM_NAME, O_RDWR, 0600);
            if (child_shm_fd == -1) {
                perror("child shm_open fehlgeschlagen");
                exit(67);
            }

            int *zaehler_ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, child_shm_fd, 0);
            if (zaehler_ptr == MAP_FAILED) {
                perror("child mmap fehlgeschlagen");
                close(child_shm_fd);
                exit(67);
            }

            child_funktion_aufgabe_1(zaehler_ptr, semaphore);

            if (munmap(zaehler_ptr, sizeof(int)) == -1) {
                perror("child munmap fehlgeschlagen");
            }

            sem_close(semaphore);
            close(child_shm_fd);
            exit(67);
        }
    }

    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }

    int *zaehler_ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (zaehler_ptr == MAP_FAILED) {
        perror("parent mmap fehlgeschlagen");
        close(shm_fd);
        shm_unlink(SHM_NAME);
        sem_close(semaphore);
        sem_unlink("/praktikum_2_semaphore");
        return 1;
    }

    printf("Parent PID=%d (SHM): Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);

    if (munmap(zaehler_ptr, sizeof(int)) == -1) {
        perror("parent munmap fehlgeschlagen");
    }

    close(shm_fd);
    shm_unlink(SHM_NAME);
    sem_close(semaphore);
    sem_unlink("/praktikum_2_semaphore");
    return 0;
}


int main() {
    int aufgabe_b_2 = 0;
    int *ptr_aufgabe_b_2 = &aufgabe_b_2;
    
    pthread_t thread[10];
    for (int i = 0; i < 10; i++) {
        if (pthread_create(&thread[i], NULL, worker, ptr_aufgabe_b_2) != 0) {
            perror("pthread_create fehlgeschlagen");
            return 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Main thread finished: Wert=%d, Adresse=%p\n", *ptr_aufgabe_b_2, (void *)ptr_aufgabe_b_2);

    //aufgabe_1();
    pthread_mutex_destroy(&mutex);
    return 0;
}