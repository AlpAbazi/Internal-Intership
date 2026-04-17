#include <stdio.h>

int main() {
    int numri;

    printf("Shkruani nje numer nga 1 deri ne 7: ");
    scanf("%d", &numri);

    switch(numri) {
        case 1:
            printf("E Hene - Dite pune\n");
            break;
        case 2:
            printf("E Marte - Dite pune\n");
            break;
        case 3:
            printf("E Merkure - Dite pune\n");
            break;
        case 4:
            printf("E Enjte - Dite pune\n");
            break;
        case 5:
            printf("E Premte - Dite pune\n");
            break;
        case 6:
            printf("E Shtune - Fundjave\n");
            break;
        case 7:
            printf("E Diele - Fundjave\n");
            break;
        default:
            printf("Input i pavlefshem ju lutem shkruani numer nga 1 deri 7.\n");
    }

    return 0;
}