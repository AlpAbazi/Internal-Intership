int main() {
    int mosha;
    char iniciali;
    float gjatesia;
    double mesatarja;

    short vitiLindjes = 2005;
    long numriTelefonit = 38344123456;

    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj gjatesine (ne metra): ");
    scanf("%f", &gjatesia);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &mesatarja);

    printf("\n--- Profili i Perdoruesit ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Gjatesia: %.2f m\n", gjatesia);
    printf("Mesatarja: %.2lf\n", mesatarja);
    printf("Viti i lindjes (short): %hd\n", vitiLindjes);
    printf("Numri i telefonit (long): %ld\n", numriTelefonit);

    return 0;
}
