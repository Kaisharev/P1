#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
FILE *open_file(const char *name, char *type)
{

    FILE *fp_file = fopen(name, type);

    if (!fp_file)
    {
        perror("Greska");
        exit(EXIT_FAILURE);
    }
    return fp_file;
}
int compare(const void *elem1, const void *elem2)
{
    return (*(int *)elem2 - *(int *)elem1);
}
int main(int argc, char *argv[])
{
    int menu_option;
    char file_name[50];

    while (1)
    {
        const char *menu_text = "\nCezarov sifrarnik:\n1. Pisanje poruke\n2. Citanje poruke\n3. Izlaz\n";
        printf("%s", menu_text);
        scanf("%d", &menu_option);
        while (getchar() != '\n')
            ;
        switch (menu_option)
        {
        case 1:

        {
            if (argc < 2)
            {
                printf("Fale parametri komandne linije. Ispravno pokretanje je: naziv_fajla.exe naziv_fajla.txt");
                exit(EXIT_FAILURE);
            }

            FILE *fp_input = open_file(argv[1], "ab");
            printf("Unesite broj članova niza: ");
            size_t array_size;
            scanf("%zu", &array_size);
            int *array = (int *)malloc(array_size * sizeof(int));
            if (array == NULL)
            {
                perror("Greska pri alokaciji memorije");
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < array_size; i++)
            {
                printf("\n%d clan: ", i + 1);
                scanf("%d", &array[i]);
            }
            qsort(array, array_size, sizeof(int), compare);
            for (int i = 0; i < array_size; i++)
            {
                fwrite(&array[i], sizeof(int), 1, fp_input);
            }

            free(array);
            fclose(fp_input);
            break;
        }
        case 2:

            printf("\nUnesite naziv fajla (naziv_fajla.ekst ili # ako se čita iz komandne linije): ");
            scanf("%s", file_name);
            if (strcmp(file_name, "#") == 0)
            {
                if (argc < 2)
                {
                    printf("Fale parametri komandne linije. Ispravno pokretanje je: naziv_fajla.exe naziv_fajla.txt");
                    exit(EXIT_FAILURE);
                }
                strncpy(file_name, argv[1], sizeof(file_name) - 1);
                file_name[sizeof(file_name) - 1] = '\0';
            }
            FILE *fp = open_file(file_name, "rb");

            int value;
            while (fread(&value, sizeof(int), 1, fp) == 1)
            {
                printf("%d\n", value);
            }
            fclose(fp);

            break;
        case 3:
            printf("Izlazim iz programa!");
            return EXIT_SUCCESS;

        default:
            printf("Neispravan odabir! Unesite 1, 2 ili 3!");
        }
    }
}