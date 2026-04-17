#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} StudentStatus;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int progress;
    StudentStatus status;
} StudentRecord;

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

const char* getStatusText(StudentStatus status) {
    switch (status) {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

void printHeader(void) {
    printf("\n========================================\n");
    printf("      STUDENT PROGRESS TRACKER\n");
    printf("========================================\n");
}

void showMenu(void) {
    printf("\nMenu:\n");
    printf("1. Add student record\n");
    printf("2. Show all records\n");
    printf("3. Search student by ID\n");
    printf("4. Show summary\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int findStudentById(StudentRecord students[], int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

int addStudentRecord(StudentRecord students[], int *count) {
    StudentRecord newStudent;
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("\nTracker is full. Maximum %d students allowed.\n", MAX_STUDENTS);
        return 0;
    }

    printf("\nEnter student ID: ");
    if (scanf("%d", &newStudent.id) != 1 || newStudent.id <= 0) {
        printf("Invalid ID. Please enter a positive number.\n");
        clearInputBuffer();
        return 0;
    }

    if (findStudentById(students, *count, newStudent.id) != -1) {
        printf("A student with this ID already exists.\n");
        return 0;
    }

    clearInputBuffer();

    printf("Enter student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    if (strlen(newStudent.name) == 0) {
        printf("Student name cannot be empty.\n");
        return 0;
    }

    printf("Enter progress (0-100): ");
    if (scanf("%d", &newStudent.progress) != 1 || newStudent.progress < 0 || newStudent.progress > 100) {
        printf("Invalid progress. Please enter a number from 0 to 100.\n");
        clearInputBuffer();
        return 0;
    }

    printf("Select status:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Choice: ");
    if (scanf("%d", &statusChoice) != 1 || statusChoice < 1 || statusChoice > 3) {
        printf("Invalid status choice.\n");
        clearInputBuffer();
        return 0;
    }

    newStudent.status = (StudentStatus)statusChoice;
    students[*count] = newStudent;
    (*count)++;

    printf("\nStudent record added successfully.\n");
    return 1;
}

void showAllRecords(StudentRecord students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("%-10s %-25s %-15s %-15s\n", "ID", "Name", "Progress", "Status");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-10d %-25s %-15d %-15s\n",
               students[i].id,
               students[i].name,
               students[i].progress,
               getStatusText(students[i].status));
    }

    printf("--------------------------------------------------------------------------------\n");
}

void searchStudent(StudentRecord students[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    printf("\nEnter student ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentById(students, count, id);

    if (index == -1) {
        printf("Student with ID %d was not found.\n", id);
    } else {
        printf("\nStudent Found:\n");
        printf("ID: %d\n", students[index].id);
        printf("Name: %s\n", students[index].name);
        printf("Progress: %d%%\n", students[index].progress);
        printf("Status: %s\n", getStatusText(students[index].status));
    }
}

void showSummary(StudentRecord students[], int count) {
    int i;
    int completed = 0;
    int inProgress = 0;
    int notStarted = 0;
    int totalProgress = 0;
    float average = 0.0f;

    if (count == 0) {
        printf("\nNo records available for summary.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        totalProgress += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        } else if (students[i].status == IN_PROGRESS) {
            inProgress++;
        } else if (students[i].status == NOT_STARTED) {
            notStarted++;
        }
    }

    average = (float) totalProgress / count;

    printf("\nSummary:\n");
    printf("Total students   : %d\n", count);
    printf("Not Started      : %d\n", notStarted);
    printf("In Progress      : %d\n", inProgress);
    printf("Completed        : %d\n", completed);
    printf("Average Progress : %.2f%%\n", average);
}

int main(void) {
    StudentRecord students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    int running = 1;

    while (running) {
        printHeader();
        showMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudentRecord(students, &studentCount);
                break;
            case 2:
                showAllRecords(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                showSummary(students, studentCount);
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                running = 0;
                break;
            default:
                printf("\nInvalid option. Please choose from 1 to 5.\n");
        }
    }

    return 0;
}

