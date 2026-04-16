#include <stdio.h>

int main() {
    int n, zgjedhja;

    // Input për madhësinë
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    // Kontroll i input-it
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Duhet te jete nga 1 deri ne 12.\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjidh pattern:\n");
    printf("1 - Me yje (*)\n");
    printf("2 - Me numra\n");
    printf("Zgjedhja: ");
    scanf("%d", &zgjedhja);

    printf("\n");

    // Pattern me yje
    if (zgjedhja == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if (zgjedhja == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Zgjedhje e pavlefshme
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
