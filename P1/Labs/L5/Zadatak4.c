#include <stdio.h>

int sum_of_digits(int number) {
    int suma = 0;
    while (number != 0) {
        suma += number % 10;
        number /= 10;
    }
    return suma;
}

int main() {
    int number;
    printf("Unesite prirodan broj: ");
    scanf("%d", &number);

    printf("Suma cifara broja %d je: %d\n", number, sum_of_digits(number));
    return 0;
}
