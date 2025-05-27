#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *sifra, *naziv;
} PREDMET;

typedef struct
{
    char *br_indeksa, *ime, *prezime;
    PREDMET *niz;
    int n;
} STUDENT;