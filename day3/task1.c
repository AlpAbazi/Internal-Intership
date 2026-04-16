#include <stdio.h>

int main() {
    int n, choice;

    // Input
    printf("Shkruaj madhesine (1-12): ");
    scanf("%d", &n);

    // Kontroll validiteti
    if(n < 1 || n > 12) {
        printf("Input nuk eshte valid!\n");
        return 0;
    }

    printf("Zgjedh pattern (1 = yje, 2 = numra): ");
    scanf("%d", &choice);

    // Pattern me yje
    if(choice == 1) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if(choice == 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Zgjedhje e pavlefshme!\n");
    }

    return 0;
}
