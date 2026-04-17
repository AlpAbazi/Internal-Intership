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

// ================= CHECK =================
int isEmpty() {
    if (count == 0) {
        printf("Nuk ka te dhena!\n");
        return 1;
    }
    return 0;
}

// ================= MENU =================
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

    int s;
    printf("Status (1-InProgress, 2-Completed, 3-Failed): ");
    scanf("%d", &s);

    if (s < 1 || s > 3) {
        printf("Status i pavlefshem!\n");
        return;
    }

    students[count].status = (Status)s;
    count++;

    printf("U shtua me sukses!\n");
}

// ================= SHOW =================
void showStudents() {
    if (isEmpty()) return;

    printf("\nID   Emri        Nota   Status\n");
    printf("---------------------------------\n");

    for (int i = 0; i < count; i++) {

        char *statusText;

        switch (students[i].status) {
            case IN_PROGRESS: statusText = "IN_PROGRESS"; break;
            case COMPLETED: statusText = "COMPLETED"; break;
            case FAILED: statusText = "FAILED"; break;
            default: statusText = "UNKNOWN";
        }

        printf("%d   %s        %.2f   %s\n",
               students[i].id,
               students[i].name,
               students[i].grade,
               statusText);
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

            printf("\nU GJET:\n");
            printf("Emri: %s\n", students[i].name);
            printf("Nota: %.2f\n", students[i].grade);

            if (students[i].grade < 5)
                printf("Paralajmerim: rezultat i dobet!\n");
            else if (students[i].grade >= 9)
                printf("Shkelqyeshem!\n");
            else
                printf("Rezultat normal.\n");

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

            int s;
            printf("Status i ri (1-3): ");
            scanf("%d", &s);

            if (s >= 1 && s <= 3)
                students[i].status = (Status)s;
            else
                printf("Status i pavlefshem, nuk u ndryshua!\n");

            printf("U perditesua me sukses!\n");
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
            printf("U fshi me sukses!\n");
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

    printf("U renditen studentet!\n");
}

// ================= REPORT =================
void generateReport() {
    if (isEmpty()) return;

    float sum = 0, max = students[0].grade;
    int completed = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].grade;

        if (students[i].grade > max)
            max = students[i].grade;

        if (students[i].status == COMPLETED)
            completed++;
    }

    printf("\n--- RAPORT ---\n");
    printf("Total: %d\n", count);
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
            case 0: printf("Dalje...\n"); break;
            default: printf("Zgjedhje e pavlefshme!\n");
        }

    } while (choice != 0);

    return 0;
}
