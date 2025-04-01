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

char *cipher_text(const char *string, int key)
{
    if (!string)
    {
        fprintf(stderr, "Invalid input: string is NULL\n");
        exit(EXIT_FAILURE);
    }
    char letter;
    char *ciphered_string = calloc(strlen(string) + 1, sizeof(char));
    if (!ciphered_string)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; string[i] != '\0'; i++)
    {
        letter = string[i];

        if (islower(letter))
        {
            letter = (letter - 'a' + key) % 26 + 'a';
        }
        if (isupper(letter))
        {
            letter = (letter - 'A' + key) % 26 + 'A';
        }
        if (isdigit(letter))
        {
            letter = (letter - '0' + key) % 10 + '0';
        }
        ciphered_string[i] = letter;
    }
    return ciphered_string;
}
int main(int argc, char *argv[])
{
    char file_name[50];
    int menu_option;

    while (1)
    {
        printf("\nCezarov sifrarnik:\n1. Pisanje poruke\n2. Citanje poruke\n3. Izlaz\n");
        printf("Molimo Vas, odaberite zeljenu opciju: ");
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
            char string[100];

            printf("Unesite rijec koju zelite sifrovati: ");
            fgets(string, 100, stdin);
            string[strcspn(string, "\n")] = '\0';

            char *ciphered_string = cipher_text(string, 3);
            size_t string_len = strlen(ciphered_string);

            fwrite(&string_len, sizeof(size_t), 1, fp_input);
            fwrite(ciphered_string, sizeof(char), string_len, fp_input);

            free(ciphered_string);
            fclose(fp_input);
            break;
        }
        case 2:

            printf("\nUnesite naziv fajla (naziv_fajla.ekst ili # ako se cita iz komandne linije): ");
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
            printf("\nSadrzaj fajla:\n");
            printf("-------------\n");

            size_t len;
            while (fread(&len, sizeof(size_t), 1, fp) == 1)
            {
                char *buffer = malloc(len + 1);
                if (fread(buffer, 1, len, fp) != len)
                {
                    free(buffer);
                    break;
                }
                buffer[len] = '\0';
                printf("%s\n", buffer);
                free(buffer);
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