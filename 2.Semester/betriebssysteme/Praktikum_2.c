#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/mman.h>



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
    int *zaehler_ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (zaehler_ptr == MAP_FAILED) {
        perror("mmap fehlgeschlagen");
        return 1;
    }

    *zaehler_ptr = 0;

    for (int i = 0; i < 10; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork fehlgeschlagen");
            munmap(zaehler_ptr, sizeof(int));
            return 1;
        }

        if (pid == 0) {
            child_funktion_aufgabe_3(zaehler_ptr);
            munmap(zaehler_ptr, sizeof(int));
            exit(67);
        }
    }

    for (int i = 0; i < 10; i++) {
        wait(NULL);
    }

    printf("Parent PID=%d (SHM): Wert=%d, Adresse=%p\n", getpid(), *zaehler_ptr, (void *)zaehler_ptr);
    munmap(zaehler_ptr, sizeof(int));
    return 0;
}

int main() {
    aufgabe_3();
    return 0;
}