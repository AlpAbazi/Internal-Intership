#include <stdio.h>

#define MAX 25

enum Status {NOT_STARTED, IN_PROGRESS, COMPLETED};

void updateStudent(float *progress, enum Status *status) {
    float newProgress;

    printf("Enter new progress (0-100): ");
    if (scanf("%f", &newProgress) != 1) {
        printf("Invalid input!\n");
        return;
    }

    if (newProgress < 0 || newProgress > 100) {
        printf("Invalid progress!\n");
        return;
    }

    *progress = newProgress;

    if (*progress == 0)
        *status = NOT_STARTED;
    else if (*progress < 100)
        *status = IN_PROGRESS;
    else
        *status = COMPLETED;

    printf("Student updated successfully!\n");
}

void searchStudent(int ids[], float progress[], enum Status status[], int count) {
    int id;

    if (count == 0) {
        printf("No students available!\n");
        return;
    }

    printf("\n===== STUDENT IDS =====\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", ids[i]);
    }

    printf("\nEnter ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            found = 1;

            printf("\n===== RESULT =====\n");
            printf("ID: %d\n", ids[i]);

            if (progress[i] < 30 && status[i] == NOT_STARTED)
                printf("Critical: No progress started!\n");
            else if (progress[i] < 50 && status[i] == IN_PROGRESS)
                printf("Warning: Student is behind!\n");
            else if (progress[i] >= 100 && status[i] == COMPLETED)
                printf("Excellent: Fully completed!\n");
            else if (progress[i] >= 80)
                printf("Good performance, keep going!\n");

            printf("==================\n");
        }
    }

    if (!found) {
        printf("No student found with this ID!\n");
    }
}

void showRanking(int ids[], float progress[], int count) {
    if (count == 0) {
        printf("No students available!\n");
        return;
    }

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
        printf("%d. ID: %d | Progress: %.2f%%\n",
               i + 1, sortedIDs[i], sortedProgress[i]);
    }

    printf("===================\n");
}

int main() {
    int ids[MAX];
    float progress[MAX];
    enum Status status[MAX];

    int count = 0;
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Edit Student\n");
        printf("4. Show Report\n");
        printf("5. Search Student\n");
        printf("6. Show Ranking\n");
        printf("7. Delete Student\n");
        printf("8. Exit\n");
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {

            case 1:
                if (count >= MAX) {
                    printf("List full!\n");
                    break;
                }

                printf("ID: ");
                if (scanf("%d", &ids[count]) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                printf("Progress (0-100): ");
                if (scanf("%f", &progress[count]) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (progress[count] < 0 || progress[count] > 100) {
                    printf("Invalid progress!\n");
                    break;
                }

                if (progress[count] == 0)
                    status[count] = NOT_STARTED;
                else if (progress[count] < 100)
                    status[count] = IN_PROGRESS;
                else
                    status[count] = COMPLETED;

                count++;
                printf("Student added!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No students!\n");
                    break;
                }

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\n", ids[i]);
                    printf("Progress: %.2f\n", progress[i]);

                    printf("Status: ");
                    switch (status[i]) {
                        case NOT_STARTED: printf("Not Started\n"); break;
                        case IN_PROGRESS: printf("In Progress\n"); break;
                        case COMPLETED: printf("Completed\n"); break;
                    }
                }
                break;

            case 3: {
                int id, found = 0;

                printf("Enter ID to edit: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (ids[i] == id) {
                        found = 1;

                        printf("1. Change Progress\n");
                        printf("2. Change Status (via progress)\n");
                        printf("3. Change Both\n");
                        printf("Choice: ");

                        int c;
                        scanf("%d", &c);

                        if (c == 1 || c == 3) {
                            printf("Enter new progress: ");
                            scanf("%f", &progress[i]);
                        }

                        if (c == 2 || c == 3) {
                            if (progress[i] == 0)
                                status[i] = NOT_STARTED;
                            else if (progress[i] < 100)
                                status[i] = IN_PROGRESS;
                            else
                                status[i] = COMPLETED;
                        }

                        printf("Updated!\n");
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 4: {
                if (count == 0) {
                    printf("No data!\n");
                    break;
                }

                int completed = 0;
                float sum = 0, max = progress[0], min = progress[0];

                for (int i = 0; i < count; i++) {
                    sum += progress[i];

                    if (progress[i] > max) max = progress[i];
                    if (progress[i] < min) min = progress[i];
                    if (status[i] == COMPLETED) completed++;
                }

                printf("\n===== REPORT =====\n");
                printf("Total: %d\n", count);
                printf("Completed: %d\n", completed);
                printf("Avg: %.2f\n", sum / count);
                printf("Max: %.2f\n", max);
                printf("Min: %.2f\n", min);

                printf("==================\n");
                break;
            }

            case 5:
                searchStudent(ids, progress, status, count);
                break;

            case 6:
                showRanking(ids, progress, count);
                break;

            case 7: {
                int id, found = 0;

                printf("Enter ID to delete: ");
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (ids[i] == id) {
                        found = 1;

                        for (int j = i; j < count - 1; j++) {
                            ids[j] = ids[j + 1];
                            progress[j] = progress[j + 1];
                            status[j] = status[j + 1];
                        }

                        count--;
                        printf("Student deleted!\n");
                        break;
                    }
                }

                if (!found)
                    printf("Student not found!\n");

                break;
            }

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}