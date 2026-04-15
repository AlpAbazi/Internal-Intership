#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double points;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj piket: ");
    scanf("%lf", &points);

    printf("Zgjedh punetorine (1-3): ");
    scanf("%d", &option);

    // Kontroll moshe
    if (age < 10) {
        printf("Nuk lejohet pjesemarrja (mosha shume e vogel)\n");
    }

    // Klasifikimi me if
    if (points < 50) {
        printf("Status: Nevojitet me shume ushtrim\n");
    }
    else if (points < 80) {
        printf("Status: Gati per vazhdim\n");
    }
    else {
        printf("Status: Gati per sfide\n");
    }

    // Zgjedhja me switch
    printf("Punetoria: ");
    switch(option) {
        case 1:
            printf("Programim\n");
            break;
        case 2:
            printf("Dizajn\n");
            break;
        case 3:
            printf("Rrjete\n");
            break;
        default:
            printf("Zgjedhje e pavlefshme\n");
    }

    // Output final
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Piket: %.2lf\n", points);
    printf("Opsioni: %d\n", option);

    return 0;
}
