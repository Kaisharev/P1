#include "ucitavanje.h"
extern long long* niz;  
extern int n;
void ucitavanje()
{
   
    do scanf("%d", &n); while (n < 1);
    niz = malloc(sizeof(long long)*n);
    for (int i = 0; i < n; ++i)
    scanf("%ld", niz + i);
}