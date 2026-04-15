#include <stdio.h>

int main() {
    int score;

    // Merr input nga përdoruesi
    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &score);

    // Kontrolli i validitetit të intervalit
    if (score < 0 || score > 100) {
        printf("Input-i nuk eshte valid! Ju lutem shkruani nje vlere nga 0 deri 100.\n");
    }
    else if (score >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Shume mire\n");
    }
    else if (score >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
