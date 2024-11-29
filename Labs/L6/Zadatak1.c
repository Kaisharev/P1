/*
    Napisati program (bez korištenja funkcija iz math.h) koji učitava 
    prirodan broj b, a zatim ispisuje vrijednost sljedeće sume:

    Σ(i, k-1) b(i)^i+1
    gdje je bi cifra na poziciji i broja b koji ima k cifara 
    (tj. b=b(k-1),b(k-2)...b2,b1, b0). Na primjer, vrijednost 
    tražene sume za broj 2534 je 154 (2^4 + 5^3 + 3^2 + 4^1 = 16 + 125 + 9 + 4 = 154).

*/
#include <stdio.h>
double power_of (double argument, double exponent){
    double pow_value=1;
    for (int i = 1; i<=exponent; i++){
        pow_value*=argument;
    }
    return pow_value;
}

int main (void){

    int number;
    printf ("Unesite prirodan broj N: ");
    scanf ("%d", &number);
 
    double sum = 0;
    int counter = 1;
    while (number >0){
        sum+=power_of((number%10), counter);
        counter++;
        number/=10;
    }
    printf ("Suma broja je: %d", (int) sum);
}