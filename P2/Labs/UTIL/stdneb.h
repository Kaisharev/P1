/*  KOLEKCIJA KORISNIH FUNKCIJA ZA LABOVE */
#ifndef STDNEB_H
#define STDNEB_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void malloc_check(void *pointer);
FILE *open_file(char *file_name, char *type);

#endif