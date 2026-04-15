#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pike;
    int opsioni;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    if (mosha < 15 || mosha > 25) {
        printf("\nNuk ploteson kushtin e moshes per pjesemarrje.\n");
    } else {
        printf("\nMosha eshte valide per pjesemarrje.\n");
    }

    char* rezultati;

    if (pike < 50) {
        rezultati = "Nevojitet me shume ushtrim";
    } else if (pike >= 50 && pike < 80) {
        rezultati = "Gati per vazhdim";
    } else {
        rezultati = "Gati per sfide";
    }

    char* punetoria;

    switch (opsioni) {
        case 1:
            punetoria = "Programim bazik";
            break;
        case 2:
            punetoria = "Algoritme";
            break;
        case 3:
            punetoria = "Struktura te dhenash";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", pike);
    printf("Punetoria: %s\n", punetoria);
    printf("Rezultati: %s\n", rezultati);

    return 0;
}