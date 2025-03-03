/*
    Dijagramom toka predstaviti
    algoritam koji učitava prirodan 
    broj x, a zatim ispisuje prirodne 
    brojeve iz segmenta [x,2x] koji imaju 
    barem tri neparna delioca (ne uključujući
    broj jedan, kao niti dati broj). Na primer, 
    broj 30 ispunjava dato svojstvo, jer su
    neparni delioci datog broja sledeći brojevi: 3, 5
    i 15.
*/

#include <stdio.h>

int main (int argc, char* argv[]){
    int x;
    printf ("Unesite prirodni broj c: ");
    scanf ("%d", &x);

    for (int i = x; i<= 2*x; i++){
    int counter=0;

        for (int j = 3; j<i; j=j+2){
            if(i%j==0){
                counter++;
            }

        }
            if (counter>=3) printf ("Broj %d ima minimalno tri djelioca \n", i);

    }
}