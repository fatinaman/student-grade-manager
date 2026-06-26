#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student *students, int *count){
    char name[50];
    float marks;
    printf("Enter student's name: ");
    fgets(name, sizeof(name), stdin); //This also takes in the \n character at the and of the string which will cause problems later on
    name[strcspn(name,"\n")] = '\0';
    printf("\nEnter student's marks: ");
    scanf("%f", &marks);
    Student tempStudent;
    tempStudent.id = *count + 1;
    tempStudent.marks = marks;
    strcpy(tempStudent.name, name);
    students[*count] = tempStudent;
    (*count)++;

    printf("Student with ID: %d named %s added", tempStudent.id, tempStudent.name);
} // taking a pointer to the count variable because we need to update it

void displayStudents(Student students[], int count){
    if (count == 0) {
        printf("No students to print !\n");
    } else {
        printf("------------------------------------------\n");
        // Using explicit spacing that perfectly mirrors the loop below
        printf("%-5s  %-20s  %-s\n", "ID", "Name", "Marks");
        printf("------------------------------------------\n");
        for (int i = 0; i < count; i++){
            Student tempStudent = students[i];
            // Matches the header alignment exactly
            printf("%-5d  %-20s  %.2f\n", tempStudent.id, tempStudent.name, tempStudent.marks);
        }
        printf("------------------------------------------\n");
    }
}

void searchStudent(Student students[], int count, int id){
    for(int i = 0; i < count; i++){
        if (students[i].id == id){ // Using the actual ID property is safer than i+1
            printf("------------------------------------------\n");
            printf("%-5s  %-20s  %-s\n", "ID", "Name", "Marks");
            printf("------------------------------------------\n");
            Student tempStudent = students[i];
            printf("%-5d  %-20s  %.2f\n", tempStudent.id, tempStudent.name, tempStudent.marks);
            printf("------------------------------------------\n");
            return;
        }
    }
    printf("No student with that id\n");
}