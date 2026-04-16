#include <stdio.h>

int main() {
    int n, choice;
    
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Input nuk eshte valid!\n");
        return 0;
    }

    printf("Zgjidh pattern:\n");
    printf("1 - Yje (*)\n");
    printf("2 - Numra\n");
    printf("Zgjedhja: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }

    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Zgjedhje jo valide!\n");
    }

    return 0;
}