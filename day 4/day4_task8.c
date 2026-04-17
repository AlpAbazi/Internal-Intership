#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
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

typedef struct {
    int totalRecords;
    int completedCount;
    int inProgressCount;
    int notStartedCount;
    int totalProgress;
    int highestProgress;
    int lowestProgress;
    float averageProgress;
} ReportData;

void clearInputBuffer(void);
int readInteger(const char *message, int *value);
int promptIntInRange(const char *message, int minValue, int maxValue, int *value);
void readLine(const char *message, char text[], int size);
int promptNonEmptyLine(const char *message, char text[], int size);
void printTitle(void);
void printDivider(void);
void printSection(const char *title);
const char *statusToString(StudentStatus status);
int chooseStatus(StudentStatus *status);
void syncStatusFromProgress(StudentRecord *record);
int findStudentById(StudentRecord records[], int count, int id);
int containsIgnoreCase(const char text[], const char search[]);
void printRecordHeader(void);
void printRecordRow(StudentRecord record);
void printSingleRecord(StudentRecord record);
void showRecordEvaluation(StudentRecord record);
void calculateReport(StudentRecord records[], int count, ReportData *report);
void addRecord(StudentRecord records[], int *count);
void showRecords(StudentRecord records[], int count);
void showReport(StudentRecord records[], int count);
void updateStudentProgress(StudentRecord *record);
void updateRecordById(StudentRecord records[], int count);
void searchById(StudentRecord records[], int count);
void searchByName(StudentRecord records[], int count);
void searchMenu(StudentRecord records[], int count);
void sortRecordsByProgress(StudentRecord records[], int count);
void showRanking(StudentRecord records[], int count);
void editRecord(StudentRecord *record);
void editRecordById(StudentRecord records[], int count);
void deleteRecordById(StudentRecord records[], int *count);
void showMenu(void);

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int readInteger(const char *message, int *value) {
    printf("%s", message);

    if (scanf("%d", value) != 1) {
        clearInputBuffer();
        return 0;
    }

    clearInputBuffer();
    return 1;
}

int promptIntInRange(const char *message, int minValue, int maxValue, int *value) {
    if (!readInteger(message, value)) {
        printf("Invalid input. Please enter a whole number.\n");
        return 0;
    }

    if (*value < minValue || *value > maxValue) {
        printf("Invalid value. Please enter a number from %d to %d.\n", minValue, maxValue);
        return 0;
    }

    return 1;
}

void readLine(const char *message, char text[], int size) {
    printf("%s", message);

    if (fgets(text, size, stdin) == NULL) {
        text[0] = '\0';
        return;
    }

    text[strcspn(text, "\n")] = '\0';
}

int promptNonEmptyLine(const char *message, char text[], int size) {
    readLine(message, text, size);

    if (strlen(text) == 0) {
        printf("This field cannot be empty.\n");
        return 0;
    }

    return 1;
}

void printTitle(void) {
    printf("\n===============================================================\n");
    printf("                  STUDENT PROGRESS TRACKER\n");
    printf("===============================================================\n");
}

void printDivider(void) {
    printf("---------------------------------------------------------------\n");
}

void printSection(const char *title) {
    printf("\n%s\n", title);
    printDivider();
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

int chooseStatus(StudentStatus *status) {
    int choice;

    printSection("Choose Student Status");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");

    if (!promptIntInRange("Enter status choice: ", 1, 3, &choice)) {
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
            return 0;
    }
}

void syncStatusFromProgress(StudentRecord *record) {
    if (record->progress == 0) {
        record->status = STATUS_NOT_STARTED;
    } else if (record->progress == 100) {
        record->status = STATUS_COMPLETED;
    } else {
        record->status = STATUS_IN_PROGRESS;
    }
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

void printRecordHeader(void) {
    printDivider();
    printf("%-5s %-22s %-10s %-15s\n", "ID", "Name", "Progress", "Status");
    printDivider();
}

void printRecordRow(StudentRecord record) {
    printf("%-5d %-22s %-10d %-15s\n",
           record.id,
           record.name,
           record.progress,
           statusToString(record.status));
}

void printSingleRecord(StudentRecord record) {
    printSection("Record Details");
    printf("ID       : %d\n", record.id);
    printf("Name     : %s\n", record.name);
    printf("Progress : %d%%\n", record.progress);
    printf("Status   : %s\n", statusToString(record.status));
    showRecordEvaluation(record);
}

void showRecordEvaluation(StudentRecord record) {
    printf("Evaluation:\n");

    if (record.progress < 30 && record.status != STATUS_COMPLETED) {
        printf("- Warning: Progress is very low and the student needs immediate support.\n");
    } else if (record.progress >= 30 && record.progress < 70 &&
               record.status == STATUS_IN_PROGRESS) {
        printf("- Recommendation: Progress is moderate. Keep tracking and supporting this student.\n");
    } else if (record.progress >= 70 && record.progress < 100 &&
               record.status == STATUS_IN_PROGRESS) {
        printf("- Recommendation: Student is close to completion and needs a final push.\n");
    } else if (record.progress == 100 && record.status == STATUS_COMPLETED) {
        printf("- Excellent: Record is complete and status is fully consistent.\n");
    } else if (record.progress == 100 && record.status != STATUS_COMPLETED) {
        printf("- Warning: Progress is 100%%, but status is not marked as completed.\n");
    } else if (record.progress == 0 && record.status == STATUS_IN_PROGRESS) {
        printf("- Warning: Status says in progress, but progress is still 0%%.\n");
    } else if (record.progress > 0 && record.status == STATUS_NOT_STARTED) {
        printf("- Warning: Progress exists, but status is still marked as not started.\n");
    } else {
        printf("- Info: Record is valid and does not need special action right now.\n");
    }
}

void calculateReport(StudentRecord records[], int count, ReportData *report) {
    int i;

    report->totalRecords = count;
    report->completedCount = 0;
    report->inProgressCount = 0;
    report->notStartedCount = 0;
    report->totalProgress = 0;
    report->highestProgress = 0;
    report->lowestProgress = 0;
    report->averageProgress = 0.0f;

    if (count == 0) {
        return;
    }

    report->highestProgress = records[0].progress;
    report->lowestProgress = records[0].progress;

    for (i = 0; i < count; i++) {
        report->totalProgress += records[i].progress;

        if (records[i].status == STATUS_COMPLETED) {
            report->completedCount++;
        } else if (records[i].status == STATUS_IN_PROGRESS) {
            report->inProgressCount++;
        } else {
            report->notStartedCount++;
        }

        if (records[i].progress > report->highestProgress) {
            report->highestProgress = records[i].progress;
        }

        if (records[i].progress < report->lowestProgress) {
            report->lowestProgress = records[i].progress;
        }
    }

    report->averageProgress = (float)report->totalProgress / count;
}

void addRecord(StudentRecord records[], int *count) {
    StudentRecord newRecord;

    printSection("Add New Record");

    if (*count >= MAX_RECORDS) {
        printf("Tracker is full. Maximum %d records are allowed.\n", MAX_RECORDS);
        return;
    }

    if (!promptIntInRange("Enter student ID: ", 1, 1000000, &newRecord.id)) {
        return;
    }

    if (findStudentById(records, *count, newRecord.id) != -1) {
        printf("A record with this ID already exists.\n");
        return;
    }

    if (!promptNonEmptyLine("Enter student name: ", newRecord.name, sizeof(newRecord.name))) {
        return;
    }

    if (!promptIntInRange("Enter progress (0-100): ", 0, 100, &newRecord.progress)) {
        return;
    }

    if (!chooseStatus(&newRecord.status)) {
        return;
    }

    records[*count] = newRecord;
    (*count)++;

    printf("Record added successfully. Total records: %d\n", *count);
}

void showRecords(StudentRecord records[], int count) {
    int i;

    printSection("All Records");

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printRecordHeader();

    for (i = 0; i < count; i++) {
        printRecordRow(records[i]);
    }

    printDivider();
}

void showReport(StudentRecord records[], int count) {
    ReportData report;

    calculateReport(records, count, &report);
    printSection("Analytic Report");

    if (count == 0) {
        printf("No records available for analysis.\n");
        return;
    }

    printf("Total records      : %d\n", report.totalRecords);
    printf("Completed          : %d\n", report.completedCount);
    printf("In progress        : %d\n", report.inProgressCount);
    printf("Not started        : %d\n", report.notStartedCount);
    printf("Average progress   : %.2f%%\n", report.averageProgress);
    printf("Highest progress   : %d%%\n", report.highestProgress);
    printf("Lowest progress    : %d%%\n", report.lowestProgress);

    if (report.averageProgress >= 80.0f) {
        printf("Performance note   : Overall progress is very strong.\n");
    } else if (report.averageProgress >= 50.0f) {
        printf("Performance note   : Progress is acceptable but still needs improvement.\n");
    } else {
        printf("Performance note   : Progress is low and needs extra attention.\n");
    }

    if (report.completedCount == report.totalRecords) {
        printf("Completion note    : Every student has completed the work.\n");
    } else if (report.completedCount > 0) {
        printf("Completion note    : Some students are completed, but some still need support.\n");
    } else {
        printf("Completion note    : No student has completed the work yet.\n");
    }
}

void updateStudentProgress(StudentRecord *record) {
    int newProgress;

    printSection("Update Student Progress");
    printf("Student: %s (ID: %d)\n", record->name, record->id);
    printf("Current progress: %d%%\n", record->progress);
    printf("Current status  : %s\n", statusToString(record->status));

    if (!promptIntInRange("Enter new progress (0-100): ", 0, 100, &newProgress)) {
        return;
    }

    record->progress = newProgress;
    syncStatusFromProgress(record);

    printf("Progress updated successfully.\n");
    printf("New progress: %d%%\n", record->progress);
    printf("New status  : %s\n", statusToString(record->status));
}

void updateRecordById(StudentRecord records[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("No records available to update.\n");
        return;
    }

    if (!promptIntInRange("Enter student ID to update progress: ", 1, 1000000, &id)) {
        return;
    }

    index = findStudentById(records, count, id);

    if (index == -1) {
        printf("No record found with ID %d.\n", id);
        return;
    }

    updateStudentProgress(&records[index]);
}

void searchById(StudentRecord records[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("No records available for search.\n");
        return;
    }

    if (!promptIntInRange("Enter student ID to search: ", 1, 1000000, &id)) {
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

    if (!promptNonEmptyLine("Enter student name to search: ", searchName, sizeof(searchName))) {
        return;
    }

    printSection("Matching Records");

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

    printSection("Search Menu");

    if (count == 0) {
        printf("No records available for search.\n");
        return;
    }

    printf("1. Search by ID\n");
    printf("2. Search by name\n");

    if (!promptIntInRange("Choose search option: ", 1, 2, &choice)) {
        return;
    }

    switch (choice) {
        case 1:
            searchById(records, count);
            break;
        case 2:
            searchByName(records, count);
            break;
    }
}

void sortRecordsByProgress(StudentRecord records[], int count) {
    int i;
    int j;
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

    printSection("Student Ranking");

    if (count == 0) {
        printf("No records available for ranking.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        sorted[i] = records[i];
    }

    sortRecordsByProgress(sorted, count);
    printDivider();
    printf("%-6s %-5s %-22s %-10s %-15s\n", "Rank", "ID", "Name", "Progress", "Status");
    printDivider();

    for (i = 0; i < count; i++) {
        printf("%-6d %-5d %-22s %-10d %-15s\n",
               i + 1,
               sorted[i].id,
               sorted[i].name,
               sorted[i].progress,
               statusToString(sorted[i].status));
    }

    printDivider();
    printf("Ranking is based on progress from highest to lowest.\n");
}

void editRecord(StudentRecord *record) {
    int choice;
    int newProgress;
    StudentStatus newStatus;
    char newName[NAME_LENGTH];

    printSection("Edit Record");
    printf("Editing student: %s (ID: %d)\n", record->name, record->id);
    printf("1. Change name\n");
    printf("2. Change progress\n");
    printf("3. Change status\n");
    printf("4. Change name and progress\n");

    if (!promptIntInRange("Choose edit option: ", 1, 4, &choice)) {
        return;
    }

    switch (choice) {
        case 1:
            if (!promptNonEmptyLine("Enter new name: ", newName, sizeof(newName))) {
                return;
            }
            strcpy(record->name, newName);
            printf("Name updated successfully.\n");
            break;
        case 2:
            if (!promptIntInRange("Enter new progress (0-100): ", 0, 100, &newProgress)) {
                return;
            }
            record->progress = newProgress;
            syncStatusFromProgress(record);
            printf("Progress updated successfully.\n");
            break;
        case 3:
            if (!chooseStatus(&newStatus)) {
                return;
            }
            record->status = newStatus;
            printf("Status updated successfully.\n");
            break;
        case 4:
            if (!promptNonEmptyLine("Enter new name: ", newName, sizeof(newName))) {
                return;
            }
            if (!promptIntInRange("Enter new progress (0-100): ", 0, 100, &newProgress)) {
                return;
            }
            strcpy(record->name, newName);
            record->progress = newProgress;
            syncStatusFromProgress(record);
            printf("Name and progress updated successfully.\n");
            break;
    }
}

void editRecordById(StudentRecord records[], int count) {
    int id;
    int index;

    if (count == 0) {
        printf("No records available to edit.\n");
        return;
    }

    if (!promptIntInRange("Enter student ID to edit: ", 1, 1000000, &id)) {
        return;
    }

    index = findStudentById(records, count, id);

    if (index == -1) {
        printf("No record found with ID %d.\n", id);
        return;
    }

    editRecord(&records[index]);
}

void deleteRecordById(StudentRecord records[], int *count) {
    int id;
    int index;
    int i;

    if (*count == 0) {
        printf("No records available to delete.\n");
        return;
    }

    if (!promptIntInRange("Enter student ID to delete: ", 1, 1000000, &id)) {
        return;
    }

    index = findStudentById(records, *count, id);

    if (index == -1) {
        printf("No record found with ID %d.\n", id);
        return;
    }

    for (i = index; i < *count - 1; i++) {
        records[i] = records[i + 1];
    }

    (*count)--;
    printf("Record deleted successfully. Remaining records: %d\n", *count);
}

void showMenu(void) {
    printTitle();
    printf("1. Add record\n");
    printf("2. Show all records\n");
    printf("3. Show analytic report\n");
    printf("4. Update student progress\n");
    printf("5. Search record\n");
    printf("6. Show ranking\n");
    printf("7. Edit record\n");
    printf("8. Delete record\n");
    printf("9. Exit\n");
    printDivider();
}

int main(void) {
    StudentRecord records[MAX_RECORDS];
    int count = 0;
    int choice;
    int running = 1;

    while (running) {
        showMenu();

        if (!promptIntInRange("Choose an option: ", 1, 9, &choice)) {
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
                editRecordById(records, count);
                break;
            case 8:
                deleteRecordById(records, &count);
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                running = 0;
                break;
        }
    }

    return 0;
}
