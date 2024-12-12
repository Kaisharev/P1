/*
Definisati tip ARTIKAL kojim se reprezentuju podaci o jednom artiklu. Svaki artikl karakteriše identifikator
(prirodan broj), naziv (string), količina (realan broj) i cijena (realan broj). Napisati program koji učitava
prirodan broj n i niz od n podataka o artiklima. Učitani niz podataka o artiklima sortirati rastuće po
identifikatoru. Na kraju, formatirano ispisati sortirani niz podataka o artiklima, kao i ukupnu cijenu svih
artikala.
Primjer ispisa:
===== ==================== ====== ====== =========
ID NAZIV CIJENA KOL. UKUPNO
===== ==================== ====== ====== =========
11111 Jabuke 2.30 1.00 2.30
22222 Banane 3.10 1.50 4.65
==================================================
 UKUPNO: 6.95
==================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ARTIKAL {
    int id;
    char name [99];
    double quantity;
    double price;
}ARTIKAL;

ARTIKAL product_input (){
    ARTIKAL product;

    printf("==============================\n");
    printf("Identifikator:      ");
    scanf("%d", &product.id);
    printf("Naziv:              ");
    scanf("%s", product.name);
    printf("Cijena:             ");
    scanf("%lf", &product.price);
    printf("Kolicina:           ");
    scanf("%lf", &product.quantity);
    printf("==============================\n");

    return product;
}

int compare_array_elements (const void *a, const void *b){
    ARTIKAL *p1 = (ARTIKAL*) a;
    ARTIKAL *p2 = (ARTIKAL*) b;
    return p1->id - p2->id;
}

void print_products (int n, ARTIKAL array_of_products[]){

    printf("===== ==================== ====== ====== =========\n");
    printf("ID    NAZIV                CIJENA   KOL.    UKUPNO\n");
    printf("===== ==================== ====== ====== =========\n");

    double total = 0;
    for (int i = 0; i < n; i++)
    {
        ARTIKAL p = array_of_products[i];
        double current_total = p.price * p.quantity;

        printf("%-5d %-20s %6.2lf %6.2lf %9.2lf\n", p.id, p.name, p.price, p.quantity, current_total);

        total += current_total;
    }

    printf("==================================================\n");
    printf("                                 UKUPNO: %9.2lf\n", total);
    printf("==================================================\n");
}

int main (){
    int n;
    do
    {
        printf ("Unesite broj n: ");
        scanf ("%d", &n);
    } while (n<0);

    ARTIKAL array_of_products [n];

    for (int i = 0; i<n; i++){
        array_of_products[i] = product_input();
    }
    
    qsort(array_of_products, n, sizeof(ARTIKAL),compare_array_elements);

    print_products(n, array_of_products);
}