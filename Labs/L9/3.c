/*Definisati tip KOMPLEKS kojim se reprezentuje kompleksan broj (svaki kompleksan broj ima realni i
imaginarni dio). Napisati program koji učitava prirodan broj n i niz od n kompleksnih brojeva. Učitani niz
kompleksnih brojeva sortirati opadajuće po modulu. Na kraju, ispisati sortirani niz kompleksnih brojeva */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} KOMPLEKS;

KOMPLEKS complex_number_input (){
    KOMPLEKS number;
    scanf ("%lf %lf", &number.re, &number.im);
    return number;
}

double complex_number_modulo (KOMPLEKS c){
    return sqrt((c.re*c.re)+(c.im*c.im));
}
int compare_complex_number_modulo (const void *a, const void *b){
    KOMPLEKS *c1 = (KOMPLEKS*) a;
    KOMPLEKS *c2 = (KOMPLEKS*) b;

    return complex_number_modulo(*c2)-complex_number_modulo(*c1);
}

void print_complex_number(KOMPLEKS c){
    printf ("%.2lf+.2lf", c.re, c.im);
}
int main (){
    int n;
    do
    {
        printf ("Unesite prirodan broj n: ");
        scanf ("%d", &n);
    } while (n<0);

    KOMPLEKS array_of_complex_numbers[n];

    for (int i = 0; i<n; i++){
        printf ("Unesite %d komplesan broj: ", i+1);
        array_of_complex_numbers[i]=complex_number_input();
    }

    qsort (array_of_complex_numbers, n, sizeof(KOMPLEKS),compare_complex_number_modulo);

    for (int i = 0; i<n; i++){
        print_complex_number(array_of_complex_numbers[i]);
        printf("\n");

    }
    

}