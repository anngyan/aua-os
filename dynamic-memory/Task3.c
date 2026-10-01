#include <stdio.h>
#include <stdlib.h>

// Helper function to clear leftover invalid characters from input buffer 
void clear_input_buffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
}

int main() {
    int* arr = NULL; 
    int* temp = NULL; 
    // 1. Dynamically allocates memory for an array of 10 integers using malloc()
    arr = (int*)malloc(10 * sizeof(int)); 

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // 2. Lets the user input 10 values 
    printf("Enter 10 Integers: \n"); 
    for (int i = 0; i < 10; i++) {
        while (1) { 
            printf("Enter value %d: ", i + 1); 
            if (scanf("%d", &arr[i]) == 1) { 
                break; // Valid integer input 
            } 
            printf("Invalid input. Please enter an integer.\n"); 
            clear_input_buffer(); 
        } 
    } 
    // Display the initial 10 elements 
    printf("\nInitial 10 Values: "); 
    for (int i = 0; i < 10; i++) { 
        printf("%d ", arr[i]); 
    } 
    // 3. Resize the array using realloc() to hold only 5 integers (shrink memory) 
    temp = (int*)realloc(arr, 5 * sizeof(int)); 
    
    arr = temp; // Update array pointer 
    
    // 4. Print the first 5 values of the resized array 
    printf("\nArray after resizing: "); 
    for (int i = 0; i < 5; i++) { 
        printf("%d ", arr[i]);
    } 
    printf("\n");
    
    // 5. Free memory after use 
    free(arr); 
    
    return 0;
}