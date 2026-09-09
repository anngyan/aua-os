#include <stdio.h>

// 1. Write a function swap(int *a, int *b) that swaps two integer values using pointers.
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int a = 5, b = 7;

    // 3. Print the values of the integers before and after the swap.
    printf("Before swap:\na = %d, b = %d\n", a, b);

    // 2. Write a function swap(int *a, int *b) that swaps two integer values using pointers.
    swap(&a, &b);

    // 3. Print the values of the integers before and after the swap.
    printf("After swap:\na = %d, b = %d\n", a, b);

    return 0;
}