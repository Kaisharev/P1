/*
    Napisati program u programskom
    jeziku C (dozvoljeno je korištenje funkcija samo
    iz stdio.h) koji učitava realan broj x i prirodan
    broj k, a zatim ispisuje vrednost sledeće sume:

    S= 1/x+2!/x^2+3!/x^3+...+k!/x^k=∑(j=1, k)
*/


#include <stdio.h>

int main (int argc, char* argv[]){
    int k; 
    float x;

    printf ("Unesite realan broj x i prirodni broj k (x, k): ");
    scanf ("%f, %d", &x, &k);
    float sum=1/x;

    for (int i = 2; i<=k; i++){
        // stepen broja
        int power_of=1;
        for (int pow= 1; pow<=i; pow++) power_of*=x;

        float factoriel_of=1.0;
        for (int fac=1; fac<=i; fac++) factoriel_of*=fac;

        sum+=factoriel_of/power_of;
    }

    printf ("Suma je: %f", sum);
}