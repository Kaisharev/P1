#include <stdio.h>

int main() {
    int n;

    do {
        printf("Unesite prirodan broj n (n <= 30): ");
        scanf("%d", &n);
        if (n <= 0 || n > 30) {
            printf("n mora biti prirodan broj (1 <= n <= 30).\n");
        }
    } while (n <= 0 || n > 30);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
