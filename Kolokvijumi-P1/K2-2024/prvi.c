#include <stdio.h>
#include <stdlib.h>

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
    } while (path.n<=100||path.k>=2||path.k<=10);
    
    for (int i = 0; i<= path.k; i++){
        printf ("Tacka %d:\n", i+1);
        for (int j = 0; i<path.n; j++){
            printf ("x[%d][%d]", i,j);
            scanf ("%lf", path.x[i][j]);
        }
    }
    return path;
}

