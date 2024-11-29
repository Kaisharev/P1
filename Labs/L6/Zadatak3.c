#include <stdio.h>
/*
    Napisati program koji učitava prirodan broj n, 
    a zatim ispisuje najveći broj koji je jednak sumi faktorijela
    svojih cifara, a koji je manji od prirodnog broja n. 
    Na primjer, broj 145 je jednak sumi faktorijela svojih cifara
(   1! + 4! + 5! = 1 + 24 + 120 = 145)
*/
int factoriel_of_number (int number){
    int factoriel_value = 1;
    for (int i = 1; i<=number; i++) factoriel_value*=i;
    return factoriel_value;
}
int sum_of_factoriel_digits(int n)
{
    int sum = 0;

    while (n)
    {
        sum += factoriel_of_number(n % 10);
        n /= 10;
    }

    return sum;
}

int main(void)
{
    int n;

    do
    {
        printf("n= ");
        scanf("%d", &n);
    } while (n < 1 ? (printf("n mora biti prirodan broj.\n"), 1) : 0);

    while (n--)
    {
        if (sum_of_factoriel_digits(n) == n)
        {
            printf("Trazeni broj je %d.\n", n);

            return 0;
        }
    }

    printf("Trazeni broj ne postoji.\n");

    return 0;
}