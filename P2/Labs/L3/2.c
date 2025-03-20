#include <stdio.h>
#include <stdlib.h>

int is_even(int n) {
    return n % 2 == 0;
}

int is_positive(int n) {
    return n > 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina) {
    *duzina = 0;
    *pocetak = NULL;

    int current_length = 0;
    int *current_start = NULL;

    for (int i = 0; i < n; i++) {
        if (s(niz[i])) {
            current_length++;

            if (current_start == NULL) {
                current_start = &niz[i];
            }
        } else {
            if (current_length > *duzina) {
                *duzina = current_length;
                *pocetak = current_start;
            }

            current_length = 0;
            current_start = NULL;
        }
    }

    if (current_length > *duzina) {
        *duzina = current_length;
        *pocetak = current_start;
    }
}

void write_subarray(int *pocetak, int duzina, const char *opis) {
    printf("%s: ", opis);
    for (int i = 0; i < duzina; i++) {
        printf("%d ", pocetak[i]);
    }
    printf("\n");
}

int main() {
    int n;

    do {
        printf("Unesite veličinu niza : ");
        scanf("%d", &n);
    } while (n < 1 && printf("Veličina mora biti pozitivna!\n"));

    int niz[n];

    for (int i = 0; i < n; i++) {
        printf("Unesite %d elemenat:\n", i+1);

        scanf("%d", &niz[i]);
    }

    int *even_start;
    int even_length;
    serija(niz, n, is_even, &even_start, &even_length);

    int *positive_start;
    int positive_length;
    serija(niz, n, is_positive, &positive_start, &positive_length);

    write_subarray(even_start, even_length, "Najduži podniz parnih brojeva");
    write_subarray(positive_start, positive_length, "Najduži podniz pozitivnih brojeva");

    return 0;
}