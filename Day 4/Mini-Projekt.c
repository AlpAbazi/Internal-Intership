#include <stdio.h>

#define MAX 25

enum Status {NOT_STARTED, IN_PROGRESS, COMPLETED};

void printStatus(enum Status s) {
    switch (s) {
        case NOT_STARTED: printf("Not Started\n"); break;
        case IN_PROGRESS: printf("In Progress\n"); break;
        case COMPLETED: printf("Completed\n"); break;
    }
}

void printStudent(int id, float progress, enum Status status) {
    printf("\n---------------------\n");
    printf("ID: %d\n", id);
    printf("Progress: %.2f%%\n", progress);
    printf("Status: ");
    printStatus(status);
    printf("---------------------\n");
}

void updateStatus(float progress, enum Status *status) {
    if (progress == 0)
        *status = NOT_STARTED;
    else if (progress < 100)
        *status = IN_PROGRESS;
    else
        *status = COMPLETED;
}

void addStudent(int ids[], float progress[], enum Status status[], int *count) {
    if (*count >= MAX) {
        printf("List full!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &ids[*count]);

    printf("Progress (0-100): ");
    scanf("%f", &progress[*count]);

    if (progress[*count] < 0 || progress[*count] > 100) {
        printf("Invalid progress!\n");
        return;
    }

    updateStatus(progress[*count], &status[*count]);

    (*count)++;
    printf("Student added!\n");
}

void showStudents(int ids[], float progress[], enum Status status[], int count) {
    if (count == 0) {
        printf("No students!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printStudent(ids[i], progress[i], status[i]);
    }
}

void editStudent(int ids[], float progress[], enum Status status[], int count) {
    int id, found = 0;

    printf("Enter ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            found = 1;

            int choice;
            printf("1. Change Progress\n2. Change Status (via progress)\n3. Change Both\nChoice: ");
            scanf("%d", &choice);

            if (choice == 1 || choice == 3) {
                printf("New progress: ");
                scanf("%f", &progress[i]);
            }

            if (choice == 2 || choice == 3) {
                updateStatus(progress[i], &status[i]);
            }

            printf("Updated!\n");
            return;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

void deleteStudent(int ids[], float progress[], enum Status status[], int *count) {
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (ids[i] == id) {
            found = 1;

            for (int j = i; j < *count - 1; j++) {
                ids[j] = ids[j + 1];
                progress[j] = progress[j + 1];
                status[j] = status[j + 1];
            }

            (*count)--;
            printf("Student deleted!\n");
            return;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

void searchStudent(int ids[], float progress[], enum Status status[], int count) {
    int id;

    printf("\nIDs:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", ids[i]);
    }

    printf("Search ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            printStudent(ids[i], progress[i], status[i]);

            if (progress[i] < 30)
                printf("Critical: No progress!\n");
            else if (progress[i] < 50)
                printf("Warning: Behind schedule!\n");
            else if (progress[i] >= 80)
                printf("Good performance!\n");

            return;
        }
    }

    printf("Not found!\n");
}

void showRanking(int ids[], float progress[], enum Status status[], int count) {
    int sortedIDs[MAX];
    float sortedProgress[MAX];

    for (int i = 0; i < count; i++) {
        sortedIDs[i] = ids[i];
        sortedProgress[i] = progress[i];
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (sortedProgress[i] < sortedProgress[j]) {
                float tp = sortedProgress[i];
                sortedProgress[i] = sortedProgress[j];
                sortedProgress[j] = tp;

                int ti = sortedIDs[i];
                sortedIDs[i] = sortedIDs[j];
                sortedIDs[j] = ti;
            }
        }
    }

    printf("\n===== RANKING =====\n");

    for (int i = 0; i < count; i++) {
        printf("%d. ID: %d | %.2f%%\n", i + 1, sortedIDs[i], sortedProgress[i]);
    }
}

int main() {
    int ids[MAX];
    float progress[MAX];
    enum Status status[MAX];

    int count = 0;
    int choice;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Show Ranking\n");
        printf("7. Exit\n");
        printf("========================\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(ids, progress, status, &count); break;
            case 2: showStudents(ids, progress, status, count); break;
            case 3: editStudent(ids, progress, status, count); break;
            case 4: deleteStudent(ids, progress, status, &count); break;
            case 5: searchStudent(ids, progress, status, count); break;
            case 6: showRanking(ids, progress, status, count); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}