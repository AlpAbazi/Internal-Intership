#include <stdio.h>

int main() {
    int dita;

    printf("Shkruaj nje numer nga 1 deri ne 7: ");
    scanf("%d", &dita);

    switch (dita) {
        case 1:
            printf("E Hene - dite pune\n");
            break;

        case 2:
            printf("E Marte - dite pune\n");
            break;

        case 3:
            printf("E Merkure - dite pune\n");
            break;

        case 4:
            printf("E Enjte - dite pune\n");
            break;

        case 5:
            printf("E Premte - dite pune\n");
            break;

        case 6:
            printf("E Shtune - fundjave\n");
            break;

        case 7:
            printf("E Diel - fundjave\n");
            break;

        default:
            printf("Input i pavlefshem! Ju lutem shkruani numer nga 1 deri ne 7.\n");
    }

    return 0;
}
