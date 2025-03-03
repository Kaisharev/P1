/*
Napisati program u programskom
jeziku C (dozvoljeno je korištenje funkcija samo
iz stdio.h) koji učitava realan broj x i prirodan
broj k, a zatim ispisuje vrednost sledeće sume:
S=1/x+ 2!/x^2 + 3!/x^3 + ... + k!/x^k= ∑(j=1, k) j!/x^j
*/

#include <stdio.h>

/*
    Funkcija koja računa broj dignut na neki stepen.
    Kao parametre uzima vrijednost number i power,
    odnosno broj i stepen na koji se taj broj treba dići.

    Ova funkcija u sebi ima vrijednost pow, u kojoj
    se upisuje proizvod broja. 

    Funkcija iterira kroz petlju onoliko puta
    koliko dižemo dati broj, i vrijednost pow množi 
    sa tim brojem.
*/

float power_of (float number, int power){
    float pow = 1;
    for (int i = 1; i<=power; i++) pow*=number;    
    return pow;
}

/*
    Funkcija koja računa faktorijel broja.
    Kao parametre uzima cijelobrojni broj
    i vraća vrijednost faktorijela.

    Funkcija iterira kroz petlju onoliko puta
    kolika je vrijednost broja koji faktorišemo,
    i vrijednost factoriel_value množi sa iteratorom.
*/
int factoriel_of_number (int number){
    int factoriel_value = 1;
    for (int i = 1; i<=number; i++) factoriel_value*=i;
    return factoriel_value;
}

int main (void){

    int k; 
    float x;

    printf ("Unesite brojeve x, k: ");
    scanf ("%f, %d", &x, &k);
    float sum = 0;
    for (int i = 1; i<=k; i++) sum+=factoriel_of_number(i)/power_of(x,i);
    printf ("Suma je: %f", sum);
}