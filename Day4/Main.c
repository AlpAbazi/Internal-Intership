#include <stdio.h>
int main()
{
   // struktura për student
struct Student {
    char name[50];
    float grade;
};

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
        scanf("%d", &choice);
        getchar(); // pastron buffer

        switch(choice) {

            case 1:
                if(count >= MAX) {
                    printf("Kufiri maksimal u arrit. Nuk mund te shtosh me.\n");
                    break;
                }

                printf("Emri: ");
                fgets(students[count].name, 50, stdin);
                students[count].name[strcspn(students[count].name, "\n")] = 0;

                printf("Nota: ");
                scanf("%f", &students[count].grade);

                count++;

                printf("Regjistrimi u shtua.\n");
                break;

            case 2:
                if(count == 0) {
                    printf("Nuk ka regjistrime.\n");
                } else {
                    printf("\n--- LISTA ---\n");
                    for(int i = 0; i < count; i++) {
                        printf("%d. Emri: %s | Nota: %.2f\n",
                               i + 1,
                               students[i].name,
                               students[i].grade);
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
}