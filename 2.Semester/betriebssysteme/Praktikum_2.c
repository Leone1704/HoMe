#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
static const char *SHM_NAME = "/praktikum_2_zaehler";

int aufgabe_1(){
    pid_t pid = fork();

    if (pid == -1) {
        perror("fehler entstanden beim erstellen des childs");
        return 1;

    }

    if (pid == 0) {
        printf("Ich bin das Child mit der PID=%d und habe den Parent mit PID=%d\n", getpid(), getppid());
        sleep(5);
        exit(67);
    } else {
        printf("Ich bin der Parent mit der PID=%d und habe das Child mit PID=%d\n", getpid(), pid);
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }   else {
            printf("Child wurde terminiert haha\n");
        }

    }

    return 0;
}

void child_funktion_aufgabe_2(int *zaehler_ptr) {
    for (int i = 0; i < 10000; i++) {
        *zaehler_ptr = *zaehler_ptr + 1;
    }

    printf("Child PID=%d: Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);
}

int aufgabe_2() {
    int zaehler = 0;
    int *zaehler_ptr = &zaehler; 

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork fehlgeschlagen");
            return 1;
        }

        if (pid == 0) {
            child_funktion_aufgabe_2(zaehler_ptr);
            exit(67);
        }
    }

    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }

    printf("Parent PID=%d: Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);
    return 0;
}

void child_funktion_aufgabe_3(int *zaehler_ptr) {
    for (int i = 0; i < 10000; i++) {
        *zaehler_ptr = *zaehler_ptr + 1;
    }

    printf("Child PID=%d (SHM): Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);
}

int aufgabe_3() {
    shm_unlink(SHM_NAME);

    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);
    if (shm_fd == -1) {
        perror("shm_open fehlgeschlagen");
        return 1;
    }

    if (ftruncate(shm_fd, sizeof(int)) == -1) {
        perror("ftruncate fehlgeschlagen");
        close(shm_fd);
        shm_unlink(SHM_NAME);
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork fehlgeschlagen");
            close(shm_fd);
            shm_unlink(SHM_NAME);
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

            child_funktion_aufgabe_3(zaehler_ptr);

            if (munmap(zaehler_ptr, sizeof(int)) == -1) {
                perror("child munmap fehlgeschlagen");
            }

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
        return 1;
    }

    printf("Parent PID=%d (SHM): Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);

    if (munmap(zaehler_ptr, sizeof(int)) == -1) {
        perror("parent munmap fehlgeschlagen");
    }

    close(shm_fd);
    shm_unlink(SHM_NAME);
    return 0;
}

int main() {
    aufgabe_3();
    return 0;
}