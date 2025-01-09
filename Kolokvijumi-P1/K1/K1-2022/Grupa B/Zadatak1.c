/*
    Napisati program koji učitava prirodan broj x, a zatim 
    ispisuje prirodne brojeve iz segmenta [x,2x]
    koji imaju barem tri neparna delioca (ne
    uključujući broj jedan, kao niti dati broj). Na
    primer, broj 30 ispunjava dato svojstvo, jer su
    neparni delioci datog broja sledeći brojevi: 3, 5
    i 15.    
*/

#include <stdio.h>

int has_three_odd_divisors (int number){
    int count_divisors=0;

    for (int i = 3; i<number; i=i+2){
        if (number%i==0) count_divisors++;
        if(count_divisors>=3) return 1;
    }
    return 0;
}

int main (void){

    int x;
    do
    {
        printf("Unesite prirodan broj x: ");
        scanf ("%d", &x);
    } while (x<0);
    
    for (int i = x; i<=2*x; i++){
        if (has_three_odd_divisors(i)) printf("Broj %d ima tri neparna djelioca \n", i);
    }
}