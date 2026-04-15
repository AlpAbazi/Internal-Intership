int main() {
    int rezultati;

    printf("Shkruani rezultatin (0 - 100): ");
    scanf("%d", &rezultati);

    if (rezultati < 0 || rezultati > 100) {
        printf("Input-i nuk eshte valid.\n");
    } 
    else if (rezultati >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    } 
    else if (rezultati >= 75) {
        printf("Vleresimi: Shume mire\n");
    } 
    else if (rezultati >= 50) {
        printf("Vleresimi: Mire\n");
    } 
    else {
        printf("Vleresimi: Ne permiresim\n");
    }

    return 0;
}
