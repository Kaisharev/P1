#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : n >= 20 ? printf("n mora biti manji od 20.\n")
                                                                  : 0);

    unsigned char mat[n][n][3];
    printf("Unesite RGB komponente piksela slike: \n");
    for (int i = 0; i < n * n; i++)
    {
        int r, g, b;

        do
        {
            printf("piksel(%d, %d) - R = ", i / n, i % n);
            scanf("%d", &r);
        } while (r < 0 || r > 255 ? printf("R mora biti u intervalu [0, 255].\n") : 0);
        do
        {
            printf("piksel(%d, %d) - G = ", i / n, i % n);
            scanf("%d", &g);
        } while (g < 0 || g > 255 ? printf("G mora biti u intervalu [0, 255].\n") : 0);
        do
        {
            printf("piksel(%d, %d) - B = ", i / n, i % n);
            scanf("%d", &b);
        } while (b < 0 || b > 255 ? printf("B mora biti u intervalu [0, 255].\n") : 0);

        mat[i / n][i % n][0] = r;
        mat[i / n][i % n][1] = g;
        mat[i / n][i % n][2] = b;
    }

    printf("Slika: \n");
    for (int i = 0; i < n * n; i++)
    {
        unsigned char *rgb = mat[i / n][i % n];
        printf("#%02x%02x%02x ", rgb[0], rgb[1], rgb[2]);

        if ((i + 1) % n == 0)
        {
            printf("\n");
        }
    }

    return 0;
}