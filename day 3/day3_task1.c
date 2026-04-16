#include <stdio.h>

int main() {
    int size, choice;

    printf("Zgjidh madhesine e pattern-it (1 - 12): ");
    scanf("%d", &size);

    if (size < 1 || size > 12) {
        printf("Input i pavlefshem! Ju lutem jepni nje numer nga 1 deri ne 12.\n");
        return 1;
    }

    printf("Zgjidh pattern-in:\n");
    printf("1. Pattern me yje\n");
    printf("2. Pattern me numra\n");
    printf("Zgjedhja juaj: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Zgjedhje e pavlefshme!\n");
        return 1;
    }

    printf("\nPattern:\n");

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++) {
            if (choice == 1) {
                printf("* ");
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
