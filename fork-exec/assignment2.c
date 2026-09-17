#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;
    
    p1 = fork(); 
    if (p1 < 0) { 
        perror("fork 1 failed"); 
        exit(EXIT_FAILURE); 
    } 
    else if (p1 == 0) { 
        // Child process execution 
        printf("Child process running 'ls' using execl()\n\n"); 

        // execl(path, arg0, arg1, ..., NULL) 
        execl("/bin/ls", "ls", NULL);

        // In case execl() encounters an error 
        perror("execl 1 failed"); 
        exit(EXIT_FAILURE); 
    }
    else {
        waitpid(p1, NULL, 0);
    } 

    printf("\n");
    
    p2 = fork(); 
    if (p2 < 0) { 
        perror("fork 2 failed"); 
        exit(EXIT_FAILURE); 
    } 
    else if (p2 == 0) { 
        // Child process execution 
        printf("Child process running 'date' using execl()\n\n"); 
        
        // execl(path, arg0, arg1, ..., NULL) 
        execl("/bin/date", "date", NULL);

        // In case execl() encounters an error 
        perror("execl 2 failed"); 
        exit(EXIT_FAILURE); 
    } 
    else {
        waitpid(p2, NULL, 0);
    }

    wait(NULL);
    wait(NULL);
    
    printf("\nParent process done.\n");
    
    return 0;
}