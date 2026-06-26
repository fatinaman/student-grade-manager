#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "statistics.h"

#define MAX_STUDENTS 100

int main() {
    // Array to hold students and a counter to track how many exist
    Student students[MAX_STUDENTS];
    int count = 0;
    
    int choice;
    int searchId;

    printf("=== Welcome to the Student Management System ===\n");

    while (1) {
        // 1. Display the Menu
        printf("\n================ MAIN MENU ================\n");
        printf("1. Add a Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Show Class Statistics (Highest & Average)\n");
        printf("5. Exit\n");
        printf("===========================================\n");
        printf("Enter your choice (1-5): ");
        
        // Read user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        // Crucial: Clear the trailing '\n' from the buffer so it doesn't mess up fgets later!
        while (getchar() != '\n'); 

        printf("\n");

        // 2. Handle Menu Logic
        switch (choice) {
            case 1:
                printf("--- Adding a New Student ---\n");
                addStudent(students, &count);
                break;

            case 2:
                printf("--- Displaying All Students ---\n");
                displayStudents(students,count);
                break;

            case 3:
                printf("--- Search Student by ID ---\n");
                printf("Enter the Student ID to search for: ");
                scanf("%d", &searchId);
                while (getchar() != '\n'); // Clear buffer
                
                searchStudent(students,count, searchId);
                break;

            case 4:
                printf("--- Class Statistics ---\n");

                float highest = getHighest(students,count);
                float average = getAverage(students,count);
                printf("Highest Marks: %.2f\n", highest);
                printf("Average Marks: %.2f\n", average);
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    }

    return 0;
}