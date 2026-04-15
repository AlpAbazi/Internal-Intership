#include <stdio.h>

int main() {
    int score;
    
    printf("Futni rezultatin (0-100): ");
    scanf("%d", &score);
    
    // Kontrolloni intervalin fillesa
    if (score >= 0 && score <= 100) {
        // Klasifikimi nga vlera më e lartë drejt më të ultës
        if (score >= 90) {
            printf("Vlerësimi: Shkëlqyeshëm (Excellent)\n");
        } else if (score >= 80) {
            printf("Vlerësimi: Shumë mirë (Very Good)\n");
        } else if (score >= 70) {
            printf("Vlerësimi: Mirë (Good)\n");
        } else {
            printf("Vlerësimi: Në përmirësim (Needs Improvement)\n");
        }
    } else {
        printf("Gabim: Input nuk është valid. Ju lutem futni një vlerë ndërmjet 0 dhe 100.\n");
    }
    
    return 0;
}
