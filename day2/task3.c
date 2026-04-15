    int main() {
    int dita;

    printf("Shkruaj nje numer nga 1 deri 7: ");
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
            printf("E Diele - fundjave\n");
            break;

        default:
            printf("Numer i pavlefshem\n");
    }

    return 0;
}
