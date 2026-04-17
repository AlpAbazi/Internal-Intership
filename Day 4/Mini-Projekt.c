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

int main(){
    int ids[MAX];
    float progress[MAX];
    enum Status status[MAX];

    int count = 0;
    int choice;

    do{
        printf("\n=== MENU ===\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Edit Student Status\n");
        printf("4. Show Report\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input!\n");
            return 1;
        }

        switch(choice){

            case 1:
                if (count >= MAX){
                    printf("List is full!\n");
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

                float *p = &progress[count];

                if (*p == 0)
                    status[count] = NOT_STARTED;
                else if (*p < 100)
                    status[count] = IN_PROGRESS;
                else
                    status[count] = COMPLETED;

                count++;

                printf("Student added successfully!\n");
                break;


            case 2:
                if (count == 0) {
                    printf("No students added!\n");
                    break;
                }

                printf("\n===== STUDENT LIST =====\n");

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\n", ids[i]);
                    printf("Progress: %.2f\n", progress[i]);

                    printf("Status: ");
                    switch(status[i]) {
                        case NOT_STARTED:
                            printf("Not Started\n");
                            break;
                        case IN_PROGRESS:
                            printf("In Progress\n");
                            break;
                        case COMPLETED:
                            printf("Completed\n");
                            break;
                    }
                }
                break;


            case 3:
            {
                int id, found = 0;

                if (count == 0) {
                    printf("\nNo students to edit\n");
                    break;
                }

                printf("\n===== STUDENT LIST =====\n");

                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\n", ids[i]);
                    printf("Progress: %.2f\n", progress[i]);

                    printf("Status: ");
                    switch(status[i]) {
                        case NOT_STARTED:
                            printf("Not Started\n");
                            break;
                        case IN_PROGRESS:
                            printf("In Progress\n");
                            break;
                        case COMPLETED:
                            printf("Completed\n");
                            break;
                    }
                }

                printf("Enter Student ID To edit: ");
                if (scanf("%d", &id) != 1) { 
                    printf("Invalid input!\n");
                    return 1;
                }

                for (int i = 0; i < count; i++) {
                    if (ids[i] == id) {
                        found = 1;
                        updateStudent(&progress[i], &status[i]);
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }

                break;
            }


            case 4:
            {
                if (count == 0) {
                    printf("\nNo data available for report!\n");
                    break;
                }

                int completed = 0;
                float sum = 0;
                float max = progress[0];
                float min = progress[0];

                for (int i = 0; i < count; i++) {
                    sum += progress[i];

                    if (progress[i] > max)
                        max = progress[i];

                    if (progress[i] < min)
                        min = progress[i];

                    if (status[i] == COMPLETED)
                        completed++;
                }

                float avg = sum / count;

                printf("\n===== REPORT =====\n");
                printf("Total students: %d\n", count);
                printf("Completed: %d\n", completed);
                printf("Average progress: %.2f\n", avg);
                printf("Highest progress: %.2f\n", max);
                printf("Lowest progress: %.2f\n", min);

                if (avg >= 80)
                    printf("Class Performance: Excellent\n");
                else if (avg >= 50)
                    printf("Class Performance: Good\n");
                else
                    printf("Class Performance: Weak\n");

                printf("=====================\n");
                break;
            }

            case 5:
                searchStudent(ids, progress, status, count);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}