/*
    Napisati program u programskom 
    jeziku C (dozvoljeno je korištenje funkcija samo 
    iz stdio.h) koji učitava prirodne brojeve n i k 
    (k≤10), a zatim ispisuje vrednost sledeće 
    sume:
    S=∑(n;i=1) sp(i^k) = sp(1)+sp(2^k)+...sp(n^k)

    Gdje je sp(t) suma parnih cifara broja t.
    NPR: sp(128)=2+8=10
*/


#include <stdio.h>

/*
    Funkcija koja računa sumu svih prostih brojeva.
    Kao parametar uzima vrijednost number, odnosno
    broj čiju sumu računamo.

    Unutar funkcije se definišu varijable 'sum' i 'n'.
    Varijabla sum služi da se u njoj računa vrijednost sume, 
    dok varijabla n služi da se u nju pohrani poslednja cifra
    broja 'number'. Ukoliko je ta cifra parna, ona se sabira sa 
    vrijednošću sum.

    Nakon toga, broj se dijeli sa 10, što uklanja njegovu poslednju
    cifru.

    Funkcija iterira sve dokle god je vrijednost number veća od 0.
*/
int sum_even (int number){
    int sum = 0;
    int n;
    while (number>0){
        n=number%10;
        if (n%10==0) sum+=n;
        number/=10;
    }
    return sum;
}

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

int power_of (int number, int power){
    int pow=1;
    for (int i =1; i<=power; i++){
        pow*=number;
    }
    return pow;
}

int main (void){
    int n,k;
    int sum=0;
    printf ("Unesite broj n: ");
    scanf ("%d", &n);
    
    do
    {
        printf ("Unesite broj k (K<=10): ");
        scanf("%d", &k);
    } while (k<=0||k>10);

    for (int i = 1; i<=n; i++){
        sum+=sum_even(power_of(i, k));
    }
    printf ("Suma je: %d", sum);
}