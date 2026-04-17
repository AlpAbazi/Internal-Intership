#include <stdio.h>

int main() {
    int mosha, opsioni;
    char iniciali;
    double pike;

    printf("Shkruani moshen: ");
    scanf("%d", &mosha);

    printf("Shkruani inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruani pikat paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjidhni punetorine (1-3): ");
    scanf("%d", &opsioni);

    if (mosha < 12) {
        printf("Nuk lejohet pjesemarrja (mosha shume e vogel).\n");
    } else if (mosha > 60) {
        printf("Jashte kufirit te rekomanduar te moshes.\n");
    } else {
        printf("Mosha eshte ne rregull per pjesemarrje.\n");
    }

    char* niveli;
    if (pike < 50) {
        niveli = "Nevojitet me shume ushtrim";
    } else if (pike < 80) {
        niveli = "Gati per vazhdim";
    } else {
        niveli = "Gati per sfide";
    }

    char* punetoria;
    switch (opsioni) {
        case 1:
            punetoria = "Programim Bazik";
            break;
        case 2:
            punetoria = "Web Development";
            break;
        case 3:
            punetoria = "AI & Data";
            break;
        default:
            punetoria = "Opsion i pavlefshem";
    }

    printf("\n--- PERMBLEDHJE ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2f\n", pike);
    printf("Niveli: %s\n", niveli);
    printf("Punetoria: %s\n", punetoria);

    return 0;
}