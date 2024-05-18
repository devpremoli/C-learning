#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

void addStudent(Student students[], int *count);
float calculateAverage(Student students[], int count);
float findHighestGrade(Student students[], int count);
float findLowestGrade(Student students[], int count);
void displayStudents(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("Student Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Calculate Average Grade\n");
        printf("3. Find Highest Grade\n");
        printf("4. Find Lowest Grade\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                printf("Average Grade: %.2f\n", calculateAverage(students, count));
                break;
            case 3:
                printf("Highest Grade: %.2f\n", findHighestGrade(students, count));
                break;
            case 4:
                printf("Lowest Grade: %.2f\n", findLowestGrade(students, count));
                break;
            case 5:
                displayStudents(students, count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter student grade: ");
    scanf("%f", &students[*count].grade);
    (*count)++;
}

float calculateAverage(Student students[], int count) {
    if (count == 0) return 0.0;

    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    return sum / count;
}

float findHighestGrade(Student students[], int count) {
    if (count == 0) return 0.0;

    float highest = students[0].grade;
    for (int i = 1; i < count; i++) {
        if (students[i].grade > highest) {
            highest = students[i].grade;
        }
    }
    return highest;
}

float findLowestGrade(Student students[], int count) {
    if (count == 0) return 0.0;

    float lowest = students[0].grade;
    for (int i = 1; i < count; i++) {
        if (students[i].grade < lowest) {
            lowest = students[i].grade;
        }
    }
    return lowest;
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Grade: %.2f\n", students[i].name, students[i].grade);
    }
}
