#include <stdio.h>
#include <string.h>

typedef enum { E_BERE, NE_PROGRES, E_PAFILLUAR } Status;

typedef struct {
    int id;
    char emri[50];
    int progresi;
    Status statusi;
} Regjistrim;

#define MAX_KAPACITETI 10
Regjistrim lista[MAX_KAPACITETI];
int numriAktual = 0;

void perditesoMePointer(Regjistrim* r, int progresiRi) {
    if (r != NULL) {
        r->progresi = progresiRi;
        if (progresiRi >= 100) r->statusi = E_BERE;
        else if (progresiRi > 0) r->statusi = NE_PROGRES;
        else r->statusi = E_PAFILLUAR;
    }
}

const char* statusNeTekst(Status s) {
    switch (s) {
        case E_BERE: return "E bere";
        case NE_PROGRES: return "Ne progres";
        case E_PAFILLUAR: return "E pafilluar";
        default: return "Panjohur";
    }
}

void shtoRegjistrim() {
    if (numriAktual >= MAX_KAPACITETI) {
        printf("\nGabim: Eshte arritur kapaciteti maksimal (%d)!\n", MAX_KAPACITETI);
        return;
    }

    Regjistrim r;
    r.id = numriAktual + 1;
    printf("Jepni emrin e regjistrimit: ");
    scanf(" %[^\n]s", r.emri); 
    r.progresi = 0;
    r.statusi = E_PAFILLUAR;

    lista[numriAktual++] = r;
    printf("Regjistrimi u shtua me sukses!\n");
}

void shfaqRegjistrimet() {
    if (numriAktual == 0) {
        printf("\nLista eshte boshe.\n");
        return;
    }
    
    printf("\n--- LISTA E REGJISTRIMEVE ---\n");
    for (int i = 0; i < numriAktual; i++) {
        printf("ID: %d | Emri: %s | Progresi: %d%% | Statusi: %s\n", 
               lista[i].id, lista[i].emri, lista[i].progresi, statusNeTekst(lista[i].statusi));
    }
}

void gjeneroRaport() {
    if (numriAktual == 0) {
        printf("\nNuk ka te dhena.\n");
        return;
    }

    int tePerfunduara = 0;
    float shumaProgresit = 0;
    int maxProgIdx = 0;

    for (int i = 0; i < numriAktual; i++) {
        if (lista[i].statusi == E_BERE) tePerfunduara++;
        shumaProgresit += lista[i].progresi;
        if (lista[i].progresi > lista[maxProgIdx].progresi) maxProgIdx = i;
    }
    
    float mesatarja = shumaProgresit / numriAktual;

    printf("\n--- RAPORTI ANALITIK ---\n");
    printf("* Totali i regjistrimeve: %d\n", numriAktual);
    printf("* Te perfunduara: %d\n", tePerfunduara);
    printf("* Mesatarja e progresit: %.2f%%\n", mesatarja);
    printf("* Regjistrimi me progres me te larte: %s\n", lista[maxProgIdx].emri);

    if (mesatarja > 80) printf("Statusi i Grupit: Shkelqyeshem!\n");
    else if (mesatarja >= 40) printf("Statusi i Grupit: Ne rruge te mbare.\n");
    else printf("Statusi i Grupit: Nevojitet vemendje e shtuar.\n");
}

void kerkoDheParalajmero() {
    int kerkimId;
    printf("\nJepni ID-ne per kerkim: ");
    scanf("%d", &kerkimId);

    int uGjet = 0;
    for (int i = 0; i < numriAktual; i++) {
        if (lista[i].id == kerkimId) {
            printf("\nU gjet: %s\n", lista[i].emri);
            printf("Progresi: %d%% | Statusi: %s\n", lista[i].progresi, statusNeTekst(lista[i].statusi));
            
            if (lista[i].progresi < 20 && lista[i].statusi != E_BERE) {
                printf("REKOMANDIM: Ky regjistrim kerkon aksion te menjëhershëm!\n");
            } else {
                printf("REKOMANDIM: Vazhdoni punën sipas planit.\n");
            }
            uGjet = 1;
            break;
        }
    }
    if (!uGjet) printf("Nuk u gjet asnje regjistrim me ID: %d\n", kerkimId);
}

void fshijRegjistrim() {
    int idFshirje;
    printf("\nJepni ID-ne per fshirje: ");
    scanf("%d", &idFshirje);

    int indeksi = -1;
    for (int i = 0; i < numriAktual; i++) {
        if (lista[i].id == idFshirje) {
            indeksi = i;
            break;
        }
    }

    if (indeksi != -1) {
        for (int i = indeksi; i < numriAktual - 1; i++) {
            lista[i] = lista[i + 1];
        }
        numriAktual--;
        printf("Regjistrimi u fshi.\n");
    } else {
        printf("Gabim: ID e pavlefshme!\n");
    }
}

void renditSipasProgresit() {
    if (numriAktual < 2) return;

    for (int i = 0; i < numriAktual - 1; i++) {
        for (int j = 0; j < numriAktual - i - 1; j++) {
            if (lista[j].progresi < lista[j + 1].progresi) {
                Regjistrim temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
    printf("\nRegjistrimet u renditen sipas progresit.\n");
}

int main() {
    int zgjedhja;

    do {
        printf("\n--- MENUJA KRYESORE ---");
        printf("\n1. Shto Regjistrim");
        printf("\n2. Shfaq te Gjitha");
        printf("\n3. Perditeso Progresin");
        printf("\n4. Gjenero Raportin");
        printf("\n5. Kerko dhe Paralajmero");
        printf("\n6. Fshij Regjistrim");
        printf("\n7. Rendit (Rankim)");
        printf("\n0. Dil");
        printf("\nZgjedhja juaj: ");
        
        if (scanf("%d", &zgjedhja) != 1) {
            printf("\nGabim: Input i pavlefshem!\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (zgjedhja) {
            case 1: shtoRegjistrim(); break;
            case 2: shfaqRegjistrimet(); break;
            case 3: {
                int id, prog;
                printf("ID: "); scanf("%d", &id);
                printf("Progresi i ri (0-100): "); scanf("%d", &prog);
                if (prog < 0 || prog > 100) break;
                int gjetur = 0;
                for(int i=0; i<numriAktual; i++) {
                    if(lista[i].id == id) {
                        perditesoMePointer(&lista[i], prog);
                        gjetur = 1; break;
                    }
                }
                break;
            }
            case 4: gjeneroRaport(); break;
            case 5: kerkoDheParalajmero(); break;
            case 6: fshijRegjistrim(); break;
            case 7: renditSipasProgresit(); shfaqRegjistrimet(); break;
            case 0: break;
            default: printf("\nZgjedhje e pavlefshme!\n");
        }
    } while (zgjedhja != 0);

    return 0;
}