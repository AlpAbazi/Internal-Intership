#include <stdio.h>

// Krijimi i enum me 4 vlera
typedef enum {
    BEGJINOR = 1,
    MESATAR,
    AVANCUAR,
    EKSPERT
} Nivel;

int main() {
    int zgjedhja;
    int i;

    int validCount = 0;
    int invalidCount = 0;

    // Loop për 3 raste testimi (3 përdorues)
    for (i = 1; i <= 3; i++) {

        printf("\n--- Rasti %d ---\n", i);
        printf("Zgjidh nivelin e nxënësit:\n");
        printf("1. Fillestar\n");
        printf("2. Mesatar\n");
        printf("3. Avancuar\n");
        printf("4. Ekspert\n");
        printf("Shkruaj zgjedhjen (1-4): ");

        scanf("%d", &zgjedhja);

        // Kontrolli dhe lidhja me enum
        switch ((Nivel)zgjedhja) {

            case BEGJINOR:
                printf("Ke zgjedhur nivelin Fillestar: Fokus në bazat.\n");
                validCount++;
                break;

            case MESATAR:
                printf("Ke zgjedhur nivelin Mesatar: Praktikë dhe ushtrime.\n");
                validCount++;
                break;

            case AVANCUAR:
                printf("Ke zgjedhur nivelin Avancuar: Detyra më komplekse.\n");
                validCount++;
                break;

            case EKSPERT:
                printf("Ke zgjedhur nivelin Ekspert: Projekte të avancuara.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme! Ju lutem zgjidhni 1-4.\n");
                invalidCount++;
                break;
        }
    }

    // Statistikat në fund
    printf("\n===== STATISTIKAT =====\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje të pavlefshme: %d\n", invalidCount);

    return 0;
}
