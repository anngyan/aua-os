#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2, p3;

    //First fork call
    p1 = fork();
    if (p1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    // Second fork call
    p2 = fork();
    if (p2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    // Third fork call
    p3 = fork();
    if (p3 < 0) {
        perror("Third fork failed");
        exit(1);
    }

    // Information for every process created
    printf("Process PID: %d | Parent PID (PPID): %d\n", getpid(), getppid());


    return 0;
}