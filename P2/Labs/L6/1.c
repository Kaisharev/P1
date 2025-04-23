#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    char last_name[20];
    char index[7];
} STUDENT;

typedef struct node
{
    STUDENT data;
    struct node *next;
} CVOR;

void add_to_start(CVOR **head, STUDENT data)
{
    CVOR *new_node = (CVOR *)malloc(sizeof(CVOR));

    if (new_node == NULL)
    {
        printf("Greska pri alociranju memorije! Izlazim iz programa!");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(CVOR *head)
{
    CVOR *current = head;
    printf("Lista studenata: ");
    while (current != NULL)
    {
        printf("Ime: %s\n", current->data.name);
        printf("Prezime: %s\n", current->data.last_name);
        printf("Broj indeksa: %s\n", current->data.index);
        printf("----------------------------------------\n");
        current = current->next;
    }
}

FILE *open_file(char *file_name, char *type)
{
    FILE *fp = fopen(file_name, type);
    if (fp == NULL)
    {
        perror("Greska pri otvaranju!");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void input_into_file(CVOR *head, char *file_name)
{
    FILE *fp_input = open_file(file_name, "a");
    CVOR *current = head;
    while (current != NULL)
    {
        fprintf(fp_input, "Ime: %s\nPrezime: %s\nBroj indeksa: %s\n", current->data.name, current->data.last_name, current->data.index);
        current = current->next;
    }
}

int main()
{
    CVOR *head = NULL;

    int input;
    STUDENT student;
    while (1)
    {
        printf("\nVI Lab:\n1. Unos novog studenta\n2. Ispis svih kontakta\nIspis u tektualnu datoteku\n4. Izlaz\n");
        printf("Molimo Vas, odaberite zeljenu opciju: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Unos novog kontakta:\n ");
            scanf("%20s %20s %7s", student.name, student.last_name, student.index);
            add_to_start(&head, student);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            input_into_file(head, "studenti.txt");
            break;
        case 4:
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}