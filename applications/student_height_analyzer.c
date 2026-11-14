#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MERET 10

void tomb_feltolt(int* lista,int len);
void ellenorzott_string(char* target);
void ellenorzott_hatarok(int* also, int* felso);
double megadott_atlag(int* lista, int len, char bemenet[]);
void tomb_ki(int* lista,int len);
int hanyadik(int* lista, int len, int target);

int main(){
    int tanulok[MERET];
    tomb_feltolt(tanulok,MERET);
    //tomb_ki(tanulok,MERET);

    char magassag[20];
    ellenorzott_string(magassag);

    int hatara;
    int hatarf;
    ellenorzott_hatarok(&hatara,&hatarf);

    double atlag = megadott_atlag(tanulok,MERET,magassag);
    printf("A %s atlag: %.2f\n",magassag,atlag);

    int result = hanyadik(tanulok,MERET,165);
    if (result == -1){
        printf("Nincs ilyen magassagu tanulo.");
    }else{
        printf("A 165 cm magassagu tanulo a %d.",result+1);
    }
}

void tomb_ki(int* lista,int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d: %d \n",i+1,lista[i]);
    }
}

void tomb_feltolt(int* lista,int len){
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        lista[i] = rand() % (180-140+1) + 140;
    }
}

void ellenorzott_string(char* target){
    char temp[50];
    bool ok = true;
    do
    {
        ok = true;
        printf("Kerem adja meg a kategoriat:");
        if(scanf("%49s",temp) == 1){
            if (strcmp(temp,"alacsony") == 0 || strcmp(temp,"magas") == 0)
            {
                strcpy(target,temp); // hova masolja es mit
            }else{
                printf("Hibas bemenet, csak magas vagy alacsony lehet.\n");
                ok = false;
            }

        }else{
            printf("Hibas bemenet.\n");
            ok = false;
        }

        while(getchar() != '\n');
    } while (!ok);
}

void ellenorzott_hatarok(int* also, int* felso){
    int alsot;
    int felsot;
    bool ok;
    do
    {
        ok = true;
        printf("Adja meg az also es felso hatart: (also felso):");
        if(scanf("%d %d",&alsot,&felsot) == 2){
            if(alsot >= 1 && alsot <= 10 && felsot >= 1 && felsot <= 10 && felsot > alsot){
                *also = alsot;
                *felso = felsot;
            }else{
                printf("Hibas bemenet, a hatarok nem jok.");
                ok = false;
            }
        }else{
            printf("Csak szamot adhat meg.");
            ok = false;
        }
        while(getchar() != '\n');
    } while (!ok);
}

double megadott_atlag(int* lista, int len, char* bemenet){
    int eredmeny = strcmp(bemenet, "magas"); // strcmp -> 0 ha egyezik, !=0 ha nem
    int ossz = 0;
    int db = 0;

    for (int i = 0; i < len; i++)
    {
        if(eredmeny == 0 && lista[i] >= 160){ // magas tanulok
            //printf("%d ",lista[i]);
            ossz += lista[i];
            db += 1;
        }else if(eredmeny != 0 && lista[i] < 160) // alacsony tanulok
        {
            //printf("%d ",lista[i]);
            ossz += lista[i];
            db += 1;
        }
    }
    if(db == 0){
        printf("Nincs a kategorianak megfelelo ember");
        return -1;
    }
    return (double)ossz/db;
}

int hanyadik(int* lista, int len, int target){
    for (int i = 0; i < len; i++)
    {
        if(lista[i] == target){
            return i;
        }
    }
    return -1;
}
