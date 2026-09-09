#include <stdio.h>

int main() {
    // 1. Declare a string as a character array: char str[] = "Hello";.
    char str[] = "Hello";

    // 2. Declare a pointer to the first character of the string.
    char* p = &str[0];

    // 3. Print the string using the pointer and a loop (without using str[i]).
    for(int i = 0; i < 5; ++i) {
        printf("%c", *(p + i));
    }
    printf("\n");
    
    return 0;
}