#include <stdio.h>
#include <stdlib.h>

// Helper function to clear leftover invalid characters from input buffer 
void clear_input_buffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
}

int main() {
    int num_students; 
    float* grades = NULL; 
    // 1. Ask the user for the number of students
    while (1) { 
        printf("Enter the number of students in the class: "); 
        if (scanf("%d", &num_students) != 1 || num_students <= 0) { 
            printf("Invalid input. Please enter a valid positive integer.\n\n"); 
            clear_input_buffer(); 
        } 
        else { 
            break; // Valid number received 
        } 
    } 
    // 2. Dynamically allocates memory for the student grades using malloc() 
    grades = (float*)malloc(num_students * sizeof(float)); 
    if (grades == NULL) {
        printf("Memory allocation failed.\n"); 
        return 1; 
    } 
    // 3. Lets the user input the grade for each student 
    printf("\nEnter Grades for %d Student(s): \n", num_students); 
    for (int i = 0; i < num_students; i++) { 
        while (1) { 
            printf("Enter grade for Student %d: ", i + 1); 
            if (scanf("%f", &grades[i]) == 1 && grades[i] >= 0.0f) { 
                break; // Valid non-negative grade entered 
            } 
            printf("Invalid grade. Please enter a valid non-negative number.\n");
            clear_input_buffer(); 
        } 
    } 
    // 4. Calculate the highest and lowest grades 
    float highest = grades[0]; 
    float lowest = grades[0]; 
    for (int i = 1; i < num_students; i++) { 
        if (grades[i] > highest) { 
            highest = grades[i]; 
        } 
        if (grades[i] < lowest) { 
            lowest = grades[i]; 
        } 
    } 
    // Prints the grades 
    printf("Highest Grade: %.2f\n", highest); 
    printf("Lowest Grade: %.2f\n", lowest); 
    
    // 5. Frees the memory after use
    free(grades); 
    
    return 0;
}