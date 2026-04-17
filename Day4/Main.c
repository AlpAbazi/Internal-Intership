#include <stdio.h>
#include <string.h>

#define MAX 5

typedef enum {
    AKTIV = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

struct Student {
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

// funksion për raport
void raport(struct Student students[], int count) {

    if(count == 0) {
        printf("\nNuk ka te dhena per raport.\n");
        return;
    }

    int completed = 0;
    float sum = 0;
    float max = students[0].grade;
    float min = students[0].grade;

    for(int i = 0; i < count; i++) {

        sum += students[i].grade;

        if(students[i].status == PERFUNDUAR) {
            completed++;
        }

        if(students[i].grade > max) {
            max = students[i].grade;
        }

        if(students[i].grade < min) {
            min = students[i].grade;
        }
    }

    float avg = sum / count;

    printf("\n--- RAPORT ---\n");
    printf("Totali i regjistrimeve: %d\n", count);
    printf("Te perfunduara: %d\n", completed);
    printf("Mesatarja: %.2f\n", avg);
    printf("Nota me e larte: %.2f\n", max);
    printf("Nota me e ulet: %.2f\n", min);

    // klasifikim
    if(avg >= 9) {
        printf("Vleresim: Shume mire\n");
    } else if(avg >= 7) {
        printf("Vleresim: Mire\n");
    } else if(avg >= 5) {
        printf("Vleresim: Mesatare\n");
    } else {
        printf("Vleresim: Dobet\n");
    }
}

int main() {

    struct Student students[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Shto regjistrim\n");
        printf("2. Shfaq regjistrimet\n");
        printf("3. Raport analitik\n");
        printf("0. Dil\n");
        printf("Zgjedhja: ");

        if(scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem.\n");
            while(getchar() != '\n');
            continue;
        }

        getchar();

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("Kufiri maksimal u arrit.\n");
                    break;
                }

                printf("Emri: ");
                fgets(students[count].name, 50, stdin);
                students[count].name[strcspn(students[count].name, "\n")] = 0;

                printf("Nota: ");
                if(scanf("%f", &students[count].grade) != 1) {
                    printf("Nota e pavlefshme.\n");
                    while(getchar() != '\n');
                    break;
                }

                int statusChoice;

                printf("Zgjedh statusin:\n");
                printf("1. Aktiv\n2. Ne progres\n3. Perfunduar\n");
                printf("Zgjedhja: ");

                if(scanf("%d", &statusChoice) != 1) {
                    printf("Status i pavlefshem.\n");
                    while(getchar() != '\n');
                    break;
                }

                switch(statusChoice) {
                    case 1: students[count].status = AKTIV; break;
                    case 2: students[count].status = NE_PROGRES; break;
                    case 3: students[count].status = PERFUNDUAR; break;
                    default:
                        printf("Status i pavlefshem.\n");
                        break;
                }

                count++;
                printf("Regjistrimi u shtua.\n");
                getchar();
                break;

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime.\n");
                } else {
                    printf("\n--- LISTA ---\n");
                    for(int i = 0; i < count; i++) {
                        printf("%d. %s | %.2f | %s\n",
                               i + 1,
                               students[i].name,
                               students[i].grade,
                               statusToString(students[i].status));
                    }
                }
                break;

            case 3:
                raport(students, count);
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
