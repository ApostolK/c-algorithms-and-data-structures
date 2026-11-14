#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Eldonti, hogy prim-e a szam
bool prim(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Szamolja a negativ szamok atlagat
double negativ_atlag(int also, int felso) {
    int osszeg = 0, db = 0;
    for (int i = also; i <= felso; i++) {
        if (i < 0) {
            osszeg += i;
            db++;
        }
    }
    if (db == 0) return 0;
    return (double)osszeg / db;
}

// Szamolja a pozitiv szamok mertani atlagat
double pozitiv_mertani_atlag(int also, int felso) {
    double szorzat = 1.0;
    int db = 0;
    for (int i = also; i <= felso; i++) {
        if (i > 0) {
            szorzat *= i;
            db++;
        }
    }
    if (db == 0) return 0;
    return pow(szorzat, 1.0 / db);
}

// Megszamolja a prim szamokat
int prim_szamlalo(int also, int felso) {
    int db = 0;
    for (int i = also; i <= felso; i++) {
        if (prim(abs(i))) db++;
    }
    return db;
}

int main(void) {
    int also, felso;

    printf("Add meg a tartomany also es felso hatarat (pl. -100 100): ");
    while (scanf("%d %d", &also, &felso) != 2 || also >= felso) {
        printf("\033[1;31mHibas bemenet! Also hatar kisebb legyen, mint a felso!\033[0m ");
        while (getchar() != '\n');
    }

    double neg_atlag = negativ_atlag(also, felso);
    double poz_geom = pozitiv_mertani_atlag(also, felso);
    int prim_db = prim_szamlalo(also, felso);

    printf("\033[1;34mStatisztikai adatok:\033[0m\n");
    printf("Negativ szamok atlaga: %.2f\n", neg_atlag);
    printf("Pozitiv szamok mertani atlaga: %.2f\n", poz_geom);
    printf("Prim szamok szama: %d\n", prim_db);

    return 0;
}