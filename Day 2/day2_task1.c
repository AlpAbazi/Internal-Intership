#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;
    short vleraShort = 120;
    long vleraLong = 100000L;


    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin (nje shkronje): ");
    scanf(" %c", &iniciali);  

    printf("Shkruaj gjatesine (float): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren (double): ");
    scanf("%lf", &mesatarja);


    printf("\n--- PROFILI I PERDORUESIT ---\n");

    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);

    printf("Vlera short: %hd\n", vleraShort);
    printf("Vlera long: %ld\n", vleraLong);

    return 0;
}