#include <stdio.h>

int main() {
    int score;

    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Input-i nuk eshte valid! Duhet te jete ne intervalin 0-100.\n");
    }
    else if (score >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (score >= 75) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (score >= 60) {
        printf("Vleresimi: Mire\n");
    }
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}