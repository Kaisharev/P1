/*  KOLEKCIJA KORISNIH FUNKCIJA ZA LABOVE */

#include <stdlib.h>
#include <string.h>

void malloc_check(void *pointer)
{
    if (pointer == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

FILE *open_file(char *file_name, char *type)
{
    FILE *fp = fopen(file_name, type);
    if (fp == NULL)
    {
        perror("Greska pri otvaranju!");
        exit(EXIT_FAILURE);
    }
    return fp;
}