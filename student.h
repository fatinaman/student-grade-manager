#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    int id;
    char name[50];
    float marks;
} Student;

// creating a Student struct with type of Student

// function declarations

void addStudent(Student *students, int *count); // taking a pointer to the count variable because we need to update it

void displayStudents(Student students[], int count);

void searchStudent(Student students[], int count, int id);

#endif