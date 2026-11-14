#include <stdio.h>
#include <stdbool.h>

// Eldonti, hogy szokoev-e
bool szokoev(int ev) {
    return (ev % 4 == 0 && ev % 100 != 0) || (ev % 400 == 0);
}

// Kiszamolja, hanyadik napja az evnek a megadott datum
int hanyadik_nap(int ev, int honap, int nap) {
    int napok_honapban[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (szokoev(ev)) {
        napok_honapban[1] = 29; // ha szokoev, februar 29 napos
    }

    int osszesen = nap;
    for (int i = 0; i < honap - 1; i++) {
        osszesen += napok_honapban[i];
    }

    return osszesen;
}

int main(void) {
    int ev, honap, nap;

    printf("Add meg az evet, honapot es napot (pl. 2020 3 1): ");
    while (scanf("%d %d %d", &ev, &honap, &nap) != 3 ||
           honap < 1 || honap > 12 || nap < 1 || nap > 31) {
        printf("\033[1;31mHibas datum! Adj meg ervenyes adatokat:\033[0m ");
        while (getchar() != '\n');
    }

    int nap_sorszam = hanyadik_nap(ev, honap, nap);

    printf("\033[1;32m%d.%02d.%02d az ev %d. napja.\033[0m\n",
           ev, honap, nap, nap_sorszam);

    return 0;
}
