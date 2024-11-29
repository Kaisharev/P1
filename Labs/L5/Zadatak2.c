#include <stdio.h>

int main() {
    int n;
    double number, smallest_number;

    printf("Unesite prirodan broj n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Broj n mora biti pozitivan!\n");
        return 1;
    }

    printf("Unesite broj: ");
    scanf("%lf", &smallest_number); 

    for (int i = 1; i < n; i++) {
        printf("Unesite broj: ");
        scanf("%lf", &number);
        if (number < smallest_number) {
            smallest_number = number;
        }
    }

    printf("Najmanji broj je: %.2lf\n", smallest_number);
    return 0;
}
