#include <stdio.h>
#include <stdlib.h>

typedef struct duz { float duzina; } DUZ;
typedef struct trougao { DUZ a, b, c;} TROUGAO;

int validan(float a, float b, float c){
    if (a+b>=c||a+c>=b || b+c>=a) return 0;
    return 1;
}
void ucitaj(TROUGAO *t){
    do
    {
        printf ("Unesite stranice trougla a, b, c: ");
        scanf ("%lf %lf %lf", &t->a.duzina, &t->b.duzina, &t->c.duzina);
    } while (validan(t->a.duzina, t->b.duzina, t->c.duzina));
    
}

int podudarni(TROUGAO t1, TROUGAO t2){
    if (t1.a.duzina == t1.a.duzina && t1.b.duzina == t2.b.duzina && t1.c.duzina == t2.c.duzina) return 1;
    else return 0; 
}
float r(TROUGAO *t){

    return sqrt(t->a.duzina*t->b.duzina*t->c.duzina/(t->a.duzina+t->b.duzina+t->c.duzina)*(t->b.duzina+t->c.duzina-t->a.duzina)*(t->c.duzina+t->a.duzina-t->b.duzina)*(t->a.duzina+t->b.duzina-t->c.duzina));
}