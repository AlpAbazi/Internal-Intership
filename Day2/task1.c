#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;
    short smallNumber = 10;
    long bigNumber = 100000;

    // Input
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &height);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &average);

    // Output
    printf("\n--- PROFILI ---\n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Short number: %d\n", smallNumber);
    printf("Long number: %ld\n", bigNumber);

    return 0;
}
