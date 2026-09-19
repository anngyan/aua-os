#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// First function 
void first(void) { 
    printf("Function 1\n");
}
// Second function 
void second(void) { 
    printf("Function 2\n"); 
}

int main() {
    atexit(first);
    atexit(second);

    return 0;

}