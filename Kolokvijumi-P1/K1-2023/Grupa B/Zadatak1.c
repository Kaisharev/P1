/*
    Napisati program koji učitava prirodne brojeve n i k, a 
    zatim ispisuje prirodne brojeve iz segmenta 
    [1,n] čiji binarni ekvivalent ima k jedinica. Na 
    primer, traženi brojevi za n=15 i k=3 su 7, 11, 
    13 i 14
*/

#include <stdio.h>

/*
    Funkcija koja provjerava da li dati broj u binarnom
    brojnom sistemu ima određeni broj jedinica.

    Funkcija prima dva parametra, number i ammount_of_ones
    odnosno broj i broj jedinica koje tražimo.

    U sebi sadrži varijablu sum. Ukoliko je sum = ammount_of_ones
    vraća 1 (TRUE) ukoliko nije vraća 0 (FALSE)

    Funkcija iterira sve dokle god je naš broj >0 i provjerava
    da li poslednja cifra broja ima ostatak jedan. Ukoliko ima1
    dodaje +1 u vrijednost sum.
*/
int has_k_ones_in_binary (int number, int ammount_of_ones){
    int sum = 0;
    while (number>0)
    {
        if (number%2==1) sum++;
        number/=2;
    }
    if (sum == ammount_of_ones) return 1;
    else return 0;
}



int main (void){

    int n,k;

    printf ("Unesite prirodne brojeve n i k: ");
    scanf ("%d %d", &n, &k);

    for (int i = 1; i<=n; i++){
        if (has_k_ones_in_binary(i, k)) printf ("Broj %d ima %d jedinica u binarnom brojnom sistemu!\n", i, k);
    }

}