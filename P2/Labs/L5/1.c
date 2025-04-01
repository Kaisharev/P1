#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    char last_name[20];
    char phone_number[12];
} DIRECTORY;

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

void read_contacts(const char *name)
{
    FILE *fp_file = open_file(name, "rb");
    DIRECTORY person;
    printf("\nSadrzaj imenika:\n");
    printf("-----------------\n");
    while (fread(&person, sizeof(DIRECTORY), 1, fp_file))
    {
        printf("%-20s %-20s %-12s\n", person.name, person.last_name, person.phone_number);
    }

    fclose(fp_file);
}

void add_new_contact(char *name)
{
    FILE *fp_file = open_file(name, "ab");
    DIRECTORY person;
    int input_case;
    printf("\nUnesite ime, prezime i broj telefona osobe: ");
    scanf("%19s %19s %11s", person.name, person.last_name, person.phone_number);
    fwrite(&person, sizeof(DIRECTORY), 1, fp_file);

    fclose(fp_file);
}

int main(int argc, char *argv[])
{
    int file_case;
    char file_name[50];
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

    while (1)
    {
        printf("\nImenik:\n1. Unos novog kontakta\n2. Ispis svih kontakta\n3. Izlaz\n");
        printf("Molimo Vas, odaberite zeljenu opciju: ");
        scanf("%d", &file_case);

        switch (file_case)
        {
        case 1:
            int input_case = 1;
            add_new_contact(file_name);
            while (input_case != 2)
            {
                printf("Da li zelite da unesete jos jednu osobu u imenik?\nUnesite 1 za da i 2 za ne: ");
                scanf("%d", &input_case);
                if (input_case == 1)
                    add_new_contact(file_name);
            }
            break;
        case 2:
            read_contacts(file_name);
            break;
        case 3:
            printf("Izlazim iz programa!");
            return EXIT_SUCCESS;

        default:
            printf("Neispravan odabir! Unesite 1, 2 ili 3!");
        }
    }
}