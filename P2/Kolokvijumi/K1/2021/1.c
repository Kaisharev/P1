/*
Napisati rekurzivnu funkciju invert koja
kao parametre prima niz stringova (parametar niz) i
cijeli broj n koji predstavlja broj stringova u nizu.
Funkcija invert invertuje svaki string u nizu i vraća na
istu poziciju u niz. Invertovani string ne smije da sadrži
cifre. Obradu svakog stringa potrebno je vršiti u
odvojenom rekurzivnom pozivu.
Prototip funkcije invert je:
void invert(char **niz, int n);

*/
#include <ctype.h>
#include <string.h>
#include <stdio.h>
void invert_string(const char *input, char *output, int position)
{
    if (position < 0)
    {
        *output = '\0';
        return;
    }

    if (!isdigit(input[position]))
    {
        *output = input[position];
        invert_string(input, output + 1, position - 1);
    }
    else
        invert_string(input, output, position - 1);
}
void invert(char **niz, int n)
{
    if (n < 0)
        return;
    int string_length = strlen(niz[0]);
    char *inverted_string = (char *)calloc(string_length + 1, sizeof(char));
    invert_string(niz[0], inverted_string, string_length);
    strcpy(niz[0], inverted_string);
    free(inverted_string);
    invert(niz + 1, n - 1);
}