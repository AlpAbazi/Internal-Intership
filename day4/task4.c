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

void updateStudent(struct Student *s) {
    float newProgress;

    printf("Progresi i ri (0-100): ");
    if (scanf("%f", &newProgress) != 1) {
        printf("Input gabim.\n");
        while(getchar()!='\n');
        return;
    }

    if (newProgress < 0 || newProgress > 100) {
        printf("Progres i pavlefshem.\n");
        return;
    }

    s->progress = newProgress;

    if (newProgress == 0) {
        s->status = NOT_STARTED;
    } else if (newProgress < 100) {
        s->status = IN_PROGRESS;
    } else {
        s->status = COMPLETED;
    }

    printf("U perditesua.\n");
}

void findAndUpdate(struct Student students[], int count) {
    int id, i, found = 0;

    if (count == 0) {
        printf("Nuk ka data.\n");
        return;
    }

    printf("Shkruaj ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);  // pointer ketu
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nuk u gjet.\n");
    }
}

void addStudent(struct Student students[], int *count) {
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("Max u arrit.\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &students[*count].id);

    printf("Emri: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Progresi: ");
    scanf("%f", &students[*count].progress);

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Gabim.\n");
        return;
    }

    printf("1.Not Started 2.In Progress 3.Completed: ");
    scanf("%d", &statusChoice);

    switch(statusChoice) {
        case 1: students[*count].status = NOT_STARTED; break;
        case 2: students[*count].status = IN_PROGRESS; break;
        case 3: students[*count].status = COMPLETED; break;
        default: printf("Gabim.\n"); return;
    }

    (*count)++;
    printf("U shtua.\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("Nuk ka data.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);

        switch(students[i].status) {
            case NOT_STARTED: printf("Status: Not Started\n"); break;
            case IN_PROGRESS: printf("Status: In Progress\n"); break;
            case COMPLETED: printf("Status: Completed\n"); break;
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
        printf("3. Update (pointer)\n");
        printf("4. Dalje\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(students, &count); break;
            case 2: showStudents(students, count); break;
            case 3: findAndUpdate(students, count); break;
            case 4: printf("Bye\n"); break;
            default: printf("Gabim.\n");
        }

    } while(choice != 4);

    return 0;
}
