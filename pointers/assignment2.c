#include <stdio.h>

int main() {

    // 1. Declare an array of integers and initialize it with 5 values.
    int a[5] = {1, 2, 3, 4, 5}; 
    
    // 2. Use a pointer to traverse the array and print each element.
    printf("Elements: ");
    int* p = &a[0];
    for (int i = 0; i < 5; ++i) {
        printf("%d ", *(p + i));
    }

    // 3. Modify the values of the array using pointer arithmetic.
    // 4. Print the modified array using both the pointer and the array name.
    printf("\nModified: ");
    for (int i = 0; i < 5; ++i) {
        *(p + i) += 1;
        printf("%d ", *(p + i));
    }
    printf("\n");
    for(int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;

}