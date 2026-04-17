#include <stdio.h>
#include <string.h>

#define MAX 100

// ENUM per status
typedef enum {
    NEW = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

// Struktura
struct Student {
    int id;
    char name[50];
    float grade;
    Status status;
};

struct Student students[MAX];
int count = 0;

// ================= POINTER FUNCTION =================
void updateGrade(struct Student *s, float newGrade) {
    s->grade = newGrade;
}

// ================= ADD =================
void addStudent() {
    if (count >= MAX) {
        printf("Kapaciteti maksimal u arrit!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &students[count].id);

    printf("Emri: ");
    scanf("%s", students[count].name);

    printf("Nota: ");
    scanf("%f", &students[count].grade);

    int st;
    printf("Status (1=NEW, 2=IN_PROGRESS, 3=COMPLETED): ");
    scanf("%d", &st);

    if (st < 1 || st > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    students[count].status = st;
    count++;

    printf("Studenti u shtua me sukses!\n");
}

// ================= SHOW =================
void showStudents() {
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %.2f | %d\n",
            students[i].id,
            students[i].name,
            students[i].grade,
            students[i].status);
    }
}

// ================= REPORT =================
void report() {
    if (count == 0) {
        printf("Nuk ka te dhena per raport!\n");
        return;
    }

    float sum = 0, max = students[0].grade, min = students[0].grade;
    int completed = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].grade;

        if (students[i].grade > max) max = students[i].grade;
        if (students[i].grade < min) min = students[i].grade;

        if (students[i].status == COMPLETED) completed++;
    }

    printf("\n--- RAPORT ---\n");
    printf("Totali: %d\n", count);
    printf("Mesatarja: %.2f\n", sum / count);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);
    printf("Completed: %d\n", completed);

    if (sum / count >= 9)
        printf("Performanca: Shume e mire\n");
    else if (sum / count >= 7)
        printf("Performanca: Mesatare\n");
    else
        printf("Performanca: Dobet\n");
}

// ================= SEARCH =================
void searchStudent() {
    int id;
    printf("Shkruaj ID: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("U gjet: %s | %.2f\n", students[i].name, students[i].grade);

            // LOGJIKA ME IF/ELSE (paralajmerim)
            if (students[i].grade < 6)
                printf("Paralajmerim: Nota shume e ulet!\n");
            else if (students[i].grade < 8)
                printf("Ne rregull por mund te permiresohet\n");
            else
                printf("Shkelqyeshem!\n");

            found = 1;
        }
    }

    if (!found)
        printf("Nuk u gjet asnje student!\n");
}

// ================= POINTER UPDATE =================
void changeGrade() {
    int id;
    printf("Shkruaj ID per ndryshim: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            float newGrade;
            printf("Nota e re: ");
            scanf("%f", &newGrade);

            // POINTER CALL
            updateGrade(&students[i], newGrade);

            printf("Nota u ndryshua me sukses!\n");
            return;
        }
    }

    printf("Studenti nuk u gjet!\n");
}

// ================= MENU =================
int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto student\n");
        printf("2. Shfaq studentet\n");
        printf("3. Raport\n");
        printf("4. Kerko student\n");
        printf("5. Ndrysho noten (pointer)\n");
        printf("0. Exit\n");

        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: report(); break;
            case 4: searchStudent(); break;
            case 5: changeGrade(); break;
            case 0: printf("Dalje...\n"); break;
            default: printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 0);

    return 0;
}
