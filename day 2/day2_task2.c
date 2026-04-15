#include <stdio.h>

int main() {
    int rezultati;

    printf("Shkruani rezultatin (0-100): ");
    scanf("%d", &rezultati);

    // Kontrolli i validitetit
    if (rezultati < 0 || rezultati > 100) {
        printf("Input-i nuk eshte valid.\n");
    }
    else if (rezultati >= 90) {
        printf("Shkelqyeshem\n");
    }
    else if (rezultati >= 75) {
        printf("Shume mire\n");
    }
    else if (rezultati >= 50) {
        printf("Mire\n");
    }
    else {
        printf("Ne permiresim\n");
    }

    return 0;
}
