#include <stdio.h>
#include <stdlib.h>

typedef struct put {
 double x[20][50]; // koordinate tacaka
 int d; // dimenzija prostora, 1 <= d <= 50
 int n; // broj tacaka, 2 <= n <= 20
} PUT;


void ucitaj (PUT *p){
    do
    {
        printf ("Unesite broj dimenzija i broj tačaka prostora: ");
        scanf ("%d %d", &p->d, &p->n);
    } while (p->d>50|| p->d<1 || p->n<2 || p->n>20);

    for (int i = 0; i<p->n; i++){
        printf ("Tacka %d:\n", i+1);
        for (int j = 0; j<p->d; j++){
            printf ("x[%d][%d]", i,j);
            scanf ("%lf", &p->x[i][j]);
        }
    }
}

double duzina (const PUT *p){
    double length = 0; 
    for (int i = 0; i<p->n; i++){
        double sum = 0;
        for (int j = 0; j<p->d; j++){
            sum += (p->x[i+1][j]- p->x[i][j])*(p->x[i+1][j]- p->x[i][j]);
        }
        length+=sqrt(sum);
    }
    return length;
}
int main (void){
    PUT pathOne, pathTwo;
    ucitaj(&pathOne);
    ucitaj(&pathTwo);

    if (duzina(&pathOne) == duzina(&pathTwo)){
        printf ("Putanje su iste\n");
    }else{

        printf ("Putanje nisu iste\n");
    }
}