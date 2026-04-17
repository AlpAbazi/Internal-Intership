#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
} Status;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float progress;
    Status status;
} StudentRecord;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

const char* statusToString(Status status) {
    switch (status) {
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        default: return "Unknown";
    }
}


int chooseStatus(Status *status) {
    int choice;

    printf("Zgjidh statusin:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Zgjedhja juaj: ");

    if (scanf("%d", &choice) != 1) {
        printf("Input i pavlefshem per statusin.\n");
        clearInputBuffer();
        return 0;
    }

    switch (choice) {
        case 1:
            *status = NOT_STARTED;
            return 1;
        case 2:
            *status = IN_PROGRESS;
            return 1;
        case 3:
            *status = COMPLETED;
            return 1;
        default:
            printf("Status i pavlefshem. Zgjidh 1, 2 ose 3.\n");
            return 0;
    }
}

void addStudentRecord(StudentRecord students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nKapaciteti maksimal u arrit. Nuk mund te shtoni me shume regjistrime.\n");
        return;
    }

    StudentRecord newStudent;

    printf("\nVendos ID: ");
    if (scanf("%d", &newStudent.id) != 1) {
        printf("ID e pavlefshme.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Vendos emrin: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    if (strlen(newStudent.name) == 0) {
        printf("Emri nuk mund te jete bosh.\n");
        return;
    }

    printf("Vendos progresin (0 - 100): ");
    if (scanf("%f", &newStudent.progress) != 1) {
        printf("Progres i pavlefshem.\n");
        clearInputBuffer();
        return;
    }

    if (newStudent.progress < 0 || newStudent.progress > 100) {
        printf("Progresi duhet te jete nga 0 deri ne 100.\n");
        return;
    }

    if (!chooseStatus(&newStudent.status)) {
        return;
    }

    students[*count] = newStudent;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
}

void displayAllRecords(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime te ruajtura.\n");
        return;
    }

    printf("\n===== LISTA E REGJISTRIMEVE =====\n");
    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f%%\n", students[i].progress);
        printf("Statusi: %s\n", statusToString(students[i].status));
        printf("--------------------------\n");
    }
}

void showReport(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\n===== RAPORT ANALITIK =====\n");
        printf("Nuk ka regjistrime per analizim.\n");
        return;
    }

    int completedCount = 0;
    int inProgressCount = 0;
    int notStartedCount = 0;

    float sumProgress = 0;
    float highestProgress = students[0].progress;
    float lowestProgress = students[0].progress;

    for (int i = 0; i < count; i++) {
        sumProgress += students[i].progress;

        if (students[i].progress > highestProgress) {
            highestProgress = students[i].progress;
        }

        if (students[i].progress < lowestProgress) {
            lowestProgress = students[i].progress;
        }

        if (students[i].status == COMPLETED) {
            completedCount++;
        } else if (students[i].status == IN_PROGRESS) {
            inProgressCount++;
        } else {
            notStartedCount++;
        }
    }

    float averageProgress = sumProgress / count;

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Te perfunduara: %d\n", completedCount);
    printf("Ne progres: %d\n", inProgressCount);
    printf("Te pa filluara: %d\n", notStartedCount);
    printf("Mesatarja e progresit: %.2f%%\n", averageProgress);
    printf("Progresi me i larte: %.2f%%\n", highestProgress);
    printf("Progresi me i ulet: %.2f%%\n", lowestProgress);

    printf("\nKlasifikimi:\n");

    if (averageProgress >= 80) {
        printf("Performanca e pergjithshme eshte shume e mire.\n");
    } else if (averageProgress >= 50) {
        printf("Performanca e pergjithshme eshte mesatare.\n");
    } else {
        printf("Performanca e pergjithshme ka nevoje per permiresim.\n");
    }

    if (completedCount == count) {
        printf("Te gjitha regjistrimet jane te perfunduara.\n");
    } else if (completedCount == 0) {
        printf("Asnje regjistrim nuk eshte perfunduar ende.\n");
    } else {
        printf("Disa regjistrime jane perfunduar, por jo te gjitha.\n");
    }
}

int main() {
    StudentRecord students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha regjistrimet\n");
        printf("3. Shfaq raportin analitik\n");
        printf("4. Dil\n");
        printf("Zgjedhja juaj: ");

        if (scanf("%d", &choice) != 1) {
            printf("Zgjedhje e pavlefshme. Vendos nje numer.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudentRecord(students, &count);
                break;
            case 2:
                displayAllRecords(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                printf("Programi po mbyllet...\n");
                break;
            default:
                printf("Opsion i pavlefshem. Zgjidh 1, 2, 3 ose 4.\n");
        }

    } while (choice != 4);

    return 0;
}
