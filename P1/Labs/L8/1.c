#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : n >= 20 ? printf("n mora biti manji od 20.\n")
                                                                  : 0);

    int mat[n][n];
    for (int i = 0; i < n * n; i++)
    {
        scanf("%d", &mat[i / n][i % n]);
    }

    int main_diag_sum = 0;
    int sec_diag_sum = 0;
    for (int i = 0; i < n; i++)
    {
        main_diag_sum += mat[i][i];
        sec_diag_sum += mat[i][n - i - 1];
    }

    printf("Suma elemenata glavne dijagonale:   %d\n", main_diag_sum);
    printf("Suma elemenata sporedne dijagonale: %d\n", sec_diag_sum);

    return 0;
}