#include <stdio.h>

int suma(int *niz, int n){
    if (n == 0)
    return 0;
  else
    return niz[n - 1] + suma(niz, n - 1);

}

int main(){
    int i, n;
    int niz[50];
    do printf("n="), scanf("%d", &n); while (!n || n > 50);
    for (i = 0; i < n; i++)
    { 
        printf("%d. broj: ", i + 1); scanf("%d", niz + i);
    }
    printf("Suma: %.2d", suma(niz, n));
    return 0;
}