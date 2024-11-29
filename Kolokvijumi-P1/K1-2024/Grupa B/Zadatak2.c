/*
    Napisati program u programskom
    jeziku C (dozvoljeno je korištenje funkcija samo
    iz stdio.h) koji učitava prirodne brojeve a, b
    (a<b) i k (k≤10), a zatim ispisuje sledeće
    vrednosti: e^a, e^a+0.5, e^a+1... e^b-0.5, e^b.

    Vrednost e^x može da se izračuna
    korištenjem sledeće formule:

    e^x=1+x/1!+x^2/2!+x^3/3!+...+x^k/k!
*/

/*
    NAPOMENA: Zbog određenih pravila jezika C, sve vrijednosti 
    tipa int se moraju eksplicitno prebaciti u float, te zbog
    toga se na par mjesta pojavljajuje (float) ispred neke
    vrijednosti.

    Postoji i drugi metod da se ovaj zadatak uradi, a to je
    da svi podaci budu tipa float. 
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
float power_of_digit (int number, float power){
    float pow_value = 1.0;
    for (float i = 1; i<=power; i+=(float)0.5){
        pow_value*=(float)number;
    }
    return pow_value;
}

/*
    Funkcija koja računa faktorijel broja.
    Kao parametre uzima cijelobrojni broj
    i vraća vrijednost faktorijela.

    Funkcija iterira kroz petlju onoliko puta
    kolika je vrijednost broja koji faktorišemo,
    i vrijednost factoriel_value množi sa iteratorom.
*/

float factoriel_of_number (float number){
    float factoriel_value = 1.0;
    for (int i = 1; i<=number; i++){
        factoriel_value*=(float)i;
    }
    return factoriel_value;
}

int main (void){

    int a,b;
    float e=1.0;

    // Unos brojeva a i b, gdje je a < b
    do
    {
        printf("Unesite brojeve a, b gdje je a<b: ");
        scanf ("%d, %d", &a, &b);
    } while (a>b);

    // Unos prirodnog broja k koji je manji od 10
    int k = 0;
    do
    {
        printf("Unesite broj (k<=10): ");
        scanf ("%d", &k);
    } while (k>10|| k<=0);

    // Ispis vrijednosti broja e onoliko puta koliki je interval a,b.
    for (float i =(float)a; i<=b; i+=(float)0.5){
        e+=power_of_digit(k,i)/factoriel_of_number(i);
        printf ("Vrijednost e^%d=%.1f je %f\n", k,i,e);
    }
    
}