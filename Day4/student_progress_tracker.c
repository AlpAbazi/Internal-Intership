#include <stdio.h>

/* Maximum number of student records we can store */
#define MAX_STUDENTS 10
#define NAME_SIZE 50

/* Enum for the student's progress status */
enum Status {
    LOW,
    MEDIUM,
    HIGH
};

/* Structure that stores one student record */
struct Student {
    int id;
    char name[NAME_SIZE];
    double score;
    enum Status status;
};

/* This function uses a pointer to update the status value */
void assignStatus(double score, enum Status *status) {
    if (score < 50) {
        *status = LOW;
    } else if (score < 80) {
        *status = MEDIUM;
    } else {
        *status = HIGH;
    }
}

/* Convert enum status to text so it is easy to print */
const char *getStatusText(enum Status status) {
    switch (status) {
        case LOW:
            return "LOW";
        case MEDIUM:
            return "MEDIUM";
        case HIGH:
            return "HIGH";
        default:
            return "UNKNOWN";
    }
}

/* Add one new student to the array */
void addStudent(struct Student students[], int *studentCount) {
    struct Student newStudent;

    if (*studentCount >= MAX_STUDENTS) {
        printf("\nThe student list is full. You cannot add more students.\n");
        return;
    }

    printf("\n--- Add Student Record ---\n");

    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);

    printf("Enter student name: ");
    scanf(" %49[^\n]", newStudent.name);

    printf("Enter student score (0 - 100): ");
    scanf("%lf", &newStudent.score);

    /* Validate that the score is between 0 and 100 */
    if (newStudent.score < 0 || newStudent.score > 100) {
        printf("\nInvalid score. The score must be between 0 and 100.\n");
        return;
    }

    /* Assign status using a pointer */
    assignStatus(newStudent.score, &newStudent.status);

    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("\nStudent record added successfully.\n");
}

/* Display all stored student records */
void showStudents(struct Student students[], int studentCount) {
    int i;

    printf("\n--- Student Records ---\n");

    if (studentCount == 0) {
        printf("No student records have been added yet.\n");
        return;
    }

    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Score", "Status");
    printf("------------------------------------------------\n");

    for (i = 0; i < studentCount; i++) {
        printf("%-5d %-20s %-10.2f %-10s\n",
               students[i].id,
               students[i].name,
               students[i].score,
               getStatusText(students[i].status));
    }
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    int running = 1;

    /* The menu keeps running until the user chooses Exit */
    while (running) {
        printf("\n==============================\n");
        printf(" Student Progress Tracker\n");
        printf("==============================\n");
        printf("1. Add student record\n");
        printf("2. Show all student records\n");
        printf("3. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                showStudents(students, studentCount);
                break;
            case 3:
                running = 0;
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please choose 1, 2, or 3.\n");
        }
    }

    return 0;
}
