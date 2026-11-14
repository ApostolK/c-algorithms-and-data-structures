#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Globális konstans a negyedév heteinek számára
#define HETEK_SZAMA 13

// Függvény deklarációk
void A_inicializacio(float arfolyamok[HETEK_SZAMA], int *db);
void B_beolvasas(float arfolyamok[HETEK_SZAMA]);
void C_veletlen_toltes(float arfolyamok[HETEK_SZAMA], float *max, int *max_het, float *min, int *min_het);
float D_atlag(const float arfolyamok[HETEK_SZAMA]);
void D_atlag_eltolodas(const float arfolyamok[HETEK_SZAMA], float atlag);

// Főprogram
int main() {
    float arfolyamok[HETEK_SZAMA];
    int harom_szaz_alatt_db = 0;

    // a) Inicializálás és 300 Ft alatti napok számlálása
    printf("--- a) Inicializacio es 300 Ft alatti arfolyamok szamlalasa ---\n");
    A_inicializacio(arfolyamok, &harom_szaz_alatt_db);
    printf("A negyedevben %d alkalommal volt az arfolyam 300 Ft alatt.\n\n", harom_szaz_alatt_db);

    // b) Ellenőrzött beolvasás és monotonitás vizsgálata
    printf("--- b) Ellenorzott beolvasas es monotonitas vizsgalat ---\n");
    B_beolvasas(arfolyamok);

    // c) Véletlenszámokkal való feltöltés és szélsőértékek keresése
    // Ez a feladat a b) ponttal ütközik (vagy feltöltjük kézzel, vagy véletlennel).
    // A feladat sorrendje miatt az arfolyamok tömböt a c) pontban felülírjuk véletlenszámokkal.
    float max_ertek, min_ertek;
    int max_het, min_het;

    printf("--- c) Veletlenszamokkal valo feltoltes es szelsoertekek keresese ---\n");
    C_veletlen_toltes(arfolyamok, &max_ertek, &max_het, &min_ertek, &min_het);
    
    printf("\nArfolyam adatok (generalt): ");
    for (int i = 0; i < HETEK_SZAMA; i++) {
        printf("%.2f ", arfolyamok[i]);
    }
    printf("\n");

    printf("A legmagasabb arfolyam: %.2f Ft, a(z) %d. heten.\n", max_ertek, max_het + 1);
    printf("A legalacsonyabb arfolyam: %.2f Ft, a(z) %d. heten.\n\n", min_ertek, min_het + 1);

    // d) Átlag és eltérés kiírása
    printf("--- d) Atlag es elteres kiirasa ---\n");
    float atlag = D_atlag(arfolyamok);
    printf("Az atlagos arfolyam a negyedevre: %.2f Ft\n", atlag);
    D_atlag_eltolodas(arfolyamok, atlag);

    return 0;
}

// ----------------------------------------------------------------------------------
// a) Inicializációs lista és számlálás
// ----------------------------------------------------------------------------------
void A_inicializacio(float arfolyamok[HETEK_SZAMA], int *db) {
    // Statikus inicializációs lista használata
    float kezdo_arfolyamok[HETEK_SZAMA] = {
        390.50, 385.20, 392.10, 380.00, 375.40, 
        298.10, 295.60, 301.50, 305.90, 310.20, 
        308.70, 312.30, 315.00
    };

    *db = 0;
    for (int i = 0; i < HETEK_SZAMA; i++) {
        arfolyamok[i] = kezdo_arfolyamok[i];
        if (arfolyamok[i] < 300.0) {
            (*db)++;
        }
    }
}

// ----------------------------------------------------------------------------------
// b) Ellenőrzött beolvasás és monotonitás vizsgálat
// ----------------------------------------------------------------------------------
void B_beolvasas(float arfolyamok[HETEK_SZAMA]) {
    // Példa ellenőrzött beolvasásra (csak 3 adatot kérünk be a teszteléshez,
    // mivel a feladat a C pontban is felülírja az adatokat)
    printf("Kerem, adja meg a heti arfolyamokat:\n");
    for (int i = 0; i < 3; i++) { // Csak 3 adat beolvasása demonstrációként
        float adat;
        bool ervenyes = false;
        while (!ervenyes) {
            printf("%d. het arfolyama: ", i + 1);
            if (scanf("%f", &adat) == 1 && adat > 0) { // Ellenőrizzük, hogy számot és pozitív értéket adott-e meg
                arfolyamok[i] = adat;
                ervenyes = true;
            } else {
                printf("Hibas bemenet! Pozitiv szamot adjon meg.\n");
                // Tisztitjuk a bemeneti puffert
                while (getchar() != '\n');
            }
        }
    }

    // Monotonitás vizsgálat
    bool monoton_notte = true;
    for (int i = 1; i < HETEK_SZAMA; i++) {
        // Feltételezve, hogy az a) pontból örökölt adatok is érintettek
        if (arfolyamok[i] < arfolyamok[i-1]) {
            monoton_notte = false;
            break;
        }
    }

    // Kiírás feltételes operátorral
    printf("Az arfolyam a negyedev soran ");
    (monoton_notte) ? printf("MONOTON NOTT.\n") : printf("NEM NOTT monoton modon.\n");
}

// ----------------------------------------------------------------------------------
// c) Véletlenszámokkal való feltöltés és szélsőértékek keresése
// ----------------------------------------------------------------------------------
void C_veletlen_toltes(float arfolyamok[HETEK_SZAMA], float *max, int *max_het, float *min, int *min_het) {
    // Inicializáljuk a véletlenszám generátort
    srand(time(NULL));

    // Véletlenszerű EUR/HUF árfolyam generálása 360 és 400 között
    for (int i = 0; i < HETEK_SZAMA; i++) {
        // Generáljunk egy 0 és 40 közötti egész számot (360 és 400 közötti tartományhoz)
        float veletlen_egesz = rand() % 41; // [0, 40]
        // Hozzáadunk 360-at, így a tartomány [360, 400]
        float arfolyam_alap = 360.0 + veletlen_egesz;
        
        // Hozzáadunk egy véletlenszerű tizedes részt (0.00 - 0.99)
        arfolyamok[i] = arfolyam_alap + (float)rand() / (float)RAND_MAX; 
    }

    // Szélsőértékek keresése
    *max = arfolyamok[0];
    *max_het = 0;
    *min = arfolyamok[0];
    *min_het = 0;

    for (int i = 1; i < HETEK_SZAMA; i++) {
        if (arfolyamok[i] > *max) {
            *max = arfolyamok[i];
            *max_het = i;
        }
        if (arfolyamok[i] < *min) {
            *min = arfolyamok[i];
            *min_het = i;
        }
    }
}

// ----------------------------------------------------------------------------------
// d) Átlag számítása
// ----------------------------------------------------------------------------------
float D_atlag(const float arfolyamok[HETEK_SZAMA]) {
    float osszeg = 0.0;
    for (int i = 0; i < HETEK_SZAMA; i++) {
        osszeg += arfolyamok[i];
    }
    return osszeg / HETEK_SZAMA;
}

// ----------------------------------------------------------------------------------
// d) Eltérés kiírása 
// ----------------------------------------------------------------------------------
void D_atlag_eltolodas(const float arfolyamok[HETEK_SZAMA], float atlag) {
    printf("Arfolyam | Atlagtol valo elteres\n");
    printf("--------------------------------\n");
    for (int i = 0; i < HETEK_SZAMA; i++) {
        float elteres = arfolyamok[i] - atlag;
        // Az elteres elojeles kiirasa
        printf(" %.2f Ft | %+7.2f Ft\n", arfolyamok[i], elteres);
    }
}