/*
    NAPOMENA: 
    Većina zadataka (uključujući ovaj) NEMAJU main funkciju, odnosno kad se kompajliraju
    neće se ništa pokrenuti. Razlog za to je da u tekstu zadatka nigdje nije traženo
    a meni se nije dalo kucat...

    U suštini, ako hoćete testirati, samo napišite main f-ju koja će implementirati sve funkcionalnosti.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct duz
{
    double duzina;
} DUZ;

typedef struct valjak
{
    DUZ poluprecnik, visina;
} VALJAK;

VALJAK ucitaj (){
    VALJAK valjak;
    do
    {
        printf ("Unesite poluprecnik valjka: ");
        scanf ("%lf", &valjak.poluprecnik.duzina);
        printf ("Unesite visinu valjka: ");
        scanf ("%lf", &valjak.visina.duzina);
    } while (valjak.poluprecnik.duzina <0 || valjak.visina.duzina==0);
    

    return valjak;
}

double zapremina (VALJAK v){
    double pi = acos(-1);
    return pi*pow(v.poluprecnik.duzina,2)*v.visina.duzina;
}

int uporedi (VALJAK *v1,VALJAK *v2){
    if (zapremina(*v1)>zapremina(*v2)) return 1;
    if (zapremina(*v2)>zapremina(*v1)) return -1;
    return 0;
}
int compare_valjak(const void *a, const void *b){
    VALJAK *v1 = (VALJAK*) a;
    VALJAK *v2 = (VALJAK*) b;

    if (zapremina(*v1) > zapremina(*v2)) return 1;
    if (zapremina(*v2) > zapremina(*v1)) return -1;
    return 0;
}
void sortiraj (VALJAK *niz, int n){
    qsort(niz, n, sizeof(VALJAK),compare_valjak);
    for (int i = 0; i<n; i++){
        printf ("Valjak[%d]:\nPoluprecnik: %lf\nVisina: %lf\n\n", i, niz[i].poluprecnik.duzina, niz[i].visina.duzina);
    }
}

int main (void){
    int n;
    printf ("Unesite broj valjaka: ");
    scanf ("%d", &n);
    VALJAK *niz = (VALJAK *)malloc (n*sizeof(VALJAK));

       for (int i = 0; i < n; i++) {
        printf("Valjak[%d]:\n", i);
        niz[i] = ucitaj();
    }

    printf("\nSortiranje valjaka po zapremini...\n");
    sortiraj(niz, n);
}