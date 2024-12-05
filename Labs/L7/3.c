#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    do
    {
        printf("n=");
        scanf("%d", &n);
    } while (n < 1 ? printf("n mora biti pozitivan.\n") : 0);

    int arr[n];
    int sum = 0;
    printf("Elementi niza: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("==================================================\n");

    float avg = (float)sum / n;
    float closest = INFINITY;
    int closest_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (fabs(arr[i] - avg) < fabs(closest - avg))
        {
            closest = arr[i];
            closest_index = i;
        }
    }

    for (int i = 0; i < closest_index - 1; i++)
    {
        for (int j = i + 1; j < closest_index; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = closest_index + 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Aritmeticka sredina je %.2f.\n", avg);
    printf("Najblizi element je %d.\n", arr[closest_index]);
    printf("Modifikovani niz: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}