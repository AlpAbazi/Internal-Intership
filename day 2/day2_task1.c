#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;

    short year = 2025;
    long population = 1800000;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter initial: ");
    scanf(" %c", &initial);

    printf("Enter height: ");
    scanf("%f", &height);

    printf("Enter average: ");
    scanf("%lf", &average);

    printf("\n--- USER PROFILE ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average: %.2lf\n", average);
    printf("Year: %d\n", year);
    printf("Population: %ld\n", population);

    return 0;
}
