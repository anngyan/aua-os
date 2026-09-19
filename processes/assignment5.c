#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
    pid_t pid = fork(); 
    if (pid < 0) { 
        perror("fork failed"); 
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) { 
        // Child Process: Exits immediately 
        printf("[Child] PID: %d — Exiting now...\n", getpid()); 
        exit(0); 
    } 
    else { 
        // Parent Process: Sleeps without calling wait(), creating a zombie 
        printf("[Parent] PID: %d — Created Child PID: %d\n", getpid(), pid); 
        printf("[Parent] Sleeping for 30 seconds without waiting...\n"); 
        sleep(30); 
        printf("[Parent] Woke up and exiting.\n"); 
    }
    return 0;
}