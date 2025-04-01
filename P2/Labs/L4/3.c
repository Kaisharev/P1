#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int rb;
    char id[5];
    char name[20];
    double price;
} ARTIKAL;

FILE *open_file(char *name, char *type)
{

    FILE *fp_file = fopen(name, type);

    if (!fp_file)
    {
        perror("Greska");
        exit(EXIT_FAILURE);
    }
    return fp_file;
}
ARTIKAL input_article(int id)
{
    ARTIKAL article;
    article.rb = id;
    printf("---ARTIKAL %d---\n", id + 1);
    printf("Unesite ID proizvoda: ");
    scanf("%s", article.id);
    printf("Unesite naziv proizvoda: ");
    scanf("%s", article.name);
    printf("Unesite cijenu proizvoda: ");
    scanf("%lf", &article.price);
    return article;
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Fale parametri komandne linije. Ispravno pokretanje je: naziv_fajla.exe naziv_fajla.txt");
        exit(EXIT_FAILURE);
    }
    int n;

    printf("Unesite broj artikala: ");
    scanf("%d", &n);

    FILE *fp_output = open_file(argv[1], "w");
    ARTIKAL *articles = (ARTIKAL *)malloc(n * sizeof(ARTIKAL));
    for (int i = 0; i < n; i++)
    {
        articles[i] = input_article(i);
    }

    fprintf(fp_output, "=== ===== ==================== ======\n");
    fprintf(fp_output, "RB. SIFRA NAZIV                CIJENA\n");
    fprintf(fp_output, "=== ===== ==================== ======\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp_output, "%2d. %5s %-20s %7.2lf\n",
                articles[i].rb,
                articles[i].id,
                articles[i].name,
                articles[i].price);
    }

    fprintf(fp_output, "=== ===== ==================== ======\n");

    free(articles);
    fclose(fp_output);
}