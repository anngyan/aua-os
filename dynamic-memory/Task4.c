#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

// Helper function to remove the trailing newline added by fgets() 
void remove_newline(char* str) { 
    size_t len = strlen(str); 
    if (len > 0 && str[len - 1] == '\n') { 
        str[len - 1] = '\0'; 
    } 
} 

int main() { 
    int initial_count = 3; 
    int total_count = 5; 
    // 1. Dynamically allocates memory for an array of 3 strings (char pointers) using malloc()
    char** arr = (char**)malloc(initial_count * sizeof(char*)); 
    if (arr == NULL) { 
        printf("Pointer array allocation failed.\n");
        return 1; 
    } 
    
    // 2. Dynamically allocates memory for each of the initial 3 strings (50 chars each) 
    for (int i = 0; i < initial_count; i++) { 
        arr[i] = (char*)malloc(MAX_LEN * sizeof(char)); 
        if (arr[i] == NULL) { 
            printf("Allocation failed for string %d.\n", i + 1); 
            for (int j = 0; j < i; j++) 
            free(arr[j]); 
            free(arr); 
            return 1; 
        } 
    } 
    // 3. Lets the user input 3 strings 
    printf("Enter %d Strings: \n", initial_count); 
    for (int i = 0; i < initial_count; i++) { 
        printf("Enter string %d: ", i + 1); 
        if (fgets(arr[i], MAX_LEN, stdin) != NULL) { 
            remove_newline(arr[i]); 
        } 
    } 
    // 4. Prints the strings 
    printf("\nThe First %d Strings: ", initial_count); 
    for (int i = 0; i < initial_count; i++) { 
        printf("%s ", arr[i]); 
    }
    printf("\n"); 
    // 5. Uses realloc() to allow the user to input 2 more strings (resize the array)
    char** temp = (char**)realloc(arr, total_count * sizeof(char*)); 
    if (temp == NULL) { 
        printf("Reallocation failed.\n"); 
        for (int i = 0; i < initial_count; i++) 
        free(arr[i]); 
        free(arr); 
        return 1; 
    } 
    arr = temp; 
    // Allocates memory for the 2 new strings (50 chars each) 
    for (int i = initial_count; i < total_count; i++) { 
        arr[i] = (char*)malloc(MAX_LEN * sizeof(char)); 
        if (arr[i] == NULL) { 
            printf("Allocation failed for string %d.\n", i + 1); 
            for (int j = 0; j < i; j++) 
            free(arr[j]); 
            free(arr); 
            return 1; 
        } 
    } 
    // Lets the user input the 2 additional strings 
    printf("\nEnter 2 Additional Strings: \n"); 
    for (int i = initial_count; i < total_count; i++) { 
        printf("Enter string %d: ", i + 1); 
        if (fgets(arr[i], MAX_LEN, stdin) != NULL) { 
            remove_newline(arr[i]); 
        } 
    } 
    // 6. Prints all 5 strings 
    printf("\nAll %d Strings: ", total_count); 
    for (int i = 0; i < total_count; i++) { 
        printf("%s ", arr[i]);
    } 
    // 7. Frees all allocated memory 
    for (int i = 0; i < total_count; i++) { 
        free(arr[i]); // Free each individual string buffer 
    }
    printf("\n"); 
    free(arr);  
    return 0; 
}