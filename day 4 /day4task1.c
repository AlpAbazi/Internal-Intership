#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
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

void updateStatusByProgress(StudentRecord *student) {
    if (student->progress <= 0) {
        student->status = NOT_STARTED;
    } else if (student->progress < 100) {
        student->status = IN_PROGRESS;
    } else {
        student->status = COMPLETED;
    }
}

void addStudentRecord(StudentRecord students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nNuk mund te shtoni me shume regjistrime. Kapaciteti maksimal u arrit.\n");
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

    updateStatusByProgress(&newStudent);

    students[*count] = newStudent;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Regjistrime aktuale: %d / %d\n", *count, MAX_STUDENTS);
}

void displayAllRecords(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\nNuk ka asnje regjistrim te ruajtur.\n");
        return;
    }

    printf("\n===== TE GJITHA REGJISTRIMET =====\n");
    printf("Regjistrime aktuale: %d / %d\n\n", count, MAX_STUDENTS);

    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f%%\n", students[i].progress);
        printf("Statusi: %s\n", statusToString(students[i].status));
        printf("--------------------------\n");
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
        printf("3. Dil\n");
        printf("Zgjedhja juaj: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ju lutem vendosni nje numer valid.\n");
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
                printf("Programi po mbyllet...\n");
                break;
            default:
                printf("Opsion i pavlefshem. Provoni perseri.\n");
        }

    } while (choice != 3);

    return 0;
}
