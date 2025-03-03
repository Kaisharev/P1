#include <stdio.h>
#include <stdlib.h>

typedef struct dokument {
 char naziv[20], autor[20];
 int s; // broj strana
} DOKUMENT;

void clean_new_line ( char *s){
    for (int i = 0; s[i]!='\0'; i++){
        if (s[i] == '\n') s[i]=='\0';
    }
}

DOKUMENT* ucitaj(int *pn){
    printf ("Unesite broj dokumenata: ");
    scanf ("%d", pn);
    getchar();
    DOKUMENT* array_of_documets = (DOKUMENT*) malloc (*pn*sizeof(DOKUMENT)); 
    for (int i = 0; i<*pn-1; i++){
        printf("Unesite naziv");
        gets (array_of_documets[i].naziv);
        printf ("Unesite autora: ");
        gets (array_of_documets[i].autor);
        printf ("Unesite broj strana: ");
        scanf("%d", &array_of_documets[i].s);
        getchar();

    }
    return array_of_documets;
}
int compare_pages (const void *a, const void *b){
    DOKUMENT *d1 = a;
    DOKUMENT *d2 = b;

    return d2->s-d1->s;
}
void sortiraj(DOKUMENT *niz, int n){
    qsort(niz, n, sizeof(niz), compare_pages);
}

int main (){
    int n; 
    DOKUMENT *documents = ucitaj(&n);

    sortiraj(documents, n);

    for (int i = 0; i<n; i++){
        printf ("Naziv: %s\n", documents[i].naziv);
        printf ("Autor: %s\n", documents[i].autor);
        printf ("Broj strana: %s\n", documents[i].s);

    }


    free (documents);
}