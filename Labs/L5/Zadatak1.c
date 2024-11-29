#include <stdio.h>

int main() {
    int n, broj, brojacPozitivnih = 0;

    printf("Unesite prirodan broj n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Unesite broj: ");
        scanf("%d", &broj);
        if (broj > 0) {
            brojacPozitivnih++;
        }
    }

    printf("Broj pozitivnih brojeva je: %d\n", brojacPozitivnih);
    return 0;
}
