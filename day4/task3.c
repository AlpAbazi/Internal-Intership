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
        while (getchar() != '\n');
        return;
    }

    printf("Emri: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Progresi (0-100): ");
    if (scanf("%f", &students[*count].progress) != 1) {
        printf("Input gabim.\n");
        while (getchar() != '\n');
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
        while (getchar() != '\n');
        return;
    }

    switch (statusChoice) {
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

        switch (students[i].status) {
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

void showReport(struct Student students[], int count) {
    int i;
    int completed = 0;
    float sum = 0;
    float max;
    float min;
    float average;

    if (count == 0) {
        printf("\n--- RAPORTI ---\n");
        printf("Nuk ka regjistrime per analizë.\n");
        return;
    }

    max = students[0].progress;
    min = students[0].progress;

    for (i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].progress < min) {
            min = students[i].progress;
        }
    }

    average = sum / count;

    printf("\n--- RAPORTI ---\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i perfunduara: %d\n", completed);
    printf("Mesatarja e progresit: %.2f\n", average);
    printf("Progresi me i larte: %.2f\n", max);
    printf("Progresi me i ulet: %.2f\n", min);

    if (average >= 80) {
        printf("Vleresim: Progres shume i mire.\n");
    } else if (average >= 50) {
        printf("Vleresim: Progres mesatar.\n");
    } else {
        printf("Vleresim: Progres i ulet.\n");
    }

    if (completed == count) {
        printf("Status i pergjithshem: Te gjitha regjistrimet jane completed.\n");
    } else if (completed > 0) {
        printf("Status i pergjithshem: Disa regjistrime jane completed.\n");
    } else {
        printf("Status i pergjithshem: Asnje regjistrim nuk eshte completed.\n");
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
        printf("3. Raporti\n");
        printf("4. Dalje\n");
        printf("Zgjedh: ");

        if (scanf("%d", &choice) != 1) {
            printf("Input gabim.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                printf("Bye\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 4);

    return 0;
}
