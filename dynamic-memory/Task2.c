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
    double sum = 0.0; 
    double average; 
    
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
    // 2. Dynamically allocates memory for an array of n integers using calloc()
    arr = (int*)calloc(n, sizeof(int)); 
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // 3. Prints the initial values (all zeros) 
    printf("\nInitial Array Values (Zero-Initialized by calloc): "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]);
    } 
    // 4. Lets the user input n integers 
    printf("\nEnter %d Integer(s)\n", n); 
    for (int i = 0; i < n; i++) { 
        while (1) { 
            printf("Enter element %d: ", i + 1); 
            if (scanf("%d", &arr[i]) == 1) { 
                break; // Valid integer input 
            } 
            printf("Invalid number. Try again.\n"); 
            clear_input_buffer();
        } 
        sum += arr[i]; 
    } 
    // 5. Calculates the average of the array 
    average = sum / n;

    // 6. Print the updated array and the average 
    printf("\nUpdated Array Values: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\nTotal Sum: %.2f\n", sum); 
    printf("Average: %.2f\n", average); 
    
    // 7. Frees the memory after use 
    free(arr); 
    return 0; 
}
