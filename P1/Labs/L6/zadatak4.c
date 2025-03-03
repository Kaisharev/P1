#include <stdio.h>
#include <math.h>

#define EPS 1e-5
double nth_root(double x, int n, double precision) {
    double x_prev, x_curr;
    x_curr = (x + 1.0) / n; 
    
    do {
        x_prev = x_curr;
        x_curr = (1.0 / n) * ((n - 1) * x_prev + x / pow(x_prev, n - 1));
    } while (fabs(x_curr - x_prev) > precision); 
    
    return x_curr;
}

int main() {
    double x, result;
    int n;

    // Input: x and n
    printf("Unesite broj x: ");
    scanf("%lf", &x);
    do {
        printf("Unesite prirodan broj n (n > 0): ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("n mora biti prirodan broj (n > 0).\n");
        }
    } while (n <= 0);

    result = nth_root(x, n, EPS);

    printf("n-ti korijen broja %.5lf je %.5lf\n", x, result);

    return 0;
}
