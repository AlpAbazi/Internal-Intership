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
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &pike);

    printf("Zgjidh punetoren (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    printf("\n--- PERMBLEDHJE ---\n");

    // Shfaqja e te dhenave
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2f\n", pike);

    // Kontrolli i moshes
    if (mosha >= 13 && mosha <= 18) {
        printf("Mosha eshte brenda kufirit per pjesemarrje.\n");
    } else {
        printf("Mosha nuk eshte brenda kufirit per pjesemarrje.\n");
    }

    // Vendimmarrja sipas pikëve
    if (pike < 50) {
        printf("Rezultati: Nevojitet me shume ushtrim.\n");
    } else if (pike >= 50 && pike < 80) {
        printf("Rezultati: Gati per vazhdim.\n");
    } else {
        printf("Rezultati: Gati per sfide.\n");
    }

    // Switch për punëtorinë
    switch (opsioni) {
        case 1:
            printf("Punetoria e zgjedhur: Programim Bazik\n");
            break;
        case 2:
            printf("Punetoria e zgjedhur: Web Zhvillim\n");
            break;
        case 3:
            printf("Punetoria e zgjedhur: Database\n");
            break;
        default:
            printf("Opsion i pavlefshem!\n");
            break;
    }

    printf("\nProgrami perfundoi me sukses.\n");

    return 0;
}
