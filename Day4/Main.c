#include <stdio.h>
#include <string.h>

#define MAX 5

typedef enum {
    AKTIV = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

struct Student {
    int id;
    char name[50];
    float grade;
    Status status;
};

const char* statusToString(Status s) {
    switch(s) {
        case AKTIV: return "Aktiv";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduar";
        default: return "I panjohur";
    }
}

// kërkimi
void search(struct Student students[], int count, int id) {

    int found = 0;

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {

            found = 1;

            printf("\n--- REZULTATI U GJET ---\n");
            printf("ID: %d\n", students[i].id);
            printf("Emri: %s\n", students[i].name);
            printf("Nota: %.2f\n", students[i].grade);
            printf("Status: %s\n", statusToString(students[i].status));

            // logjikë paralajmëruese
            printf("\n--- ANALIZA ---\n");

            if(students[i].grade >= 9 && students[i].status == PERFUNDUAR) {
                printf("Shume mire. Performanca shume e larte.\n");
            } 
            else if(students[i].grade >= 7 && students[i].status == NE_PROGRES) {
                printf("Mire, por duhet me e perfundu punen.\n");
            } 
            else if(students[i].grade < 6) {
                printf("Paralajmerim: rezultat i dobet.\n");
            } 
            else {
                printf("Gjendje normale.\n");
            }
        }
    }

    if(!found) {
        printf("\nNuk u gjet asnje regjistrim me kete ID.\n");
    }
}

int main() {

    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq te gjitha\n");
        printf("3. Kerko sipas ID\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");

        if(scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("Kufiri maksimal u arrit.\n");
                    break;
                }

                printf("ID: ");
                scanf("%d", &students[count].id);

                printf("Emri: ");
                getchar();
                fgets(students[count].name, 50, stdin);
                students[count].name[strcspn(students[count].name, "\n")] = 0;

                printf("Nota: ");
                scanf("%f", &students[count].grade);

                int st;

                printf("Status (1-Aktiv,2-Ne progres,3-Perfunduar): ");
                scanf("%d", &st);

                switch(st) {
                    case 1: students[count].status = AKTIV; break;
                    case 2: students[count].status = NE_PROGRES; break;
                    case 3: students[count].status = PERFUNDUAR; break;
                    default:
                        printf("Status i pavlefshem, vendoset default.\n");
                        students[count].status = AKTIV;
                }

                count++;
                printf("Regjistrimi u shtua.\n");
                break;

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime.\n");
                } else {
                    for(int i = 0; i < count; i++) {
                        printf("%d | %s | %.2f | %s\n",
                               students[i].id,
                               students[i].name,
                               students[i].grade,
                               statusToString(students[i].status));
                    }
                }
                break;

            case 3:
                {
                    int id;
                    printf("Shkruaj ID per kerkim: ");
                    scanf("%d", &id);
                    search(students, count, id);
                }
                break;

            case 0:
                printf("Programi u mbyll.\n");
                break;

            default:
                printf("Zgjedhje e pavlefshme.\n");
        }

    } while(choice != 0);

    return 0;
}
