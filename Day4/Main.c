#include <stdio.h>
#include <string.h>

#define MAX 50

typedef enum {
    IN_PROGRESS = 1,
    COMPLETED,
    FAILED
} Status;

typedef struct {
    int id;
    char name[50];
    float grade;
    Status status;
} Student;

Student students[MAX];
int count = 0;

// ================= HELPERS =================
int isEmpty() {
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return 1;
    }
    return 0;
}

void printMenu() {
    printf("\n============================\n");
    printf("1. Shto student\n");
    printf("2. Shfaq studentet\n");
    printf("3. Kerko student\n");
    printf("4. Update student\n");
    printf("5. Fshij student\n");
    printf("6. Rendit sipas notes\n");
    printf("7. Raport\n");
    printf("0. Exit\n");
    printf("============================\n");
}

// ================= ADD =================
void addStudent() {
    if (count >= MAX) {
        printf("Kapaciteti i plote!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &students[count].id);

    printf("Emri: ");
    scanf("%s", students[count].name);

    printf("Nota: ");
    scanf("%f", &students[count].grade);

    printf("Status (1-InProgress, 2-Completed, 3-Failed): ");
    int s;
    scanf("%d", &s);

    if (s < 1 || s > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    students[count].status = s;
    count++;

    printf("U shtua me sukses!\n");
}

// ================= SHOW =================
void showStudents() {
    if (isEmpty()) return;

    printf("\nID   Emri        Nota   Status\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d   %s        %.2f   %d\n",
               students[i].id,
               students[i].name,
               students[i].grade,
               students[i].status);
    }
}

// ================= SEARCH =================
void searchStudent() {
    if (isEmpty()) return;

    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("U gjet: %s %.2f\n",
                   students[i].name,
                   students[i].grade);

            if (students[i].grade < 2.0)
                printf("Paralajmerim: Nota e ulet!\n");
            else if (students[i].grade > 4.0)
                printf("Shkelqyeshem!\n");

            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// ================= UPDATE =================
void updateStudent() {
    if (isEmpty()) return;

    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            printf("Emri i ri: ");
            scanf("%s", students[i].name);

            printf("Status i ri (1-3): ");
            int s;
            scanf("%d", &s);

            if (s >= 1 && s <= 3)
                students[i].status = s;

            printf("U perditesua!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// ================= DELETE =================
void deleteStudent() {
    if (isEmpty()) return;

    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("U fshi!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// ================= SORT =================
void sortStudents() {
    if (isEmpty()) return;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].grade < students[j].grade) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("U renditen!\n");
}

// ================= REPORT =================
void generateReport() {
    if (isEmpty()) return;

    int completed = 0;
    float sum = 0, max = students[0].grade;

    for (int i = 0; i < count; i++) {
        sum += students[i].grade;

        if (students[i].status == COMPLETED)
            completed++;

        if (students[i].grade > max)
            max = students[i].grade;
    }

    printf("\nTotal: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Mesatarja: %.2f\n", sum / count);
    printf("Max: %.2f\n", max);
}

// ================= MAIN =================
int main() {
    int choice;

    do {
        printMenu();
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudents(); break;
            case 7: generateReport(); break;
        }

    } while (choice != 0);

    return 0;
}
