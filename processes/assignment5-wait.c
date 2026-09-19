#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        // Parent Process: Reaps child using wait() 
        int status; 
        printf("[Parent] PID: %d — Waiting for Child PID: %d...\n", getpid(), pid); 
        pid_t child_pid = wait(&status); 
        // Collects child exit status and cleans up PID 
        if (child_pid > 0 && WIFEXITED(status)) {
            printf("[Parent] Successfully collected Child PID: %d (Exit Status: %d)\n", child_pid, WEXITSTATUS(status)); 
        }

        printf("[Parent] Sleeping for 30 seconds...\n"); 
        sleep(10); 
        printf("[Parent] Exiting.\n"); 
    }
    return 0;
}