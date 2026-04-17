#include <stdio.h>

enum Niveli {
    FILLESTAR = 1,
    MESATAR,
    AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhje;
    int valide = 0, pavlefshme = 0;

    for(int i = 1; i <= 3; i++) {
        printf("Zgjedh nivelin (1-Fillestar, 2-Mesatar, 3-Avancuar, 4-Ekspert): ");
        scanf("%d", &zgjedhje);

        enum Niveli niveli = zgjedhje;

        switch(niveli) {
            case FILLESTAR:
                printf("Je ne nivel fillestar\n");
                valide++;
                break;
            case MESATAR:
                printf("Je ne nivel mesatar\n");
                valide++;
                break;
            case AVANCUAR:
                printf("Je ne nivel avancuar\n");
                valide++;
                break;
            case EKSPERT:
                printf("Je ne nivel ekspert\n");
                valide++;
                break;
            default:
                printf("Zgjedhje e pavlefshme\n");
                pavlefshme++;
        }
    }

    printf("\nStatistika:\n");
    printf("Zgjedhje valide: %d\n", valide);
    printf("Zgjedhje te pavlefshme: %d\n", pavlefshme);

    return 0;
}