#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB 6

typedef struct
{
    int kod;
    char megnevezes[31];
    int ar;
    char raktar[6];
    char torekeny[10]; // JAVÍTVA: 4 -> 10
} Termek;


/* Kiírás fájlba */
void fajlba_ir(Termek termekek[], int db)
{
    FILE *fp = fopen("raktar.txt", "w");

    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasakor!\n");
        return;
    }

    for (int i = 0; i < db; i++)
    {
        fprintf(fp, "%04d;%s;%d;%s;%s\n",
                termekek[i].kod,
                termekek[i].megnevezes,
                termekek[i].ar,
                termekek[i].raktar,
                termekek[i].torekeny);
    }

    fclose(fp);
}


/* Keresés */
void keres_termek(int keresettKod)
{
    FILE *fp = fopen("raktar.txt", "r");

    if (fp == NULL)
    {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return;
    }

    Termek t;
    int talalt = 0;

    // JAVÍTVA: %3s -> %9s
    while (fscanf(fp, "%d;%30[^;];%d;%5[^;];%9s",
                  &t.kod,
                  t.megnevezes,
                  &t.ar,
                  t.raktar,
                  t.torekeny) == 5)
    {
        if (t.kod == keresettKod)
        {
            printf("\nA keresett termek:\n");
            printf("Kod: %04d\n", t.kod);
            printf("Megnevezes: %s\n", t.megnevezes);
            printf("Ar: %d Ft\n", t.ar);
            printf("Raktar: %s\n", t.raktar);
            printf("Torekeny: %s\n", t.torekeny);

            talalt = 1;
            break;
        }
    }

    if (!talalt)
    {
        printf("Nincs ilyen kodu termek a fajlban!\n");
    }

    fclose(fp);
}


/* Törlés */
void torol_termek(int torlendoKod)
{
    FILE *fp = fopen("raktar.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Hiba a fajl megnyitasakor!\n");

        if (fp != NULL)
            fclose(fp);

        if (temp != NULL)
            fclose(temp);

        return;
    }

    Termek t;
    int talalt = 0;

    // JAVÍTVA: %3s -> %9s
    while (fscanf(fp, "%d;%30[^;];%d;%5[^;];%9s",
                  &t.kod,
                  t.megnevezes,
                  &t.ar,
                  t.raktar,
                  t.torekeny) == 5)
    {
        if (t.kod != torlendoKod)
        {
            fprintf(temp, "%04d;%s;%d;%s;%s\n",
                    t.kod,
                    t.megnevezes,
                    t.ar,
                    t.raktar,
                    t.torekeny);
        }
        else
        {
            talalt = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("raktar.txt");
    rename("temp.txt", "raktar.txt");

    if (talalt)
        printf("A %04d kodu termek torolve lett.\n", torlendoKod);
    else
        printf("Nincs ilyen kodu termek!\n");
}


/* Fájl beolvasása */
int fajl_beolvas(Termek termekek[])
{
    FILE *fp = fopen("raktar.txt", "r");

    if (fp == NULL)
    {
        printf("Hiba a fajl megnyitasakor!\n");
        return 0;
    }

    int db = 0;

    // JAVÍTVA: %3s -> %9s
    while (db < 100 &&
           fscanf(fp, "%d;%30[^;];%d;%5[^;];%9s",
                  &termekek[db].kod,
                  termekek[db].megnevezes,
                  &termekek[db].ar,
                  termekek[db].raktar,
                  termekek[db].torekeny) == 5)
    {
        db++;
    }

    fclose(fp);

    return db;
}


/* Rendezés raktárkód szerint */
void rendez_raktar_szerint()
{
    Termek termekek[100];

    int db = fajl_beolvas(termekek);

    for (int i = 0; i < db - 1; i++)
    {
        for (int j = 0; j < db - i - 1; j++)
        {
            if (strcmp(termekek[j].raktar,
                       termekek[j + 1].raktar) > 0)
            {
                Termek temp = termekek[j];
                termekek[j] = termekek[j + 1];
                termekek[j + 1] = temp;
            }
        }
    }

    fajlba_ir(termekek, db);

    printf("A fajl rendezve lett raktar szerint.\n");
}


/* A teljes fájl kiírása */
void listaz()
{
    FILE *fp = fopen("raktar.txt", "r");

    if (fp == NULL)
    {
        printf("Nem sikerult megnyitni a fajlt!\n");
        return;
    }

    Termek t;

    printf("\n--- RAKTAR TARTALMA ---\n");

    // JAVÍTVA: %3s -> %9s
    while (fscanf(fp, "%d;%30[^;];%d;%5[^;];%9s",
                  &t.kod,
                  t.megnevezes,
                  &t.ar,
                  t.raktar,
                  t.torekeny) == 5)
    {
        printf("%04d | %-20s | %5d Ft | %s | %s\n",
               t.kod,
               t.megnevezes,
               t.ar,
               t.raktar,
               t.torekeny);
    }

    fclose(fp);
}


int main()
{
    Termek termekek[DB] =
    {
        {1001, "Laptop",       99999, "A001", "nem"},
        {1002, "Monitor",      74999, "A001", "igen"},
        {1003, "Billentyuzet", 15999, "B002", "nem"},
        {1004, "Eger",          8999, "B002", "nem"},
        {1005, "Pohar",         2499, "A001", "igen"},
        {1006, "Lampa",        12999, "C003", "igen"}
    };

    int kod;

    /* 1. Kezdeti adatok kiírása */
    fajlba_ir(termekek, DB);
    printf("A kezdeti adatok bekerultek a raktar.txt fajlba.\n");
    listaz();

    /* 2. Keresés */
    printf("\nAdj meg egy keresendo kodot: ");
    scanf("%d", &kod);
    keres_termek(kod);

    /* 3. Törlés */
    printf("\nAdj meg egy torlendo kodot: ");
    scanf("%d", &kod);
    torol_termek(kod);

    printf("\nTorles utan:\n");
    listaz();

    /* 4. Rendezés */
    printf("\nRendezes raktar szerint...\n");
    rendez_raktar_szerint();

    printf("\nRendezes utan:\n");
    listaz();

    return 0;
}