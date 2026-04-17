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

void printAnalyticsReport(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\nNuk ka të dhëna për raport. Shtoni së paku një regjistrim për të parë analizën.\n");
        return;
    }

    int completedCount = 0;
    float totalProgress = 0.0f;
    float minProgress = students[0].progress;
    float maxProgress = students[0].progress;
    int categoryCounts[5] = {0};

    for (int i = 0; i < count; i++) {
        float progress = students[i].progress;
        totalProgress += progress;

        if (progress < minProgress) {
            minProgress = progress;
        }

        if (progress > maxProgress) {
            maxProgress = progress;
        }

        if (students[i].status == COMPLETED) {
            completedCount++;
        }

        if (students[i].category >= FRESHMAN && students[i].category <= SENIOR) {
            categoryCounts[students[i].category]++;
        }
    }

    float averageProgress = totalProgress / count;
    const char *classMessage;

    if (averageProgress >= 90.0f) {
        classMessage = "Rezultati i përgjithshëm është shumë i lartë dhe grupi duket shumë i suksesshëm.";
    } else if (averageProgress >= 70.0f) {
        classMessage = "Progresi mesatar është i mirë, por ka vend për përmirësim.";
    } else if (averageProgress >= 40.0f) {
        classMessage = "Grupi është në proces përmirësimi; vlerësoni mbështetjen dhe ndjekjen.";
    } else {
        classMessage = "Progresi mesatar është i ulët. Duhet të fokusohet më shumë tek përfundimi i detyrave.";
    }

    printf("\n===== RAPORT ANALITIK =====\n");
    printf("Numri total i regjistrimeve: %d\n", count);
    printf("Numri i regjistrimeve të përfunduara: %d\n", completedCount);
    printf("Progresi mesatar: %.2f%%\n", averageProgress);
    printf("Progresi më i ulët: %.2f%%\n", minProgress);
    printf("Progresi më i lartë: %.2f%%\n", maxProgress);
    printf("\nKlasifikimi: %s\n", classMessage);

    if (completedCount == count) {
        printf("Të gjitha regjistrimet janë përfunduara.");
    } else if (completedCount == 0) {
        printf("Asnjë regjistrim nuk është përfunduar ende.");
    } else {
        printf("Ka %d regjistrime të përfunduara dhe %d që janë ende në proces.", completedCount, count - completedCount);
    }

    printf("\n\nShpërndarja sipas kategorive:\n");
    printf(" - Freshman: %d\n", categoryCounts[FRESHMAN]);
    printf(" - Sophomore: %d\n", categoryCounts[SOPHOMORE]);
    printf(" - Junior: %d\n", categoryCounts[JUNIOR]);
    printf(" - Senior: %d\n", categoryCounts[SENIOR]);
}

const char* buildSearchAdvice(const StudentRecord *student) {
    if (student->status == NOT_STARTED && student->progress == 0.0f) {
        return "Nuk ka filluar ende. Duhet të filloni menjëherë procesin e mësimit.";
    }

    if (student->status == IN_PROGRESS && student->progress < 30.0f) {
        return "Progresi është shumë i ulët dhe po ngadalësohet rëndësishëm. Konsideroni mbështetje të shtuar.";
    }

    if (student->status == IN_PROGRESS && student->progress >= 30.0f && student->progress < 70.0f) {
        return "Ka përparim, por duhet të intensifikoni punën për të përfunduar në kohë.";
    }

    if (student->status == IN_PROGRESS && student->progress >= 70.0f) {
        return "Po shkoni mirë. Ruani ritmin dhe përqendrimin deri në përfundim.";
    }

    if (student->status == COMPLETED && student->progress >= 100.0f) {
        if (student->category == SENIOR) {
            return "Regjistrimi është përfunduar mirë. Student senior mund të konsiderojë projekte kërkimore shtesë.";
        }
        return "Regjistrimi është përfunduar plotësisht. Vazhdoni të ruani performancë të lartë.";
    }

    return "Ky regjistrim ka një kombinim interesant vlerash. Shikoni detajet për të vendosur hapat e ardhshëm.";
}

void printRecordWithAdvice(const StudentRecord *student) {
    printf("\n=== Regjistrimi i gjetur ===\n");
    printf("ID: %d\n", student->id);
    printf("Emri: %s\n", student->name);
    printf("Progresi: %.2f%%\n", student->progress);
    printf("Statusi: %s\n", statusToString(student->status));
    printf("Kategoria: %s\n", categoryToString(student->category));
    printf("Paralajmërimi: %s\n", buildSearchAdvice(student));
}

int stringContainsIgnoreCase(const char *text, const char *pattern) {
    return strcasestr(text, pattern) != NULL;
}

void searchRecords(StudentRecord students[], int count) {
    if (count == 0) {
        printf("\nNuk ka regjistrime për të kërkuar. Shtoni së paku një regjistrim.");
        return;
    }

    int searchChoice;
    char searchName[NAME_LENGTH];
    int searchId;
    int found = 0;

    printf("\nZgjidhni mënyrën e kërkimit:\n");
    printf("1. Kërko sipas ID-së\n");
    printf("2. Kërko sipas emrit\n");

    if (!readInt("Zgjedhja juaj: ", &searchChoice)) {
        return;
    }

    switch (searchChoice) {
        case 1:
            if (!readInt("Vendosni ID-në për kërkim: ", &searchId)) {
                return;
            }

            for (int i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    printRecordWithAdvice(&students[i]);
                    found = 1;
                    break;
                }
            }
            break;

        case 2:
            printf("Vendosni emrin ose pjesën e tij për kërkim: ");
            fgets(searchName, NAME_LENGTH, stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            if (strlen(searchName) == 0) {
                printf("Emri i kërkuar nuk mund të jetë bosh.\n");
                return;
            }

            for (int i = 0; i < count; i++) {
                if (stringContainsIgnoreCase(students[i].name, searchName)) {
                    printRecordWithAdvice(&students[i]);
                    found = 1;
                }
            }
            break;

        default:
            printf("Opsion i pavlefshëm për kërkim. Provoni përsëri.\n");
            return;
    }

    if (!found) {
        printf("\nNuk u gjet asnjë regjistrim që përputhet me kriteret e kërkimit.\n");
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
        printf("3. Kërko regjistrim\n");
        printf("4. Raport analitik\n");
        printf("5. Dil\n");

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
                searchRecords(students, count);
                break;
            case 4:
                printAnalyticsReport(students, count);
                break;
            case 5:
                printf("Programi po mbyllet...\n");
                return 0;
            default:
                printf("Opsion i pavlefshëm. Provoni përsëri.\n");
                break;
        }
    }
}
