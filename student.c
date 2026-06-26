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
    if (count ==0) {
        printf("No students to print !");
    }else{
        printf("------------------------------------------\n");
        printf("ID   Name                            Marks\n");
        printf("------------------------------------------\n");
        for (int i = 0; i < count; i++){
            Student tempStudent = students[i];
            printf("%-5d  %-20s  %.2f\n", tempStudent.id, tempStudent.name, tempStudent.marks);
    }
    }
}

void searchStudent(Student students[], int count, int id){
    // implement a function to search student based on id
    // given that id = count + 1 at the time of inserting
    for(int i = 0; i < count; i++){
        if (i+1 == id){
            printf("------------------------------------------\n");
            printf("ID   Name                            Marks\n");
            printf("------------------------------------------\n");
            Student tempStudent = students[i];
            printf("%d  %s  %f\n", tempStudent.id, tempStudent.name, tempStudent.marks);
            return;
        }
    }
    printf("No student with that id");
}