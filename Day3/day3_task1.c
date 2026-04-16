    int main() {
    int n, choice;

    // Input për madhësinë
    printf("Shkruaj nje numer (1 - 12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Input jo valid!\n");
        return 0;
    }

    // Zgjedhja e pattern-it
    printf("Zgjedh pattern:\n");
    printf("1 - Me yje\n");
    printf("2 - Me numra\n");
    printf("Zgjedhja: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Zgjedhje jo valide!\n");
        return 0;
    }

    // Pattern
    for (int i = 1; i <= n; i++) {
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
