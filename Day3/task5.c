// Enum me 4 nivele
enum Niveli {
    FILLSTAR = 1,
    MESATAR,
    I_AVANCUAR,
    EKSPERT
};

int main() {
    int zgjedhje;
    int valid = 0, invalid = 0;

    for(int i = 1; i <= 3; i++) {
        printf("\nZgjedh nivelin per rastin %d:\n", i);
        printf("1 - Fillestar\n2 - Mesatar\n3 - I avancuar\n4 - Ekspert\n");
        printf("Zgjedhja: ");
        scanf("%d", &zgjedhje);

        switch(zgjedhje) {
            case FILLSTAR:
                printf("Je ne nivel fillestar\n");
                valid++;
                break;
            case MESATAR:
                printf("Je ne nivel mesatar\n");
                valid++;
                break;
            case I_AVANCUAR:
                printf("Je ne nivel i avancuar\n");
                valid++;
                break;
            case EKSPERT:
                printf("Je ne nivel ekspert\n");
                valid++;
                break;
            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalid++;
        }
    }

    printf("\n--- STATISTIKAT ---\n");
    printf("Zgjedhje valide: %d\n", valid);
    printf("Zgjedhje invalide: %d\n", invalid);

    return 0;
}
