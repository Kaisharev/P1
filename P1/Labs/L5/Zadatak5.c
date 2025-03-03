#include <stdio.h>

// Funkcija za izračunavanje sume djelilaca broja
int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int number1, number2;

    // Unos dva prirodna broja
    printf("Unesite prvi broj: ");
    scanf("%d", &number1);
    printf("Unesite drugi broj: ");
    scanf("%d", &number2);

    int sum1 = sum_divisors(number1);
    int sum2 = sum_divisors(number2);

    if (sum1 == number2 && sum2 == number1) {
        printf("Brojevi %d i %d su prijateljski.\n", number1, number2);
    } else {
        printf("Brojevi %d i %d nisu prijateljski.\n", number1, number2);
    }

    return 0;
}
