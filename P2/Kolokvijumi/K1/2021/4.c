/*
Napisati nerekurzivnu funkciju pretrazi
koja binarno pretražuje niz od n cijelih brojeva tipa long
long, pri čemu je ključ pretrage zadat kao parametar
funkcije (kljuc).
U slučaju uspješne pretrage funkcija pretrazi vraća
indeks pronađenog elementa, a u slučaju neuspješne
pretrage funkcija vraća -1.
Prilikom pretrage, posjećene elemente niza (elemente
niza sa kojima je vršeno poređenje) potrebno je
upisivati u binarnu datoteku čiji je naziv zadat kao
parametar funkcije (parametar dat_naziv).
Prototip funkcije pretrazi je:
*/
#include <stdio.h>
#include <stdlib.h>

FILE *open_file(const char *file_name, const char *type)
{
    FILE *fp = fopen(file_name, type);
    if (!fp)
    {
        perror("Greška: ");
        exit(EXIT_FAILURE);
    }
    return fp;
}
int pretrazi(const char *dat_naziv, long long *niz, int n, long long kljuc)
{
    FILE *fp_output = open_file(dat_naziv, "ab");
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        fwrite(&niz[mid], sizeof(long long), 1, fp_output);

        if (niz[mid] == kljuc)
        {
            return mid; // Found the target
            break;
        }
        else if (niz[mid] < kljuc)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }
    fclose(fp_output);
    return -1; // Target not found
}
