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
            printf("Not Started");
            break;
        case IN_PROGRESS:
            printf("In Progress");
            break;
        case COMPLETED:
            printf("Completed");
            break;
        default:
            printf("Unknown");
    }
}

void printStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Emri: %s\n", s.name);
    printf("Progresi: %.2f\n", s.progress);
    printf("Statusi: ");
    printStatus(s.status);
    printf("\n");
}

void showWarning(struct Student s) {
    printf("Vleresim: ");

    if (s.progress < 40 && s.status != COMPLETED) {
        printf("Paralajmerim - progres i ulet dhe nuk eshte perfunduar.\n");
    } else if (s.progress >= 40 && s.progress < 70 && s.status == IN_PROGRESS) {
        printf("Ka progres mesatar, duhet me shume pune.\n");
    } else if (s.progress == 100 && s.status == COMPLETED) {
        printf("Shkelqyeshem - regjistrimi eshte perfunduar me sukses.\n");
    } else if (s.progress > 70 && s.status == NOT_STARTED) {
        printf("Ka mospërputhje - progres i larte por statusi Not Started.\n");
    } else if (s.progress == 0 && s.status == COMPLETED) {
        printf("Ka mospërputhje - progresi 0 por statusi Completed.\n");
    } else {
        printf("Regjistrimi duket ne gjendje normale.\n");
    }
}

void addStudent(struct Student students[], int *count) {
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("\nNuk mund te shtohen me shume regjistrime. Maksimumi u arrit.\n");
        return;
    }

    printf("\nShkruaj ID: ");
    if (scanf("%d", &students[*count].id) != 1) {
        printf("Input gabim.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Shkruaj emrin: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Shkruaj progresin (0-100): ");
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
    printf("Regjistrimi u shtua me sukses.\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\n===== TE GJITHA REGJISTRIMET =====\n");

    for (i = 0; i < count; i++) {
        printf("\nRegjistrimi %d\n", i + 1);
        printStudent(students[i]);
    }
}

void updateStudent(struct Student *s) {
    float newProgress;

    printf("Shkruaj progresin e ri (0-100): ");
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

    printf("Regjistrimi u perditesua me sukses.\n");
}

void findAndUpdate(struct Student students[], int count) {
    int id, i, found = 0;

    if (count == 0) {
        printf("\nNuk ka regjistrime.\n");
        return;
    }

    printf("Shkruaj ID per perditesim: ");
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
        printf("Nuk u gjet regjistrim me kete ID.\n");
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
        printf("\n===== RAPORTI =====\n");
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

    printf("\n===== RAPORTI =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i perfunduara: %d\n", completed);
    printf("Mesatarja e progresit: %.2f\n", average);
    printf("Progresi me i larte: %.2f\n", max);
    printf("Progresi me i ulet: %.2f\n", min);

    if (average >= 80) {
        printf("Klasifikimi: Progres shume i mire.\n");
    } else if (average >= 50) {
        printf("Klasifikimi: Progres mesatar.\n");
    } else {
        printf("Klasifikimi: Progres i ulet.\n");
    }
}

void searchStudent(struct Student students[], int count) {
    int choice;
    int id;
    int i;
    int found = 0;
    char searchName[50];

    if (count == 0) {
        printf("\nNuk ka regjistrime.\n");
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
                    printf("\n===== REZULTATI =====\n");
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
                    printf("\n===== REZULTATI =====\n");
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

void sortByProgress(struct Student students[], int count) {
    int i, j;
    struct Student temp;

    if (count == 0) {
        printf("\nNuk ka regjistrime per renditje.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - 1 - i; j++) {
            if (students[j].progress < students[j + 1].progress) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n===== RANKIMI SIPAS PROGRESIT =====\n");

    for (i = 0; i < count; i++) {
        printf("\nRenditja #%d\n", i + 1);
        printStudent(students[i]);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n=================================\n");
        printf("   STUDENT PROGRESS TRACKER\n");
        printf("=================================\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Raporti analitik\n");
        printf("4. Perditeso progresin\n");
        printf("5. Kerko regjistrim\n");
        printf("6. Rendit sipas progresit\n");
        printf("7. Dalje\n");
        printf("Zgjedh opsionin: ");

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
                sortByProgress(students, count);
                break;
            case 7:
                printf("Programi u mbyll.\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provo perseri.\n");
        }

    } while (choice != 7);

    return 0;
}
