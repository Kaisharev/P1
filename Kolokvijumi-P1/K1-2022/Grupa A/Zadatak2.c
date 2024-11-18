
/*
    Napisati program u programskom
    jeziku C (dozvoljeno je korištenje funkcija samo
    iz stdio.h) koji učitava realan broj x i prirodan
    broj n, a zatim ispisuje vrednost sledeće sume:
    S=∑(i=0, n) (-1)^i * x^i/i!
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

float power_of (int number, int power){
    float pow=1;
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
    int factoriel_value=1;
    for (int i = 1; i<=number; i++) factoriel_value*=i;
    return factoriel_value;
}


int main (void){
    int x;
    float a;

    printf ("Unesite brojeve a, x: ");
    scanf("%f, %d", &a, &x);

    float sum = 0;

    for (int i = 0; i<=x; i++){
        sum+=power_of(-1, i)*power_of(x, i)/factoriel_of_number(i);
    }

    printf ("Suma brojeva je: %f", sum);
}