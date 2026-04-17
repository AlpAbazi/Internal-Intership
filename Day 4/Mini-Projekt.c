#include <stdio.h>

#define MAX 25

enum Status{NOT_STARTED, IN_PROGRESS, COMPLETED};

int main(){
    int ids[MAX];
    float progress [MAX];
    enum Status status[MAX];

    int count = 0;
    int choice;

    do{
        printf("\n=== MENU ===\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Exit\n");
        printf("Enter Choice : ");
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

            float *p = &progress[count];

            if (*p == 0)
                status[count] = NOT_STARTED;
            else if (*p < 100)
                status[count] = IN_PROGRESS;
            else
                status[count] = COMPLETED;

            count++;
                printf("Student added!\n");
                break;


            case 2:
                if (count == 0) {
                    printf("No students added!\n");
                    break;
                }

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
                printf("Exiting...\n");
                break;

                default:
                printf("Please try again.");
        }
    } while (choice != 3);

    return 0;
}