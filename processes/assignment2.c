#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1, pid2;
    int status1, status2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork 1 failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid1 == 0) {
        printf("[Child 1] PID: %d | Exiting with status code 1...\n", getpid());
        exit(1); // Return exit status 1
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("fork 2 failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid2 == 0) {
        printf("[Child 2] PID: %d | Exiting with status code 2...\n", getpid());
        exit(2); // Return exit status 2
    }

    // Use waitpid() to wait specifically for Child 2 to finish first
    printf("[Parent] Waiting for Child 2 (PID: %d) to finish first via waitpid()...\n", pid2);
    pid_t waited_pid = waitpid(pid2, &status2, 0);

    if (waited_pid > 0) {
        // Check if Child 2 exited normally
        if (WIFEXITED(status2)) {
            printf("[Parent] Child 2 (PID: %d) finished. Exit status: %d\n\n", 
                   waited_pid, WEXITSTATUS(status2));
        }
    }

    // 4. Use wait() to wait for any remaining child process (Child 1)
    printf("[Parent] Waiting for remaining child process to finish via wait()...\n");
    waited_pid = wait(&status1);

    if (waited_pid > 0) {
        // Check if Child 1 exited normally
        if (WIFEXITED(status1)) {
            printf("[Parent] Child 1 (PID: %d) finished. Exit status: %d\n\n", 
                   waited_pid, WEXITSTATUS(status1));
        }
    }

    printf("[Parent] All children collected. Parent process done.\n");
    return 0;
}