/*
Dijagramom toka predstaviti
algoritam koji učitava prirodan broj d, a zatim
ispisuje da li je za njega ispunjeno sledeće
svojstvo:
    d1*d2*...*dk = ∑(i=1, k)di^d

gde je di i-ta cifra broja d koji ima k cifara. 
Pri tome, uzeti da je 0^0=1. Na primer, za broj 
3435 jeste ispunjen dati uslov, jer je:
*/

#include <stdio.h>

int pow (int number, int exponent){
    int value=1;
    for (int i = 1; i<=exponent; i++){
        value *=number;
    }
    return value;
}
int main (void){ 

    int d;
    do{
        printf ("Unesite prirodni broj n: "); 
        scanf ("%d", &d);
    }while (d<0);

    int sum = 0;
    int last_digit=1;
    int holder = d;
    while (holder>0)
    {
        last_digit = holder%10;
        sum += pow(last_digit, last_digit);
        holder/=10;
    }

    if (sum == d) printf ("Ispunjen je uslov!");
    else printf ("Uslov nije ispunjen!");

}