#include <stdio.h>

int least_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int least_common_denumenator(int a, int b) {
    return (a * b) / least_common_divisor(a, b);
}

int main() {
    int a, b;
    printf("Unesite dva prirodna broja: ");
    scanf("%d %d", &a, &b);

    printf("NZS od %d i %d je: %d\n", a, b, least_common_denumenator(a, b));
    return 0;
}
