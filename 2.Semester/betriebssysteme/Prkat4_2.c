#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>

volatile sig_atomic_t running = 0;
int counter = 0;
volatile sig_atomic_t stop_signal = 0;


void on_signal1(int signum) {
    if (signum == SIGUSR1) {
        running = !running;
        if (running) {
            printf("Inkrementierung gestartet\n");
            alarm(1); 
        } else {
            printf("Inkrementierung unterbrochen\n");
            alarm(0); 
        }
    }
    
}

void on_signal2(int signum) {
    if (signum == SIGUSR2) {
        stop_signal = 1;
    }
}

void on_alarm(int signum) {
    if (signum == SIGALRM) {
        if (running) {
            counter++;
            printf("Counter: %d\n", counter);
            fflush(stdout);
        }
        alarm(1);
    }
}

int main() {
    printf("programm gestartet\n");

    
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, on_signal1);
    signal(SIGUSR2, on_signal2);
    signal(SIGALRM, on_alarm);

    alarm(1); 

    while (!stop_signal) {
        pause(); 
        }

    return 0;
    }

    


