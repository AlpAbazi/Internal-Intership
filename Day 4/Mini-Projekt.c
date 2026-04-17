#include <stdio.h>

#define MAX 25

enum Status {NOT_STARTED, IN_PROGRESS, COMPLETED};

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
        printf("3. Edit Students Status\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                if (count >= MAX){
                    printf("List is full!\n");
                    break;
                }

                printf("ID: ");
                scanf("%d", &ids[count]);

                printf("Progress (0-100): ");
                scanf("%f", &progress[count]);

                if (progress[count] < 0 || progress[count] > 100) {
                    printf("Invalid progress! Must be 0-100.\n");
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
                printf("Total: %d/%d\n", count, MAX);
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
                int id, found = 0;

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
                scanf("%d", &id);

                for (int i = 0; i < count; i++) {
                    if (ids[i] == id) {
                        found = 1;

                        float newProgress;

                        printf("Enter new progress (0-100): ");
                        scanf("%f", &newProgress);
                        
                        if (newProgress < 0 || newProgress > 100) {
                            printf("Invalid progress! Must be 0-100.\n");
                            break;
                        }
            
                        progress[i] = newProgress;

                        int progressLevel;

                        if (progress[i] == 0)
                            progressLevel = 1;
                        else if (progress[i] < 100)
                            progressLevel = 2;
                        else
                            progressLevel = 3;

                        switch(progressLevel) {
                            case 1:
                                status[i] = NOT_STARTED;
                                break;
                            case 2:
                                status[i] = IN_PROGRESS;
                                break;
                            case 3:
                                status[i] = COMPLETED;
                                break;
                        }

                        printf("Student updated successfully!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Student not found!\n");
                }
            break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}