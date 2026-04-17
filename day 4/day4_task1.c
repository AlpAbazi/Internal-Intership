task 1
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10
#define NAME_LENGTH 50

typedef enum {
    STATUS_NOT_STARTED = 1,
    STATUS_IN_PROGRESS,
    STATUS_COMPLETED
} StudentStatus;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int progress;
    StudentStatus status;
} StudentRecord;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

const char* statusToString(StudentStatus status) {
    switch (status) {
        case STATUS_NOT_STARTED:
            return "Not Started";
        case STATUS_IN_PROGRESS:
            return "In Progress";
        case STATUS_COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}

int readInteger(const char* message, int* value) {
    printf("%s", message);
    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    return 1;
}

int findStudentById(StudentRecord records[], int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

int chooseStatus(StudentStatus* status) {
    int choice;

    printf("Choose student status:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");

    if (!readInteger("Enter status choice: ", &choice)) {
        printf("Invalid input. Please enter a number.\n");
        return 0;
    }

    switch (choice) {
        case 1:
            *status = STATUS_NOT_STARTED;
            return 1;
        case 2:
            *status = STATUS_IN_PROGRESS;
            return 1;
        case 3:
            *status = STATUS_COMPLETED;
            return 1;
        default:
            printf("Invalid status choice. Please choose 1, 2, or 3.\n");
            return 0;
    }
}

void addRecord(StudentRecord records[], int* count) {
    StudentRecord newRecord;

    if (*count >= MAX_RECORDS) {
        printf("Tracker is full. Maximum %d records allowed.\n", MAX_RECORDS);
        return;
    }

    if (!readInteger("Enter student ID: ", &newRecord.id) || newRecord.id <= 0) {
        printf("Invalid ID. Please enter a positive whole number.\n");
        return;
    }

    if (findStudentById(records, *count, newRecord.id) != -1) {
        printf("A record with this ID already exists.\n");
        return;
    }

    clearInputBuffer();
    printf("Enter student name: ");
    fgets(newRecord.name, sizeof(newRecord.name), stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = '\0';

    if (strlen(newRecord.name) == 0) {
        printf("Student name cannot be empty.\n");
        return;
    }

    if (!readInteger("Enter progress (0-100): ", &newRecord.progress) ||
        newRecord.progress < 0 || newRecord.progress > 100) {
        printf("Invalid progress. Please enter a number from 0 to 100.\n");
        return;
    }

    if (!chooseStatus(&newRecord.status)) {
        return;
    }

    records[*count] = newRecord;
    (*count)++;

    printf("Record added successfully.\n");
}

void showRecords(StudentRecord records[], int count) {
    int i;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-15s\n", "ID", "Name", "Progress", "Status");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d %-15s\n",
               records[i].id,
               records[i].name,
               records[i].progress,
               statusToString(records[i].status));
    }
}

void showReport(StudentRecord records[], int count) {
    int i;
    int completedCount = 0;
    int totalProgress = 0;
    int highestProgress;
    int lowestProgress;
    float averageProgress;

    if (count == 0) {
        printf("\n===== REPORT =====\n");
        printf("No records available for analysis.\n");
        return;
    }

    highestProgress = records[0].progress;
    lowestProgress = records[0].progress;

    for (i = 0; i < count; i++) {
        totalProgress += records[i].progress;

        if (records[i].status == STATUS_COMPLETED) {
            completedCount++;
        }

        if (records[i].progress > highestProgress) {
            highestProgress = records[i].progress;
        } else if (records[i].progress < lowestProgress) {
            lowestProgress = records[i].progress;
        }
    }

    averageProgress = (float)totalProgress / count;

    printf("\n===== REPORT =====\n");
    printf("Total records       : %d\n", count);
    printf("Completed students  : %d\n", completedCount);
    printf("Average progress    : %.2f%%\n", averageProgress);
    printf("Highest progress    : %d%%\n", highestProgress);
    printf("Lowest progress     : %d%%\n", lowestProgress);

    if (averageProgress >= 80) {
        printf("Performance level   : Very good overall progress.\n");
    } else if (averageProgress >= 50) {
        printf("Performance level   : Moderate progress, more work needed.\n");
    } else {
        printf("Performance level   : Low progress, needs strong improvement.\n");
    }

    if (completedCount == count) {
        printf("Completion status   : All students are completed.\n");
    } else if (completedCount > 0) {
        printf("Completion status   : Some students have completed their work.\n");
    } else {
        printf("Completion status   : No student has completed yet.\n");
    }
}

void showMenu() {
    printf("\n=== Student Progress Tracker ===\n");
    printf("1. Add Record\n");
    printf("2. Show Records\n");
    printf("3. Show Report\n");
    printf("4. Exit\n");
}

int main() {
    StudentRecord records[MAX_RECORDS];
    int count = 0;
    int choice;
    int running = 1;

    while (running) {
        showMenu();

        if (!readInteger("Choose an option: ", &choice)) {
            printf("Invalid menu input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                showRecords(records, count);
                break;
            case 3:
                showReport(records, count);
                break;
            case 4:
                printf("Exiting program...\n");
                running = 0;
                break;
            default:
                printf("Invalid menu choice. Please choose 1, 2, 3, or 4.\n");
                break;
        }
    }

    return 0;
}
