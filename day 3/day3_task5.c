#include <stdio.h>

// Krijimi i enum
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int valid = 0, invalid = 0;

    // Përsëritje për 3 raste
    for(int i = 1; i <= 3; i++) {
        printf("\nZgjedh nivelin (1-4):\n");
        printf("1. Beginner\n2. Intermediate\n3. Advanced\n4. Expert\n");
        printf("Zgjedhja %d: ", i);
        scanf("%d", &choice);

        switch(choice) {
            case BEGINNER:
                printf("Ju jeni fillestar.\n");
                valid++;
                break;
            case INTERMEDIATE:
                printf("Ju jeni ne nivel mesatar.\n");
                valid++;
                break;
            case ADVANCED:
                printf("Ju jeni ne nivel te avancuar.\n");
                valid++;
                break;
            case EXPERT:
                printf("Ju jeni ekspert.\n");
                valid++;
                break;
            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalid++;
        }
    }

    // Statistikat
    printf("\n--- Statistikat ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje te pavlefshme: %d\n", invalid);

    return 0;
}
