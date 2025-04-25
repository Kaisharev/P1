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

void check_position(CVOR *head, int position)
{
    CVOR *current = head;
    int count = 0;

    while (current != NULL)
    {
        if (count == position)
        {
            printf("Na poziciji %d se nalazi student:\n", position);
            printf("Ime: %s\n", current->data.name);
            printf("Prezime: %s\n", current->data.last_name);
            printf("Broj indeksa: %s\n", current->data.index);
            return;
        }
        count++;
        current = current->next;
    }

    printf("Na poziciji %d nema studenta (duzina liste je %d).\n", position, count);
}
void add_to_end(CVOR **head, STUDENT data)
{
    CVOR *new_node = (CVOR *)malloc(sizeof(CVOR));
    if (new_node == NULL)
    {
        printf("Greska pri alociranju memorije!\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    // Ako je lista prazna
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // Pronalazak poslednjeg čvora
    CVOR *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void delete_node_with_index(CVOR **head, char *index)
{
    CVOR *temp = *head;
    CVOR *prev = NULL;

    if (temp != NULL && strcmp(temp->data.index, index) == 0)
    {
        *head = temp->next;
        free(temp);
        printf("Student sa indeksom %s je obrisan.\n", index);
        return;
    }

    while (temp != NULL && strcmp(temp->data.index, index) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student sa indeksom %s nije pronadjen.\n", index);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student sa indeksom %s je obrisan.\n", index);
}

void free_list(CVOR **head)
{
    CVOR *current = *head;
    CVOR *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
void delete_at_position(CVOR **head, int position)
{
    if (*head == NULL)
    {
        printf("Lista je prazna!\n");
        return;
    }

    CVOR *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        printf("Obrisan student na poziciji %d.\n", position);
        return;
    }

    CVOR *prev = NULL;
    int current_pos = 0;

    while (temp != NULL && current_pos < position)
    {
        prev = temp;
        temp = temp->next;
        current_pos++;
    }

    if (temp == NULL)
    {
        printf("Pozicija %d ne postoji u listi!\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Obrisan student na poziciji %d.\n", position);
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
            printf("Unos novog kontakta:\n");
            printf("Ime: ");
            fgets(student.name, 20, stdin);
            student.name[strcspn(student.name, "\n")] = '\0';
            printf("Prezime: ");
            fgets(student.last_name, 20, stdin);
            student.last_name[strcspn(student.last_name, "\n")] = '\0';
            printf("Indeks: ");
            fgets(student.index, 7, stdin);
            student.index[strcspn(student.index, "\n")] = '\0';
            add_to_start(&head, student);
            break;
        case 2:
            print_list(head);
            break;
        case 3:
            input_into_file(head, "studenti.txt");
            break;
        case 4:
            free_list(&head);

            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}