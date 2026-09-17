#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 
    if (pid < 0) { 
        perror("fork failed"); 
        exit(EXIT_FAILURE); 
    } 
    else if (pid == 0) { 
        
        // execl(path, arg0, arg1, ..., NULL) 
        execl("/bin/grep", "grep", "pain", "test.txt", NULL);

        // In case execl() encounters an error 
        perror("execl failed"); 
        exit(EXIT_FAILURE); 
    } 
    else { 
        // Parent process waits for child to finish 
        wait(NULL); 
        printf("\nParent process done.\n"); 
    } 
    
    return 0;
}