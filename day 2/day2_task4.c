#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjidh punetorine (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    printf("\n--- Permbledhja e Regjistrimit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket paraprake: %.2lf\n", piket);

    if (mosha >= 14 && mosha <= 25) {
        printf("Statusi i moshes: Brenda kufirit per pjesemarrje\n");
    } else {
        printf("Statusi i moshes: Jashte kufirit per pjesemarrje\n");
    }

    if (piket < 50) {
        printf("Klasifikimi: Nevojitet me shume ushtrim\n");
    } else if (piket < 80) {
        printf("Klasifikimi: Gati per vazhdim\n");
    } else {
        printf("Klasifikimi: Gati per sfide\n");
    }

    switch (opsioni) {
        case 1:
            printf("Punetoria e zgjedhur: Bazat e C\n");
            break;
        case 2:
            printf("Punetoria e zgjedhur: Ushtrime me vendimmarrje\n");
            break;
        case 3:
            printf("Punetoria e zgjedhur: Praktike me input/output\n");
            break;
        default:
            printf("Punetoria e zgjedhur: Opsion i pavlefshem\n");
    }

    return 0;
}
