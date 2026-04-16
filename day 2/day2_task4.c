#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double pike;
    int opsioni;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali); // hapësira para %c është e rëndësishme

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjidh punëtorinë (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // Kontrolli i moshes
    if (mosha < 15 || mosha > 25) {
        printf("\nNuk ploteson kushtin e moshes per pjesemarrje.\n");
    } else {
        printf("\nPloteson kushtin e moshes.\n");
    }

    // Klasifikimi sipas pikeve
    char rezultat[50];

    if (pike < 50) {
        sprintf(rezultat, "Nevojitet me shume ushtrim");
    } else if (pike >= 50 && pike < 80) {
        sprintf(rezultat, "Gati per vazhdim");
    } else {
        sprintf(rezultat, "Gati per sfide");
    }

    // Zgjedhja e punëtorisë
    char punetoria[50];

    switch (opsioni) {
        case 1:
            sprintf(punetoria, "Programim ne C");
            break;
        case 2:
            sprintf(punetoria, "Databaza");
            break;
        case 3:
            sprintf(punetoria, "Rrjete Kompjuterike");
            break;
        default:
            sprintf(punetoria, "Opsion i pavlefshem");
    }

    // Output final
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Iniciali: %c\n", iniciali);
    printf("Mosha: %d\n", mosha);
    printf("Piket: %.2lf\n", pike);
    printf("Punetoria: %s\n", punetoria);
    printf("Rezultati: %s\n", rezultat);

    return 0;
}
