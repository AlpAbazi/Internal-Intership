    int main() {
    int mosha;
    char iniciali;
    double pike;
    int opsioni;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj pike paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjedh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    // kontroll moshe
    if (mosha < 15) {
        printf("\nNuk lejohet pjesemarrja (mosha shume e ulet)\n");
    } else if (mosha > 25) {
        printf("\nJashte kufirit te rekomanduar te moshes\n");
    } else {
        printf("\nMosha eshte ne rregull per pjesemarrje\n");
    }

    // klasifikimi sipas pikeve
    if (pike < 50) {
        printf("Statusi: Nevojitet me shume ushtrim\n");
    } else if (pike < 80) {
        printf("Statusi: Gati per vazhdim\n");
    } else {
        printf("Statusi: Gati per sfide\n");
    }

    // zgjedhja me switch
    printf("Punetoria: ");
    switch (opsioni) {
        case 1:
            printf("Programim Bazik\n");
            break;
        case 2:
            printf("Algoritme\n");
            break;
        case 3:
            printf("Struktura te Dhenave\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    // permbledhje
    printf("\n--- Permbledhje ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", pike);
    printf("Opsioni: %d\n", opsioni);

    return 0;
