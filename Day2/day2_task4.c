#include <stdio.h>
#include <string.h>

int main() {
    int age;
    char initial;
    double points;
    int option;

    // Read inputs
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter initial: ");
    scanf(" %c", &initial); // space to consume newline
    printf("Enter previous points: ");
    scanf("%lf", &points);
    printf("Enter workshop option (1, 2, or 3): ");
    scanf("%d", &option);

    // Age check: participation limit 18-65
    if (age < 18 || age > 65) {
        printf("Age not within participation limit (18-65).\n");
        return 1;
    }

    // Classify based on points
    // < 50: needs more practice
    // 50-79: ready to continue
    // >= 80: ready for challenge
    char classification[50];
    if (points < 50) {
        strcpy(classification, "needs more practice");
    } else if (points < 80) {
        strcpy(classification, "ready to continue");
    } else {
        strcpy(classification, "ready for challenge");
    }

    // Workshop name using switch
    char workshop[50];
    switch (option) {
        case 1:
            strcpy(workshop, "Basic Programming");
            break;
        case 2:
            strcpy(workshop, "Advanced Algorithms");
            break;
        case 3:
            strcpy(workshop, "Data Structures");
            break;
        default:
            printf("Invalid workshop option.\n");
            return 1;
    }

    // Summary
    printf("\nSummary:\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Previous points: %.2f\n", points);
    printf("Classification: %s\n", classification);
    printf("Selected workshop: %s\n", workshop);

    return 0;
}