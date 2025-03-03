/*
    DRUGI ZADATAK
    Napisati program u programskom jeziku C 
    (dozvoljeno je korištenje funkcija samo iz stdio.h)
    koji na početku učitava prirodan broj n (n≤10), 
    a zatim učitava realan broj x i
    ispisuje vrednost e^x
    
    Učitavanje broja x i ispis vrednosti e^x 
    treba ponavljati dok god je učitano x≥1. 
    
    Vrednost e^x može da se izračuna
    korištenjem sledeće formule:

    e^x=1+x/1!+x^2/2!+x^3/3!+...+x^n/n!
*/


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
float power_of_number (int number, int power){
    int pow=1;
    for (int i = 1; i<=power; i++){
        pow*=number;
    }
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
float factoriel_of_number (int number){
    int factoriel_value=1;
    for (int i =1; i<=number; i++){
        factoriel_value*=i;
    }
    return factoriel_value;
}
#include <stdio.h>

int main (void){

    int n,x;
    float e=1.0;

    // Unos broja n, gdje je n<=10

    do
    {
        printf ("Unesite cijelobrojni broj n, gdje n<=10: ");
        scanf("%d", &n);
    } while (n<0 ||n>10);

    // Računanje e^x dokle god je unešeno x >= 1
    
    do
    {
        printf("Unesite broj x: ");
        scanf ("%d", &x);
        for (int i = 1; i<=n; i++){
            e+=power_of_number(x,i)/factoriel_of_number(i);
        }
        printf ("Vrijednost e^%d je %f\n", x, e);
    } while (x>=1);
    
    

}