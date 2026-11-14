#include <stdio.h>

/* 5. feladat: szokoev ellenorzes
   Egyszeru szabaly:
   - Ha az ev oszthato 400-al -> szokoev
   - Kulonben, ha oszthato 100-al -> nem szokoev
   - Kulonben, ha oszthato 4-gyel -> szokoev
   - Kulonben -> nem szokoev
*/
int is_leap_year(int ev) {
    if (ev % 400 == 0) return 1;       /* pl. 2000 -> igen */
    if (ev % 100 == 0) return 0;       /* pl. 1900 -> nem */
    if (ev % 4 == 0)   return 1;       /* pl. 2004 -> igen */
    return 0;                           /* egyebkent nem */
}

/* 6. feladat: jegy visszaadasa pont alapjan
   Tabla:
   >=90   -> jeles
   80-89  -> jo
   70-79  -> kozepes
   60-69  -> elegseges
   <60    -> elegtetlen
*/
const char* jegy_from_pont(int pont) {
    if (pont >= 90) return "jeles";
    else if (pont >= 80) return "jo";
    else if (pont >= 70) return "kozepes";
    else if (pont >= 60) return "elegseges";
    else return "elegtelen";
}

int main(void) {
    int ev;
    int pont;

    /* --- Szokoev ellenorzese --- */
    printf("5. feladat - Szokoev ellenorzo\n");
    printf("Kerem adja meg az evet (pl. 2024): ");
    if (scanf("%d", &ev) != 1) {
        printf("Hibas bemenet!\n");
        return 1;
    }

    /* egyszeru, baratsagos magyarázó uzenet */
    /* Megnezzuk: oszthato-e 4-gyel, es nem 100-al, kivetelezve a 400-at. */
    if (is_leap_year(ev)) {
        printf("%d szokoev.\n\n", ev);
    } else {
        printf("%d nem szokoev.\n\n", ev);
    }

    /* --- Jegy meghatarozasa pont alapjan --- */
    printf("6. feladat - Jegy az elert pontszam alapjan\n");
    printf("Kerem adja meg a pontszamot 0 es 100 kozott: ");
    if (scanf("%d", &pont) != 1) {
        printf("Hibas bemenet!\n");
        return 1;
    }

    /* pont validalas: ha kiesik a tartomanybol, figyelmeztetunk */
    if (pont < 0 || pont > 100) {
        printf("A pontnak 0 es 100 kozott kell lennie. Megadott: %d\n", pont);
        return 1;
    }

    const char* jegy = jegy_from_pont(pont);
    printf("Az elert pont: %d -> Jegy: %s\n", pont, jegy);

    return 0;
}
