#include <stdio.h>

int main() {
    
    // 1. Declare an integer variable and initialize it with a value.
    int a = 7; 
   
    // 2. Declare a pointer variable that points to the integer.
    int* p = &a; 
    
    // 3. Print the address of the integer variable using both the variable and the pointer.
    printf("%d\n", &a);
    printf("%d\n", p); 
    
    // 4. Modify the value of the integer using the pointer and print the new value.
    *p = 10;
    printf("%d\n", a); 
    
    return 0;
}