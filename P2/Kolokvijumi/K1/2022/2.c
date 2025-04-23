/*
Neka je dat tip:
typedef struct predmet {
 char id[15]; //identifikator
 char naziv[64];
 int ects;
} PREDMET;
 kojim se reprezentuju informacije o jednom predmetu.
Napisati funkciju fun sa promjenljivim brojem
argumenata koja prihvata pokazivač na funkciju
(parametar u), cijeli broj n i n pokazivača na PREDMET
(neobavezni argumenti).
Parametar u predstavlja pokazivač na funkciju koja
provjerava da li je ispunjen neki uslov za dati PREDMET
(funkcija vraća vrijednost 0 ako uslov nije ispunjen, a
vrijednost 1 ako uslov jeste ispunjen).
Funkcija fun treba da podatke o predmetima
(neobavezni argumenti) koji ispunjavaju dati uslov
upiše u binarnu datoteku sa nazivom
"predmeti_izlazna.dat".
Prototip funkcije fun je:
void fun(int (*u)(PREDMET *), int n,...);
Napisati funkciju provjeri_sadrzaj koja za zadati
predmet (parametar p) provjerava da li se nalazi u
tekstualnoj datoteci sa nazivom "predmeti_ulazna.txt".
Ukoliko su podaci o predmetu upisani u datoteku,
funkcija treba da vrati 1, inače treba da vrati 0.
Predmeti su jednaki ukoliko su im jednaki identifikatori.
U svakom redu datoteke je upisan podatak o jednom
predmetu u sljedećem formatu: identifikator naziv ects.
Prototip funkcije provjeri_sadrzaj je:
int provjeri_sadrzaj(PREDMET *p);

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
typedef struct predmet
{
    char id[15]; // identifikator
    char naziv[64];
    int ects;
} PREDMET;
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
void fun(int (*u)(PREDMET *), int n, ...)
{
    va_list args;
    va_start(args, n);
    FILE *fp_output = open_file("predmeti_izlazna.dat", "wb");
    for (int i = 0; i < n; i++)
    {
        PREDMET *predmet = va_arg(args, PREDMET *);

        if ((*u)(&predmet))
        {
            fwrite(&predmet, sizeof(PREDMET), 1, fp_output);
        }
    }
    fclose(fp_output);
}

int provjeri_sadrzaj(PREDMET *p)
{
    FILE *fp_input = open_file("predmeti_ulazna.dat", "rb");
    PREDMET predmet;
    while (fread(&predmet, sizeof(PREDMET), 1, fp_input) == 1)
    {
        if (strcmp(predmet.id, (*p).id) == 0)
            return 1;
        return 0;
    }
}