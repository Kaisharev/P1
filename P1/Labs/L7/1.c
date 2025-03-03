#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : 0);

    int array[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}