/*  KOLEKCIJA KORISNIH FUNKCIJA ZA LABOVE */
#ifndef STDNEB_H
#define STDNEB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


#define print_value(x) _Generic((x), \
    int: print_int, \
    double: print_double, \
    float: print_float, \
    char: print_char, \
    char*: print_string, \
    const char*: print_string, \
    long: print_long, \
    unsigned int: print_unsigned_int, \
    default: print_unknown)(x)

void print_int(int val) { printf("%d", val); }
void print_double(double val) { printf("%f", val); }
void print_float(float val) { printf("%f", val); }
void print_char(char val) { printf("%c", val); }
void print_string(const char* val) { printf("%s", val); }
void print_long(long val) { printf("%ld", val); }
void print_unsigned_int(unsigned int val) { printf("%u", val); }
void print_unknown(const void* val) { printf("<unknown type>"); }

// This is the macro you actually use:
#define print(...) do { \
    void *_args[] = { (print_value(__VA_ARGS__), NULL)... }; \
    (void)_args; \
    printf("\n"); \
} while(0)
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
#endif