#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct putanja {
 double x[10][100]; // koordinate tacaka
 int n; // dimenzija prostora, 1 <= n <= 100
 int k; // broj tacaka, 2 <= k <= 10
} PUTANJA;

PUTANJA ucitaj(){
    PUTANJA path;
    do
    {
        printf ("\nUnesite brojeve n i k: ");
        scanf ("%d %d", &path.n, &path.k);
    }while (path.n > 100 || path.k < 2 || path.k > 10);
    
    for (int i = 0; i< path.k; i++){
        printf ("Tacka %d:\n", i+1);
        for (int j = 0; j<path.n; j++){
            printf ("x[%d][%d]", i,j);
            scanf ("%lf", &path.x[i][j]);
        }
    }
    return path;
}

double duzina (const PUTANJA *put){
    double length = 0.0;
    for (int i = 0; i<put->k; i++){
        double sum = 0.0;
        for (int j = 0; j<put->n; j++){
            sum +=pow((put->x[i+1][j]- put->x[i][j]),2);
        }
        length+=sqrt(sum);
    }

    return length;
}


int main (void){
    PUTANJA putanja = ucitaj();
    double putanja_duzina = duzina(&putanja);

    printf ("DUzina putanje je: %lf", putanja_duzina);
}