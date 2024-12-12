/*Definisati tip RAZLOMAK kojim se reprezentuje razlomak (svaki razlomak ima cjelobrojni imenilac i prirodni
brojilac). Napisati program koji učitava dva razlomka, a zatim ih sabira te ispisuje rezultujući razlomak. Uzeti
u obzir kraćenje rezultujućeg razlomka.*/
#include <math.h>
#include <stdio.h>

typedef struct RAZLOMAK {
    int numerator;
    int denominator;
} RAZLOMAK;

RAZLOMAK fraction_input (){
    RAZLOMAK fraction;
    scanf ("%d/%d", &fraction.numerator, &fraction.denominator);
    return fraction;
}

int greatest_common_denominator(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

RAZLOMAK add_fraction (RAZLOMAK f1, RAZLOMAK f2){
    RAZLOMAK sum;
    sum.numerator=f1.numerator*f2.denominator+f2.numerator*f1.denominator;
    sum.denominator=f1.denominator*f2.denominator;
    return sum;
}

RAZLOMAK shorten_fraction (RAZLOMAK f){
    int divisor = greatest_common_denominator(f.numerator, f.denominator);
    f.denominator/= divisor;
    f.numerator/=divisor;
    return f;
}

void print_fraction (RAZLOMAK f1, RAZLOMAK f2, RAZLOMAK sum){
    printf ("Zbir razlomaka %d/%d i %d/%d je: %d/%d", f1.numerator, f1.denominator, f2.numerator, f2.denominator, sum.numerator, sum.denominator);
}
int main (){
    RAZLOMAK f1 = fraction_input(), f2=fraction_input();
    RAZLOMAK sum = shorten_fraction(add_fraction(f1,f2));

    print_fraction(f1,f2,sum);

}