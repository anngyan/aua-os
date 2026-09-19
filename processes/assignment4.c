#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2; 
    int status; 
 
    // Create First Child 
    pid1 = fork(); 
    if (pid1 < 0) { 
        perror("First fork failed"); 
        exit(EXIT_FAILURE); 
    } 
    else if (pid1 == 0) { 
        // Child 1 execution
        printf("[Child 1 - PID %d] Executing... exiting with code 0\n", getpid()); 
        exit(0); 
    } 
    // Create Second Child 
    pid2 = fork(); 
    if (pid2 < 0) { 
        perror("Second fork failed"); 
        exit(EXIT_FAILURE); 
    } 
    else if (pid2 == 0) { 
        // Child 2 execution 
        printf("[Child 2 - PID %d] Executing... exiting with code 5\n", getpid()); 
        exit(5);
    } 
    // Parent Process: Wait for Child 1 specifically using waitpid() 
    if (waitpid(pid1, &status, 0) > 0) { 
        if (WIFEXITED(status)) { 
            int exit_code = WEXITSTATUS(status); 
            printf("[Parent] Child 1 (PID %d) terminated with exit code %d. \n", pid1, exit_code); 
            if (exit_code == 0) { 
                printf("Status: Exited normally (Success).\n"); 
            } 
            else { 
                printf("Status: Exited with an error.\n"); 
            }
        }  
    } 
    // Parent Process: Wait for Child 2 specifically using waitpid() 
    if (waitpid(pid2, &status, 0) > 0) { 
        if (WIFEXITED(status)) { 
            int exit_code = WEXITSTATUS(status); 
            printf("[Parent] Child 2 (PID %d) terminated with exit code %d.\n", pid2, exit_code); 
            if (exit_code == 0) { 
                printf("Status: Exited normally (Success).\n"); 
            } 
            else { 
                printf("Status: Exited with an error.\n"); 
            } 
        } 
    } 
    return 0;
}