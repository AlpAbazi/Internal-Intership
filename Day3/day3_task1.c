#include <stdio.h>

int main() {
    int choice;
    printf("Choose pattern: 1 for stars, 2 for numbers: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice.\n");
        return 1;
    }

    int n;
    printf("Enter a positive number (1-12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Invalid input. Must be between 1 and 12.\n");
        return 1;
    }

    if (choice == 1) {
        // stars pattern
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        // numbers pattern
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }
    }

    return 0;
}