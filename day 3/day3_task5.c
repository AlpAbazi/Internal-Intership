
enum Niveli {
    FILLESTAR = 1,
    MESATAR = 2,
    AVANCUAR = 3,
    EKSPERT = 4
};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    for (int i = 1; i <= 3; i++) {
        printf("\nPerdoruesi %d\n", i);
        printf("Zgjidh nivelin:\n");
        printf("1. Fillestar\n");
        printf("2. Mesatar\n");
        printf("3. Avancuar\n");
        printf("4. Ekspert\n");
        printf("Zgjedhja juaj: ");
        scanf("%d", &choice);

        enum Niveli niveli;

        if (choice >= 1 && choice <= 4) {
            niveli = choice;
            validCount++;

            switch (niveli) {
                case FILLESTAR:
                    printf("Mesazh: Nxenesi eshte ne nivel fillestar.\n");
                    break;
                case MESATAR:
                    printf("Mesazh: Nxenesi ka njohuri mesatare.\n");
                    break;
                case AVANCUAR:
                    printf("Mesazh: Nxenesi eshte ne nivel te avancuar.\n");
                    break;
                case EKSPERT:
                    printf("Mesazh: Nxenesi ka arritur nivel ekspert.\n");
                    break;
            }
        } else {
            printf("Input i pavlefshem! Ju lutem zgjidhni nje numer nga 1 deri ne 4.\n");
            invalidCount++;
        }
    }

    printf("\n--- Statistikat ---\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje te pavlefshme: %d\n", invalidCount);

    return 0;
}
