#include <stdio.h>
#include <string.h>

#define MAX 5

// enum për status
typedef enum {
    AKTIV = 1,
    NE_PROGRES,
    PERFUNDUAR
} Status;

// struct
struct Student {
    char name[50];
    float grade;
    Status status;
};

// funksion për status në tekst
const char* statusToString(Status s) {
    switch(s) {
        case AKTIV: return "Aktiv";
        case NE_PROGRES: return "Ne progres";
        case PERFUNDUAR: return "Perfunduar";
        default: return "I panjohur";
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
        printf("0. Dil\n");
        printf("Zgjedhja: ");

        if(scanf("%d", &choice) != 1) {
            printf("Input i pavlefshem.\n");
            while(getchar() != '\n'); // pastrim
            continue;
        }

        getchar(); // pastrim

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
                printf("1. Aktiv\n");
                printf("2. Ne progres\n");
                printf("3. Perfundoar\n");
                printf("Zgjedhja: ");

                if(scanf("%d", &statusChoice) != 1) {
                    printf("Status i pavlefshem.\n");
                    while(getchar() != '\n');
                    break;
                }

                switch(statusChoice) {
                    case 1:
                        students[count].status = AKTIV;
                        break;
                    case 2:
                        students[count].status = NE_PROGRES;
                        break;
                    case 3:
                        students[count].status = PERFUNDUAR;
                        break;
                    default:
                        printf("Status i pavlefshem.\n");
                        break;
                }

                count++;
                printf("Regjistrimi u shtua.\n");
                getchar(); // pastrim
                break;

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime.\n");
                } else {
                    printf("\n--- LISTA ---\n");
                    for(int i = 0; i < count; i++) {
                        printf("%d. Emri: %s | Nota: %.2f | Status: %s\n",
                               i + 1,
                               students[i].name,
                               students[i].grade,
                               statusToString(students[i].status));
                    }
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
