/*  KOLEKCIJA KORISNIH FUNKCIJA ZA LABOVE */
#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void malloc_check(void *pointer);
FILE *open_file(char *file_name, char *type);

#if defined(__linux__)
#define cls() system("clear")
#elif defined(_WIN32)
#define cls() system("cls")
#else
#define cls()

#endif