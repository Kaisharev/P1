#include <stdio.h>

unsigned suma(unsigned b){
   if (b==0) return 0;
   else return b%10+suma(b/10);

}

int main(){
    unsigned n;
    printf ("Unesite broj n: ");
    scanf ("%u", &n);

    printf ("Suma cifara broja %u je %u", n, suma(n));
}