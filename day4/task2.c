#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void addStudent(struct Student students[], int *count) {
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("\nMax u arrit.\n");
        return;
    }

    printf("\nID: ");
    if (scanf("%d", &students[*count].id) != 1) {
        printf("Input gabim.\n");
        while(getchar()!='\n');
        return;
    }

    printf("Emri: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Progresi (0-100): ");
    if (scanf("%f", &students[*count].progress) != 1) {
        printf("Input gabim.\n");
        while(getchar()!='\n');
        return;
    }

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem.\n");
        return;
    }

    printf("Zgjedh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedh: ");

    if (scanf("%d", &statusChoice) != 1) {
        printf("Input gabim.\n");
        while(getchar()!='\n');
        return;
    }

    switch(statusChoice) {
        case 1:
            students[*count].status = NOT_STARTED;
            break;
        case 2:
            students[*count].status = IN_PROGRESS;
            break;
        case 3:
            students[*count].status = COMPLETED;
            break;
        default:
            printf("Status i pavlefshem.\n");
            return;
    }

    (*count)++;
    printf("U shtua.\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka data.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);

        switch(students[i].status) {
            case NOT_STARTED:
                printf("Status: Not Started\n");
                break;
            case IN_PROGRESS:
                printf("Status: In Progress\n");
                break;
            case COMPLETED:
                printf("Status: Completed\n");
                break;
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto\n");
        printf("2. Shfaq\n");
        printf("3. Dalje\n");
        printf("Zgjedh: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input gabim.\n");
            while(getchar()!='\n');
            continue;
        }

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                printf("Bye\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while(choice != 3);

    return 0;
}

