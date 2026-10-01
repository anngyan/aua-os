#include <stdio.h>
#include <stdlib.h>

// Helper function to clear leftover invalid characters from input buffer 
void clear_input_buffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
} 

int main() {
    
    int n;
    int* arr;
    int sum = 0;

    // 1. Asks the user for a number n
    while (1) { 
        printf("Enter the number of integers (n > 0): "); 
        if (scanf("%d", &n) != 1 || n <= 0) { 
            printf("Invalid input. Please enter a positive integer.\n");
            clear_input_buffer();
        } 
        else { 
            break; // Valid array size received 
        } 
    }

    // 2. Dynamically allocates memory for an array of n integers using malloc()
    arr = (int*)malloc(n * sizeof(int)); 
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // 3. Lets the user input n integers
    printf("Enter %d integer(s):\n", n); 
    for (int i = 0; i < n; i++) { 
        while (1) { 
            printf("Enter element %d: ", i + 1); 
            if (scanf("%d", &arr[i]) == 1) { 
                break; // Valid integer input 
            } 
            printf("Invalid number. Try again.\n"); 
            clear_input_buffer();
        } 
    } 
    // 4. Calculates and prints the sum of the integers
    for (int i = 0; i < n; i++) { 
        sum += arr[i]; 
    } 
    printf("\nThe sum of the %d integers is: %d\n", n, sum); 
    // 5. Frees the memory after use 
    free(arr); 

    return 0;
}