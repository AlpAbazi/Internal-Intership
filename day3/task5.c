#include <stdio.h>

// Enum me 4 nivele
enum Level {BEGINNER = 1, INTERMEDIATE, ADVANCED, EXPERT};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    // 3 raste testimi
    for(int i = 1; i <= 3; i++) {

        printf("\nZgjedh nivelin (1-4): ");
        scanf("%d", &choice);

        enum Level level = choice;

        switch(level) {
            case BEGINNER:
                printf("Nivel fillestar\n");
                validCount++;
                break;
            case INTERMEDIATE:
                printf("Nivel mesatar\n");
                validCount++;
                break;
            case ADVANCED:
                printf("Nivel i avancuar\n");
                validCount++;
                break;
            case EXPERT:
                printf("Nivel ekspert\n");
                validCount++;
                break;
            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
        }
    }

    // Statistikat
    printf("\n--- STATISTIKAT ---\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje jo valide: %d\n", invalidCount);

    return 0;
}
