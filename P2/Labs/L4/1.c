#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *open_file(char *name, char *type)
{

    FILE *fp_file = fopen(name, type);

    if (!fp_file)
    {
        perror("Greska");
        return NULL;
        exit(EXIT_FAILURE);
    }
    return fp_file;
}

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Fale parametri komandne linije. Ispravno pokretanje je: naziv_fajla.exe naziv_prvog.txt naziv_drugog.txt");
        return -1;
    }

    FILE *fp_input = open_file(argv[1], "r");
    FILE *fp_output = open_file(argv[2], "w");

    int longest_word_length = 0;

    char current_word[25];
    char longest_word[25];
    while (fscanf(fp_input, "%24s\n", current_word) == 1)
    {
        fprintf(fp_output, "%s\n", current_word);
        if (strlen(current_word) > longest_word_length)
        {
            longest_word_length++;
            strcpy(longest_word, current_word);
        }
    }

    printf("Najduža rijec je: %s", longest_word);

    fclose(fp_input);
    fclose(fp_output);
    return 0;
}