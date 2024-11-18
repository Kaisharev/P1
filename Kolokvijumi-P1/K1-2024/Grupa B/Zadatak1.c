/*
    Napisati program koji učitava prirodan broj n, a zatim
    ispisuje najmanji prost broj veći od učitanog
    broja čiji kvaternarni ekvivalent sadrži cifru 3.
    Na primer, broj 7 je prost, a kvaternarni
    ekvivalent broja 7 (134) sadrži cifru 3. Prirodan
    broj veći od jedan je prost ako je deljiv samo sa
    jedan i samim sobom.
*/

#include <stdio.h>

//Određivanje maksimalne vrijednosti intrigera
#define MAX_INT 2147483647

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
    Funkcija koja provjerava da li dati broj u brojevnom
    sistemu 4 sadrži cifru tri. Funkcija vraća vrijednost 1 (TRUE) 
    ukoliko broj sadrži cifru 3 i vrijednost 0 (FALSE) ukoliko 
    ne sadrži.
*/

int contains_digit_three_in_base_four (int number){
    while (number>0){
        if (number%4==3) return 1;
        number/=4;
    }
    return 0;
}
int main (void){
    int n;
    // Unos prirodnog broja n;

    do{
        printf ("Unesite prirodni broj n: ");
        scanf("%d", &n);
    }while (n<0);

    // Provjera da li su oba uslova iz zadatka ispunjena za svaki broj od 1 do n.
    
       for (int i=n; i<=MAX_INT; i++){
        if (is_prime(i) && contains_digit_three_in_base_four(i)){
            printf ("Broj %d je prost i sadrži cifru 3 u bazi 4", i);
            break;
        }
    }

}
