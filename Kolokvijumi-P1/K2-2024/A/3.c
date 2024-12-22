#include <stdio.h>
#include <stdlib.h>

typedef struct datum {
 int d, m, g;
} DATUM;
typedef struct artikal {
 int id; // identifikator
 char naziv[21];
 DATUM vazi_do;
 double kol; // kolicina
 double cena;
} ARTIKAL;

ARTIKAL* ucitaj (int *pn){
    ARTIKAL *artikli = (ARTIKAL*)malloc(*pn*sizeof(ARTIKAL));
    for (int i = 0; i<*pn; i++){
        printf ("Unesite ID, Naaziv, Količinu i Cijenu proizvoda: ");
        scanf ("%d %s, %lf, %lf", &artikli->id, &artikli->naziv, &artikli->kol, &artikli->cena);
        printf ("\nUneside Datum, Mjesec i Godinu trajanja proizvoda (DD/MM/GGGG): ");
        scanf ("%d/%d/%d",&artikli->vazi_do.d, &artikli->vazi_do.m, &artikli->vazi_do.g);
    }
    return artikli;
}
ARTIKAL* pronadji(ARTIKAL *niz, int n, int id){
    for (int i = 0; i<n; i++){
        if (niz[i].id == id) {
                ARTIKAL *article_by_id = (ARTIKAL*) malloc (sizeof(ARTIKAL));
        *article_by_id=niz[i];
        return article_by_id;
        }
    }
    return NULL;
}
int comparator(const void *a, const void *b){
    ARTIKAL *a1 = (ARTIKAL*) a;
    ARTIKAL *a2 = (ARTIKAL*) b;

    return a1->id-a2->id;

}
void sortiraj(ARTIKAL *niz, int n){
    qsort(niz, n, sizeof(ARTIKAL), comparator);
}
void ispisi(ARTIKAL *niz, int n) {
    for (int i = 0; i < n; i++) {
        printf("============================================\n");
        printf("ID: %d\n", niz[i].id);
        printf("Naziv: %s\n", niz[i].naziv);
        printf("Važi do: %d/%d/%d\n", niz[i].vazi_do.d, niz[i].vazi_do.m, niz[i].vazi_do.g);
        printf("Količina: %.2lf\n", niz[i].kol);
        printf("Cijena: %.2lf\n", niz[i].cena);
        printf("============================================\n");
    }
}

int main (void){

    int n;
    printf ("Unesite broj artikala: ");
    scanf ("%d", &n);

    ARTIKAL *artikli = ucitaj (&n);
 printf("\nIspis unetih artikala:\n");
    ispisi(artikli, n);

    // Pronalazak artikla po ID-u
    int trazeni_id;
    printf("\nUnesite ID artikla koji želite pronaći: ");
    scanf("%d", &trazeni_id);

    ARTIKAL *pronasao = pronadji(artikli, n, trazeni_id);
    if (pronasao != NULL) {
        printf("\nPronađeni artikal:\n");
        ispisi(pronasao, 1); // Ispis samo jednog artikla
        free(pronasao);      // Oslobađanje memorije za dinamičku kopiju
    } else {
        printf("\nArtikal sa ID %d nije pronađen.\n", trazeni_id);
    }

    // Sortiranje artikala
    printf("\nSortiranje artikala po ID-u...\n");
    sortiraj(artikli, n);

    // Ispis artikala nakon sortiranja
    printf("\nIspis artikala nakon sortiranja:\n");
    ispisi(artikli, n);

    // Oslobađanje memorije
    free(artikli);

    return 0;
}