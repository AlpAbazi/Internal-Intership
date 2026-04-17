#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50

typedef enum {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef enum {
    CATEGORY_UNKNOWN,
    FRESHMAN,
    SOPHOMORE,
    JUNIOR,
    SENIOR
} Category;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float progress;
    Status status;
    Category category;
} StudentRecord;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int readInt(const char *prompt, int *value) {
    printf("%s", prompt);
    if (scanf("%d", value) != 1) {
        printf("Input i pavlefshëm. Ju lutem vendosni një numer të vlefshëm.\n");
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

int readFloat(const char *prompt, float *value) {
    printf("%s", prompt);
    if (scanf("%f", value) != 1) {
        printf("Input i pavlefshëm. Ju lutem vendosni një numër valid.\n");
        clearInputBuffer();
        return 0;
    }
    clearInputBuffer();
    return 1;
}

const char* statusToString(Status status) {
    switch (status) {
        case NOT_STARTED: return "Not Started";
        case IN_PROGRESS: return "In Progress";
        case COMPLETED: return "Completed";
        default: return "Unknown";
    }
}

const char* categoryToString(Category category) {
    switch (category) {
        case FRESHMAN: return "Freshman";
        case SOPHOMORE: return "Sophomore";
        case JUNIOR: return "Junior";
        case SENIOR: return "Senior";
        default: return "Unknown";
    }
}

Category selectCategory(void) {
    int categoryChoice;
    Category category = CATEGORY_UNKNOWN;

    do {
        printf("\nZgjidh kategorine e studentit:\n");
        printf("1. Freshman\n");
        printf("2. Sophomore\n");
        printf("3. Junior\n");
        printf("4. Senior\n");

        if (!readInt("Zgjedhja juaj: ", &categoryChoice)) {
            continue;
        }

        switch (categoryChoice) {
            case 1:
                category = FRESHMAN;
                break;
            case 2:
                category = SOPHOMORE;
                break;
            case 3:
                category = JUNIOR;
                break;
            case 4:
                category = SENIOR;
                break;
            default:
                printf("Opsion i pavlefshëm për kategorinë. Provoni përsëri.\n");
                category = CATEGORY_UNKNOWN;
                break;
        }
    } while (category == CATEGORY_UNKNOWN);

    return category;
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
        printf("\nNuk mund të shtoni më shumë regjistrime. Kapaciteti maksimal u arrit.\n");
        return;
    }

    StudentRecord newStudent = {0};

    if (!readInt("\nVendos ID: ", &newStudent.id)) {
        return;
    }

    printf("Vendos emrin: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    if (strlen(newStudent.name) == 0) {
        printf("Emri nuk mund të jetë bosh.\n");
        return;
    }

    if (!readFloat("Vendos progresin (0 - 100): ", &newStudent.progress)) {
        return;
    }

    if (newStudent.progress < 0 || newStudent.progress > 100) {
        printf("Progresi duhet të jetë nga 0 deri në 100.\n");
        return;
    }

    newStudent.category = selectCategory();
    updateStatusByProgress(&newStudent);

    students[*count] = newStudent;
    (*count)++;

    printf("Regjistrimi u shtua me sukses.\n");
    printf("Statusi: %s | Kategoria: %s\n", statusToString(newStudent.status), categoryToString(newStudent.category));
    printf("Regjistrime aktuale: %d / %d\n", *count, MAX_STUDENTS);
}

void displayAllRecords(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\nNuk ka asnjë regjistrim të ruajtur.\n");
        return;
    }

    printf("\n===== TË GJITHA REGJISTRIMET =====\n");
    printf("Regjistrime aktuale: %d / %d\n\n", count, MAX_STUDENTS);

    for (int i = 0; i < count; i++) {
        printf("Regjistrimi #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Emri: %s\n", students[i].name);
        printf("Progresi: %.2f%%\n", students[i].progress);
        printf("Statusi: %s\n", statusToString(students[i].status));
        printf("Kategoria: %s\n", categoryToString(students[i].category));
        printf("--------------------------\n");
    }
}

int main(void) {
    StudentRecord students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq të gjitha regjistrimet\n");
        printf("3. Dil\n");

        if (!readInt("Zgjedhja juaj: ", &choice)) {
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
                return 0;
            default:
                printf("Opsion i pavlefshëm. Provoni përsëri.\n");
                break;
        }
    }
}
