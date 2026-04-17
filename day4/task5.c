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

void printStatus(enum Status status) {
    switch (status) {
        case NOT_STARTED:
            printf("Status: Not Started\n");
            break;
        case IN_PROGRESS:
            printf("Status: In Progress\n");
            break;
        case COMPLETED:
            printf("Status: Completed\n");
            break;
        default:
            printf("Status: Unknown\n");
    }
}

void printStudent(struct Student s) {
    printf("\nID: %d\n", s.id);
    printf("Emri: %s\n", s.name);
    printf("Progresi: %.2f\n", s.progress);
    printStatus(s.status);
}

void showWarning(struct Student s) {
    printf("Vleresim: ");

    if (s.progress < 40 && s.status != COMPLETED) {
        printf("Paralajmerim - progres shume i ulet dhe regjistrimi nuk eshte perfunduar.\n");
    } else if (s.progress >= 40 && s.progress < 70 && s.status == IN_PROGRESS) {
        printf("Ne rruge te mire, por ka nevoje per me shume pune.\n");
    } else if (s.progress == 100 && s.status == COMPLETED) {
        printf("Shkelqyeshem - regjistrimi eshte perfunduar me sukses.\n");
    } else if (s.progress > 70 && s.status == NOT_STARTED) {
        printf("Ka mospërputhje - progres i larte por statusi eshte Not Started.\n");
    } else if (s.progress == 0 && s.status == COMPLETED) {
        printf("Ka mospërputhje - statusi eshte Completed por progresi eshte 0.\n");
    } else {
        printf("Regjistrimi duket ne gjendje normale.\n");
    }
}

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
        printStudent(students[i]);
    }
}

void updateStudent(struct Student *s) {
    float newProgress;

    printf("Progresi i ri (0-100): ");
    if (scanf("%f", &newProgress) != 1) {
        printf("Input gabim.\n");
        while (getchar() != '\n');
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
    if (scanf("%d", &id) != 1) {
        printf("Input gabim.\n");
        while (getchar() != '\n');
        return;
    }

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nuk u gjet.\n");
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
        printf("Nuk ka regjistrime per analize.\n");
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
}

void searchStudent(struct Student students[], int count) {
    int choice;
    int id;
    int i;
    int found = 0;
    char searchName[50];

    if (count == 0) {
        printf("\nNuk ka data.\n");
        return;
    }

    printf("\nKerkim sipas:\n");
    printf("1. ID\n");
    printf("2. Emrit\n");
    printf("Zgjedh: ");

    if (scanf("%d", &choice) != 1) {
        printf("Input gabim.\n");
        while (getchar() != '\n');
        return;
    }

    switch (choice) {
        case 1:
            printf("Shkruaj ID: ");
            if (scanf("%d", &id) != 1) {
                printf("Input gabim.\n");
                while (getchar() != '\n');
                return;
            }

            for (i = 0; i < count; i++) {
                if (students[i].id == id) {
                    printStudent(students[i]);
                    showWarning(students[i]);
                    found = 1;
                }
            }

            if (!found) {
                printf("Nuk u gjet asnje regjistrim me kete ID.\n");
            }
            break;

        case 2:
            printf("Shkruaj emrin: ");
            scanf(" %[^\n]", searchName);

            for (i = 0; i < count; i++) {
                if (strcmp(students[i].name, searchName) == 0) {
                    printStudent(students[i]);
                    showWarning(students[i]);
                    found = 1;
                }
            }

            if (!found) {
                printf("Nuk u gjet asnje regjistrim me kete emer.\n");
            }
            break;

        default:
            printf("Zgjedhje e pavlefshme.\n");
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
        printf("4. Update\n");
        printf("5. Kerko\n");
        printf("6. Dalje\n");
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
                findAndUpdate(students, count);
                break;
            case 5:
                searchStudent(students, count);
                break;
            case 6:
                printf("Bye\n");
                break;
            default:
                printf("Opsion i pavlefshem.\n");
        }

    } while (choice != 6);

    return 0;
}
