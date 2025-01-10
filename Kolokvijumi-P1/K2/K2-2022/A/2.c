#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct duz {
 double duzina;
} DUZ;
typedef struct trougao {
 DUZ a, b, c;
} TROUGAO;

int validan(DUZ a, DUZ b, DUZ c){
     if (a.duzina + b.duzina <= c.duzina || a.duzina + c.duzina <= b.duzina || b.duzina + c.duzina <= a.duzina) return 0;
     return 1;
}

TROUGAO ucitaj(){
    TROUGAO triangle;
    do
    {
        printf ("Unesite stranice a, b, c: ");
        scanf ("%lf, %lf, %lf", &triangle.a.duzina, &triangle.b.duzina, &triangle.c.duzina);
    } while (!validan(triangle.a, triangle.b, triangle.c));
    
    
    return triangle;
}

int podudarni(TROUGAO *t1, TROUGAO *t2){
    if (t1->a.duzina == t2->a.duzina && t1->b.duzina == t2->b.duzina && t1->c.duzina == t2->c.duzina) return 1;
    return 0;
}

double povrsina(TROUGAO *t){
    double semi_circumference = (t->a.duzina+t->b.duzina+t->c.duzina)/2;
    double area = sqrt(semi_circumference*(semi_circumference-t->a.duzina)*(semi_circumference-t->b.duzina)*(semi_circumference-t->c.duzina));

    return area;
}

int main (int argc, char *argv){
    TROUGAO triangle = ucitaj();

    printf ("Površina trougla je: %lf", povrsina(&triangle));
}