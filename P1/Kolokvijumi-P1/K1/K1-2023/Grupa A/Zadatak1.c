/*
    Napisati program koji učitava prirodne brojeve a i b
    (a<b), a zatim ispisuje prirodne brojeve iz
    segmenta [a,b] čiji binarni ekvivalent ima
    barem tri jedinice. Na primer, broj 11 ispunjava
    dato svojstvo, jer je 11=1011(2).
*/

#include <stdio.h>

/*
    Funkcija koja provjerava da li unešeni broj
    sadrži tri cifre tri u binarnom brojevnom sistemu
*/
int has_three_digits_one_in_binary (int number){
    int sum = 0;
    while (number>0){
        if (number%2==1) sum++;
        if (sum==3) return 1;
        number/=2;
    }
    return 0;
}

int main (void){

    int a,b;

    do
    {
        printf ("Unesite brojeve a, b gdje je a < b: ");
        scanf ("%d, %d", &a, &b);    
    } while (a>b);

    for (int i =a; i<=b; i++){
        if (has_three_digits_one_in_binary(i)) printf ("Broj %d ima tri cifre 1 u binarnom\n", i);
    }
    

}