#include "ucitavanje.h"
#include "izracunavanje.h"
long long* niz;
int n;
int main()
{
 ucitavanje();
 for (int i = 0; i < n; ++i)
 niz[i] = faktorijel((int)niz[i]);
 printf("%ld", suma(niz, n));
 free(niz);
 return 0;
}
