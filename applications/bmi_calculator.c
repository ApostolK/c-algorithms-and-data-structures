#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // A BMI kiszámításához

// Konstansok
#define FIATALOK_SZAMA 10

// --- Függvény deklarációk ---

// Függvény a magasság tömb feltöltésére véletlenszámokkal
void magassag_feltolt(int magassagok[], int meret);

// Függvény a tömeg tömb feltöltésére véletlenszámokkal
void tomeg_feltolt(double tomegek[], int meret);

// Függvény a BMI kiszámítására az adatokból
void bmi_szamit(const int magassagok[], const double tomegek[], double bmi_indexek[], int meret);

// Függvény a BMI értékelésének meghatározására
const char* bmi_ertekeles(double bmi);

// Függvény a táblázat megjelenítésére
void tablazat_megjelenit(const int magassagok[], const double tomegek[], const double bmi_indexek[], int meret);

// --- Főprogram ---
int main() {
    // A véletlenszám-generátor inicializálása
    srand(time(NULL));

    // 1. Két külön tömb létrehozása a 10 fiatal adatainak tárolására
    int magassagok[FIATALOK_SZAMA];   // Egész számok, 160 és 190 cm között
    double tomegek[FIATALOK_SZAMA];   // Valós számok, 60 és 100 kg között
    double bmi_indexek[FIATALOK_SZAMA]; // A kiszámított BMI-k tárolására

    // 2. A tömbök feltöltése külön függvényekben véletlenszámokkal
    magassag_feltolt(magassagok, FIATALOK_SZAMA);
    tomeg_feltolt(tomegek, FIATALOK_SZAMA);

    // 3. BMI indexek kiszámítása
    bmi_szamit(magassagok, tomegek, bmi_indexek, FIATALOK_SZAMA);

    // 4. Az adatok megjelenítése táblázatos formában
    tablazat_megjelenit(magassagok, tomegek, bmi_indexek, FIATALOK_SZAMA);

    return 0;
}

// --- Függvény implementációk ---

/**
 * Magasság tömb feltöltése 160 és 190 közötti véletlen egész számokkal.
 */
void magassag_feltolt(int magassagok[], int meret) {
    for (int i = 0; i < meret; i++) {
        // Véletlenszám generálása [160, 190] tartományban:
        // rand() % (max - min + 1) + min
        magassagok[i] = (rand() % (190 - 160 + 1)) + 160;
    }
}

/**
 * Tömeg tömb feltöltése 60.0 és 100.0 közötti véletlen valós számokkal.
 */
void tomeg_feltolt(double tomegek[], int meret) {
    for (int i = 0; i < meret; i++) {
        // Véletlen valós szám generálása [60.0, 100.0] tartományban:
        // (rand() / (double)RAND_MAX) * (max - min) + min
        tomegek[i] = ((double)rand() / RAND_MAX) * (100.0 - 60.0) + 60.0;
    }
}

/**
 * Kiszámítja a BMI-t az adott magasságok és tömegek alapján.
 * BMI = tömeg (kg) / [magasság (m)]^2
 */
void bmi_szamit(const int magassagok[], const double tomegek[], double bmi_indexek[], int meret) {
    for (int i = 0; i < meret; i++) {
        // Magasság átváltása cm-ről méterre
        double magassag_meter = (double)magassagok[i] / 100.0;
        
        // BMI kiszámítása: tömeg / (magasság_m * magasság_m)
        bmi_indexek[i] = tomegek[i] / (magassag_meter * magassag_meter);
        
        // Alternatív megoldás:
        // bmi_indexek[i] = tomegek[i] / pow(magassag_meter, 2.0);
    }
}

/**
 * Meghatározza a BMI-hez tartozó szöveges értékelést a megadott kategóriák alapján.
 * Sovány: BMI < 18.5
 * Normális: 18.5 <= BMI < 25
 * Elhízott: BMI >= 25
 */
const char* bmi_ertekeles(double bmi) {
    if (bmi < 18.5) {
        return "Sovany";
    } else if (bmi < 25.0) { // Tudjuk, hogy BMI >= 18.5
        return "Normalis";
    } else { // BMI >= 25
        return "Elhizott";
    }
}

/**
 * Megjeleníti az adatokat táblázatos formában.
 * Egy sor szerkezete: sorszám, testsúly, testmagasság, BMI index, szöveges értelmezés.
 */
void tablazat_megjelenit(const int magassagok[], const double tomegek[], const double bmi_indexek[], int meret) {
    // Fejléc kiírása
    printf("--- Testtomeg Index (BMI) Ertekeles ---\n");
    printf("+-------+-----------+------------+-------------+-------------------+\n");
    printf("| Szam  | Testsuly  | Magassag   | BMI Index   | Ertekeles         |\n");
    printf("|       |   (kg)    |   (cm)     | (kg/m^2)    |                   |\n");
    printf("+-------+-----------+------------+-------------+-------------------+\n");
    // A táblázatnál hasonló az elgondolás mint amit pythonba csinálnék, a szintaktika változik
    // Adatok kiírása soronként
    for (int i = 0; i < meret; i++) {
        const char* ertekeles = bmi_ertekeles(bmi_indexek[i]);

        // A feladat "printf"-et kért, itt egy formázott kiírás:
        printf("| %5d | %9.2lf | %10d | %11.2lf | %-17s |\n", 
               i + 1,               // Sorszám (1-től indul)
               tomegek[i],          // Testsúly (2 tizedesjegy pontossággal)
               magassagok[i],       // Testmagasság
               bmi_indexek[i],      // BMI Index (2 tizedesjegy pontossággal)
               ertekeles            // Szöveges értelmezés
        );
    }

    // Lábjegyzet
    printf("+-------+-----------+------------+-------------+-------------------+\n");
}