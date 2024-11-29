/*
    Napisati program u programskom 
    jeziku C (dozvoljeno je korištenje funkcija samo 
    iz stdio.h) koji učitava prirodne brojeve s i t 
    (t≤10), a zatim ispisuje vrednost sledeće sume:

    S=∑(s;i=1) pr(i^t) = pr(1)+pr(2^t)+...pr(n^t)

    gde je pr(n) suma prostih cifara (2, 3, 5 i 7) 
    broja n. Na primer, pr(32768)=3+2+7=12.
*/

#include <stdio.h>

/*
    Funkcija koja provjerava da li je neki broj prost 
    Funkcija vraća vrijednost 1 (TRUE) ukoliko je broj 
    prost i vrijednost 0 (FALSE) ukoliko broj nije prost.
*/
int is_prime(int number){
    // Ukoliko je broj < 2, on nije prost.
    if (number < 2) return 0;

    for (int i = 2; i*i<=number; i++){
        if (number%i==0) return 0;
    }
    return 1;
}

/*
    Funkcija koja računa sumu cifara prostih brojeva.
    Kao parametar uzima vrijednost 'number', odnosno
    broj nad kojim računamo suma njzgovih prostih cifara.

    U funkciji se nalaze dvije varijable 'sum_digits' i
    'last_digit'. Dokle god je broj > 0, funkcija uzima
    njegovu zadnju cifru i poziva funkciju 'is_prime'. 

    Ukoliko je cifra prosta, sabira njenu vrijednost sa 
    vrijednošću sum_digit, te od broja oduzima zadnju cifru.

    Funckija će se iterirati sve dokle god je broj >0.

    Kao povratnu vrijednost, ova funkcija vraća varijablu sum_digits.
*/
int sum_prime (int number){
    int sum_digits;
    int last_digit;
    
  

    while (number > 0){
        last_digit=number%10;
        if (is_prime(last_digit)) sum_digits+=last_digit;
        number/=10;
              
    }
      
    
    return sum_digits;
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
    int s, t;

    printf ("Unesite broj s: ");
    scanf ("%d", &s);

    do
    {
        printf ("Unesite broj t: ");
        scanf("%d", &t);
    } while (t<0||t>10);

    int sum = 0;
    for (int i = 1; i<=s; i++){
        sum+=sum_prime(power_of(i,t));
    }
    
}