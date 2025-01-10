/*
    NAPOMENA: 
    Većina zadataka (uključujući ovaj) NEMAJU main funkciju, odnosno kad se kompajliraju
    neće se ništa pokrenuti. Razlog za to je da u tekstu zadatka nigdje nije traženo
    a meni se nije dalo kucat...

    U suštini, ako hoćete testirati, samo napišite main f-ju koja će implementirati sve funkcionalnosti.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct duz {
 double duzina;
} DUZ;
typedef struct kvadar {
 DUZ a, b, c;
} KVADAR;

KVADAR ucitaj(){
    KVADAR input_kvadar;
    do
    {
    printf ("Unesite stranice kvadra (a, b, c)");
    scanf ("%d, %d, %d", &input_kvadar.a.duzina, &input_kvadar.b.duzina, &input_kvadar.c.duzina);    
    } while (input_kvadar.a.duzina <=0 || input_kvadar.b.duzina<=0 || input_kvadar.c.duzina<=0);
    
    return input_kvadar;
}

double zapremina(KVADAR k){
    double volume = k.a.duzina*k.b.duzina*k.c.duzina;
    return volume;
}

int uporedi(KVADAR *k1, KVADAR *k2){
    if (zapremina(*k1)>zapremina(*k2)) return 1;
    else if (zapremina (*k1)<zapremina(*k2)) return -1;
    else return 0;
}

int compare_array (const void *a, const void *b){
    KVADAR *k1 = (KVADAR*)a;
    KVADAR *k2 = (KVADAR*)b;

    return (zapremina(*k1)-zapremina(*k2));

}

void sortiraj(KVADAR *niz, int n){
    qsort(niz, n, sizeof(niz), compare_array);
}