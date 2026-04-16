#include <stdio.h>

enum TaskStatus {
    TODO = 1,
    IN_PROGRESS,
    DONE,
    CANCELLED
};

int main() {
    int choice;
    int validCount = 0;
    int invalidCount = 0;


    for (int i = 0; i < 3; i++) {

        printf("\n=== ZGJEDH STATUSIN E DETYRES ===\n");
        printf("1. TODO\n");
        printf("2. IN PROGRESS\n");
        printf("3. DONE\n");
        printf("4. CANCELLED\n");

        printf("Shkruaj zgjedhjen (1-4): ");
        scanf("%d", &choice);

        enum TaskStatus status = (enum TaskStatus)choice;

        switch (status) {
            case TODO:
                printf("Detyra eshte ende per t'u filluar.\n");
                validCount++;
                break;

            case IN_PROGRESS:
                printf("Detyra eshte ne proces.\n");
                validCount++;
                break;

            case DONE:
                printf("Detyra eshte perfunduar me sukses.\n");
                validCount++;
                break;

            case CANCELLED:
                printf("Detyra eshte anuluar.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
                break;
        }
    }

    printf("\n=== STATISTIKA PERFUNDIMTARE ===\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}