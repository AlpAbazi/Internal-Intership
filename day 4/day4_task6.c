#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int readInteger(const char *message, int *value) {
    printf("%s", message);
    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return 0;
    }
    return 1;
}

void readLine(const char *message, char text[], int size) {
    printf("%s", message);
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = '\0';
}

const char *statusToString(StudentStatus status) {
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

void printDivider() {
    printf("------------------------------------------------------------\n");
}

void printTitle() {
    printf("\n============================================================\n");
    printf("               STUDENT PROGRESS TRACKER\n");
    printf("============================================================\n");
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

int chooseStatus(StudentStatus *status) {
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

void addRecord(StudentRecord records[], int *count) {
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
    readLine("Enter student name: ", newRecord.name, sizeof(newRecord.name));

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

    printDivider();
    printf("%-5s %-20s %-10s %-15s\n", "ID", "Name", "Progress", "Status");
    printDivider();

    for (i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d %-15s\n",
               records[i].id,
               records[i].name,
               records[i].progress,
               statusToString(records[i].status));
    }

    printDivider();
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
        }

        if (records[i].progress < lowestProgress) {
            lowestProgress = records[i].progress;
        }
    }

    averageProgress = (float)totalProgress / count;

    printf("\n================= ANALYTIC REPORT =================\n");
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

void updateStudentProgress(StudentRecord *record) {
    int newProgress;

    printf("\nUpdating record for: %s (ID: %d)\n", record->name, record->id);
    printf("Current progress: %d%%\n", record->progress);
    printf("Current status: %s\n", statusToString(record->status));

    if (!readInteger("Enter new progress (0-100): ", &newProgress) ||
        newProgress < 0 || newProgress > 100) {
        printf("Invalid progress. Please enter a number from 0 to 100.\n");
        return;
    }

    record->progress = newProgress;

    if (record->progress == 0) {
        record->status = STATUS_NOT_STARTED;
    } else if (record->progress == 100) {
        record->status = STATUS_COMPLETED;
    } else {
        record->status = STATUS_IN_PROGRESS;
    }

    printf("Record updated successfully.\n");
    printf("New progress: %d%%\n", record->progress);
    printf("New status: %s\n", statusToString(record->status));
}

void updateRecordById(StudentRecord records[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("No records available to update.\n");
        return;
    }

    if (!readInteger("Enter student ID to update: ", &id)) {
        printf("Invalid input. Please enter a number.\n");
        return;
    }

    index = findStudentById(records, count, id);

    if (index == -1) {
        printf("Student with ID %d was not found.\n", id);
        return;
    }

    updateStudentProgress(&records[index]);
}

int containsIgnoreCase(const char text[], const char search[]) {
    char textLower[NAME_LENGTH];
    char searchLower[NAME_LENGTH];
    int i;

    for (i = 0; text[i] != '\0' && i < NAME_LENGTH - 1; i++) {
        textLower[i] = (char)tolower((unsigned char)text[i]);
    }
    textLower[i] = '\0';

    for (i = 0; search[i] != '\0' && i < NAME_LENGTH - 1; i++) {
        searchLower[i] = (char)tolower((unsigned char)search[i]);
    }
    searchLower[i] = '\0';

    return strstr(textLower, searchLower) != NULL;
}

void showRecordEvaluation(StudentRecord record) {
    printf("Evaluation:\n");

    if (record.progress < 30 && record.status != STATUS_COMPLETED) {
        printf("- Warning: Progress is very low and the student is far from completion.\n");
    } else if (record.progress >= 30 && record.progress < 70 && record.status == STATUS_IN_PROGRESS) {
        printf("- Recommendation: Student is progressing, but needs continued support.\n");
    } else if (record.progress >= 70 && record.progress < 100 && record.status == STATUS_IN_PROGRESS) {
        printf("- Recommendation: Student is close to completion. Final push is needed.\n");
    } else if (record.progress == 100 && record.status == STATUS_COMPLETED) {
        printf("- Excellent: Record is fully completed and consistent.\n");
    } else if (record.progress == 100 && record.status != STATUS_COMPLETED) {
        printf("- Warning: Progress is 100%% but status is not marked as completed.\n");
    } else if (record.progress == 0 && record.status == STATUS_IN_PROGRESS) {
        printf("- Warning: Status says in progress, but recorded progress is 0%%.\n");
    } else if (record.progress > 0 && record.status == STATUS_NOT_STARTED) {
        printf("- Warning: Progress exists, but status is still marked as not started.\n");
    } else {
        printf("- Info: Record is valid. Continue monitoring progress.\n");
    }
}

void printSingleRecord(StudentRecord record) {
    printf("\nRecord found:\n");
    printf("ID       : %d\n", record.id);
    printf("Name     : %s\n", record.name);
    printf("Progress : %d%%\n", record.progress);
    printf("Status   : %s\n", statusToString(record.status));
    showRecordEvaluation(record);
}

void searchById(StudentRecord records[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("No records available for search.\n");
        return;
    }

    if (!readInteger("Enter student ID to search: ", &id)) {
        printf("Invalid input. Please enter a number.\n");
        return;
    }

    index = findStudentById(records, count, id);

    if (index == -1) {
        printf("No record found with ID %d.\n", id);
        return;
    }

    printSingleRecord(records[index]);
}

void searchByName(StudentRecord records[], int count) {
    char searchName[NAME_LENGTH];
    int i;
    int found = 0;

    if (count == 0) {
        printf("No records available for search.\n");
        return;
    }

    clearInputBuffer();
    readLine("Enter student name to search: ", searchName, sizeof(searchName));

    if (strlen(searchName) == 0) {
        printf("Search text cannot be empty.\n");
        return;
    }

    printf("\nMatching records:\n");

    for (i = 0; i < count; i++) {
        if (containsIgnoreCase(records[i].name, searchName)) {
            printSingleRecord(records[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found with name containing \"%s\".\n", searchName);
    }
}

void searchMenu(StudentRecord records[], int count) {
    int choice;

    if (count == 0) {
        printf("No records available for search.\n");
        return;
    }

    printf("\nSearch options:\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");

    if (!readInteger("Choose search option: ", &choice)) {
        printf("Invalid input. Please enter a number.\n");
        return;
    }

    switch (choice) {
        case 1:
            searchById(records, count);
            break;
        case 2:
            searchByName(records, count);
            break;
        default:
            printf("Invalid search option. Please choose 1 or 2.\n");
            break;
    }
}

void sortRecordsByProgress(StudentRecord records[], int count) {
    int i, j;
    StudentRecord temp;

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (records[j].progress < records[j + 1].progress) {
                temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void showRanking(StudentRecord records[], int count) {
    StudentRecord sorted[MAX_RECORDS];
    int i;

    if (count == 0) {
        printf("No records available for ranking.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sorted[i] = records[i];
    }

    sortRecordsByProgress(sorted, count);

    printf("\n================ STUDENT RANKING ==================\n");
    printf("%-6s %-5s %-20s %-10s %-15s\n", "Rank", "ID", "Name", "Progress", "Status");
    printDivider();

    for (i = 0; i < count; i++) {
        printf("%-6d %-5d %-20s %-10d %-15s\n",
               i + 1,
               sorted[i].id,
               sorted[i].name,
               sorted[i].progress,
               statusToString(sorted[i].status));
    }

    printDivider();
    printf("Ranking is based on progress from highest to lowest.\n");
}

void showMenu() {
    printTitle();
    printf("1. Add Record\n");
    printf("2. Show Records\n");
    printf("3. Show Report\n");
    printf("4. Update Student Progress\n");
    printf("5. Search Record\n");
    printf("6. Show Ranking\n");
    printf("7. Exit\n");
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
                updateRecordById(records, count);
                break;
            case 5:
                searchMenu(records, count);
                break;
            case 6:
                showRanking(records, count);
                break;
            case 7:
                printf("Exiting program...\n");
                running = 0;
                break;
            default:
                printf("Invalid menu choice. Please choose from 1 to 7.\n");
                break;
        }
    }

    return 0;
}
