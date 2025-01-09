/*
    Napisati program koji učitava prirodne brojeve a i b
    (a<b), a zatim ispisuje prirodne brojeve iz 
    segmenta [a,b] koji imaju barem pet delilaca
    (ne uključujući broj jedan, kao niti dati broj).
    Na primer, broj 24 ispunjava dato svojstvo, jer 
    su delioci datog broja sledeći brojevi: 2, 3, 4, 6, 
    8 i 12.
*/

#include <stdio.h>

/*
    Funckija koja provjerava da li dati broj 
    ima pet djelilaca. 

    Kao parametar uzima broj 'number' i
    kroz for petlju iterira od 2 do broj-1
    (po uslovu zadatka), i za svaki broj
    gdje je ostatak djeljenja = 0, dodaje 1 u
    count_divisors. 

    Kada je count_divisors >=5, f-ja vraća 1 (TRUE)
    a ukoliko taj uslov nije ispunjen, vraća 0 (FALSE)
*/

int has_five_divisers (int number){
    int count_divisors=0;
    for (int i = 2; i<number; i++){
        if (number%i==0) count_divisors++;  
        if (count_divisors>=5) return 1;

    }
    return 0;
}
int main (void){
    int a,b;

    do
    {
        printf ("Unesite prirodne brojeve a, b (gdje je a < b)");
        scanf ("%d, %d", &a, &b);
    } while (a>b);

    
    for (int i = a; i<=b; i++){
        if (has_five_divisers(i)) printf ("Broj %d ima pet djelilaca\n ", i);
    }
    
}