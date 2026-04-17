#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

enum Status {
    NOT_STARTED,
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
    if (*count >= MAX_STUDENTS) {
        printf("\nNuk mund te shtohen me shume regjistrime. Eshte arritur maksimumi.\n");
        return;
    }

    printf("\nShkruaj ID: ");
    scanf("%d", &students[*count].id);

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Shkruaj progresin (0 - 100): ");
    scanf("%f", &students[*count].progress);

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Progres i pavlefshem. Po vendoset 0.\n");
        students[*count].progress = 0;
    }

    if (students[*count].progress == 0) {
        students[*count].status = NOT_STARTED;
    } else if (students[*count].progress < 100) {
        students[*count].status = IN_PROGRESS;
    } else {
        students[*count].status = COMPLETED;
    }

    (*count)++;
    printf("Regjistrimi u shtua me sukses.\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\n--- Lista e regjistrimeve ---\n");

    for (i = 0; i < count; i++) {
        printf("\nRegjistrimi %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f\n", students[i].progress);

        if (students[i].status == NOT_STARTED) {
            printf("Statusi: Not Started\n");
        } else if (students[i].status == IN_PROGRESS) {
            printf("Statusi: In Progress\n");
        } else {
            printf("Statusi: Completed\n");
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Dalje\n");
        printf("Zgjedh opsionin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 3);

    return 0;
}
