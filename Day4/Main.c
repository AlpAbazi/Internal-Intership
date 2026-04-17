#include <stdio.h>
#include <string.h>

#define MAX 100

// ENUM
typedef enum {
    NEW = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

// STRUCT
struct Student {
    int id;
    char name[50];
    float grade;
    Status status;
};

struct Student students[MAX];
int count = 0;

// ADD
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

    printf("Studenti u shtua!\n");
}

// SHOW
void showStudents() {
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return;
    }

    printf("\n--- LISTA E STUDENTEVE ---\n");

    for (int i = 0; i < count; i++) {
        char *statusText;

        switch (students[i].status) {
            case NEW: statusText = "NEW"; break;
            case IN_PROGRESS: statusText = "IN_PROGRESS"; break;
            case COMPLETED: statusText = "COMPLETED"; break;
        }

        printf("%d | %s | %.2f | %s\n",
               students[i].id,
               students[i].name,
               students[i].grade,
               statusText);
    }
}

// REPORT
void report() {
    if (count == 0) {
        printf("Nuk ka te dhena per raport!\n");
        return;
    }

    float sum = 0, max = students[0].grade, min = students[0].grade;

    for (int i = 0; i < count; i++) {
        sum += students[i].grade;

        if (students[i].grade > max) max = students[i].grade;
        if (students[i].grade < min) min = students[i].grade;
    }

    float avg = sum / count;

    printf("\n--- RAPORT ---\n");
    printf("Total: %d\n", count);
    printf("Mesatarja: %.2f\n", avg);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);

    if (avg >= 9)
        printf("Performancë shumë e mirë\n");
    else if (avg >= 7)
        printf("Performancë mesatare\n");
    else
        printf("Performancë e dobët\n");
}

// SEARCH
void searchStudent() {
    int id;
    printf("Shkruaj ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("U gjet: %s | %.2f\n",
                   students[i].name,
                   students[i].grade);

            if (students[i].grade < 6)
                printf("Paralajmerim: Nota e ulet!\n");
            else
                printf("Rezultat i mire\n");

            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// POINTER UPDATE
void updateGrade() {
    int id;
    printf("ID per ndryshim note: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            float *p = &students[i].grade;

            printf("Nota e re: ");
            scanf("%f", p);

            printf("Nota u ndryshua me pointer!\n");
            return;
        }
    }

    printf("Studenti nuk u gjet!\n");
}

// SORT
void sortStudents() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].grade < students[j].grade) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("U renditen studentet!\n");
}

// UPDATE
void updateStudent() {
    int id;
    printf("ID per update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            printf("Emri i ri: ");
            scanf("%s", students[i].name);

            int st;
            printf("Status i ri (1-3): ");
            scanf("%d", &st);

            if (st < 1 || st > 3) {
                printf("Status gabim!\n");
                return;
            }

            students[i].status = st;

            printf("U perditesua!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// DELETE
void deleteStudent() {
    int id;
    printf("ID per fshirje: ");
    scanf("%d", &id);

    int found = -1;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Nuk u gjet!\n");
        return;
    }

    for (int i = found; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;
    printf("U fshi studenti!\n");
}

// MAIN
int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Add\n");
        printf("2. Show\n");
        printf("3. Report\n");
        printf("4. Search\n");
        printf("5. Update grade (pointer)\n");
        printf("6. Sort\n");
        printf("7. Update student\n");
        printf("8. Delete student\n");
        printf("0. Exit\n");

        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: report(); break;
            case 4: searchStudent(); break;
            case 5: updateGrade(); break;
            case 6: sortStudents(); break;
            case 7: updateStudent(); break;
            case 8: deleteStudent(); break;
            case 0: printf("Dalje...\n"); break;
            default: printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 0);

    return 0;
}
