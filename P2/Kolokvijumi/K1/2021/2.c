/*
Napisati funkciju init koja kao obavezne
parametre prihvata pokazivač na funkciju (parametar
u), adresu nekog cijelog broja (parametar pn) i cijeli
broj n, a zatim n realnih brojeva tipa double
(neobavezni parametri).
Parametar u predstavlja pokazivač na funkciju koja
provjerava da li je ispunjen neki uslov za dati realan
broj (funkcija vraća vrijednost 0 ako uslov nije
ispunjen, a vrijednost 1 ako uslov jeste ispunjen).
Funkcija init treba da od realnih brojeva (neobavezni
parametri) koji ispunjavaju dati uslov, formira i vrati
dinamički niz. Preko parametra pn funkcija treba da
vrati broj elemenata formiranog niza. Ako dati uslov
nije ispunjen niti za jedan realan broj, funkcija init
treba da vrati NULL.
Prototip funkcije init je:
double* init(int (*u)(double), int *pn, int n, ...);
*/

#include <stdio.h>
#include <stdarg.h>

double *init(int (*u)(double), int *pn, int n, ...)
{
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i++)
    {
        double num = va_arg(list, double);
        if ((*u)(num))
        {
            (*pn)++;
        }
    }
    double *array = (double *)malloc(*pn * sizeof(double));
    va_end(list);
    va_start(list, n);
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        double num = va_arg(list, double);
        if ((*u)(num))
        {
            array[counter++] = num;
        }
    }

    if (*pn == 0)
    {
        return NULL;
    }
    else
    {
        return array;
    }
}