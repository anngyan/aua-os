#include <stdio.h>

int main() {
    // 1. Declare an integer variable and a pointer to that variable.
    int a = 7;
    int* p = &a;
    
    // 2. Declare a pointer to the pointer and initialize it.
    int** pp = &p;

    // 3. Print the value of the integer using both the pointer and the double-pointer.
    printf("Pointer: a = %d\n", *p);
    printf("Double-pointer: a = %d\n", **pp);
    
    return 0;
}