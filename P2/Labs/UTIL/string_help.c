/*
=== STRING.H - CHEATSHEET ===
*/
// Dužina stringa (bez '\0')
size_t strlen(const char *str);

// Kopiranje (NEMA provjere granica!)
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// Nadovezivanje (NEMA provjere granica!)
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

// Usporedba (vraća <0, 0, >0)
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);

// Pretraga znakova
char *strchr(const char *str, int c);                   // Prva pojava
char *strrchr(const char *str, int c);                  // Zadnja pojava
char *strstr(const char *haystack, const char *needle); // Podstring
char *strpbrk(const char *str, const char *accept);     // Bilo koji znak iz accept

// Tokenizacija
char *strtok(char *str, const char *delim); // Koristi s NULL za nastavak

// Rad s memorijom
void *memcpy(void *dest, const void *src, size_t n);      // Bez preklapanja!
void *memmove(void *dest, const void *src, size_t n);     // S preklapanjem
void *memset(void *ptr, int c, size_t n);                 // Postavljanje bajtova
int memcmp(const void *ptr1, const void *ptr2, size_t n); // Usporedba memorije
void *memchr(const void *ptr, int c, size_t n);           // Traži znak u memoriji

// Specijalno
char *strerror(int errnum);                          // Tekst greške
size_t strspn(const char *str, const char *accept);  // Početni segment accept
size_t strcspn(const char *str, const char *reject); // Početni segment bez reject
                                                     /*
                                                     === NAPOMENE ===
                                                     - Uvijek includaj: #include <string.h>
                                                     - Funkcije s 'n' u imenu (npr. strncpy) su sigurnije (ograničen buffer size)
                                                     - strtok koristi interni state - NIJE thread-safe!
                                                     - memcpy i memmove: memcpy je brži, ali memmove podržava preklapanje
                                                     */