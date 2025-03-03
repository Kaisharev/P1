/*
    Napisati program koji učitava prirodan broj n, a zatim ispisuje najmanji prost broj veći od učitanog broja.

*/

#include <stdio.h>
int next_smallest_prime (int number){
       int next_prime = number+1;
       while (!is_prime(next_prime)){
        next_prime++;
       }
    return next_prime;
}
int main (){
    int number;
    printf ("Unesite prirodan broj N: ");
    scanf ("%d", &number);

    printf ("Najmanji prost broj veći od %d je %d", number, next_smallest_prime(number));

}