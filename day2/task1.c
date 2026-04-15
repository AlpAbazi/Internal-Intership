#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;
    short favoriteNumber = 12;
    long population = 1800000;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average Grade: %.2lf\n", average);
    printf("Favorite Number (short): %hd\n", favoriteNumber);
    printf("Population (long): %ld\n", population);

    return 0;
}
