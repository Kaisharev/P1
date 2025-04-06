/*
 Neka je dat tip:
typedef struct {
char autor[30], zaduzeni[30], status[15];
int prioritet;
} ZADATAK;
Polja autor i zaduzeni predstavljaju string u formi
Ime-Prezime. Polje prioritet može imati vrijednosti 0, 1
i 2, pri čemu manja vrijednost predstavlja viši prioritet.
Iz tekstualne datoteke čiji je naziv prvi argument
komandne linije, treba učitati formatirano upisane
podatke o zadacima (svaki zadatak u novom redu) i u
datoteku čiji je naziv drugi argument komandne linije,
treba upisati zadatke sortirano opadajuće prema
prioritetu. Za sortiranje koristiti merge sort algoritam.
Primjer sortiranih podataka u izlaznoj datoteci:

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char autor[30], zaduzeni[30], status[15];
    int prioritet;
} ZADATAK;

FILE *open_file(const char *file_name, const char *type)
{
    FILE *fp = fopen(file_name, type);
    if (!fp)
    {
        perror("Greska pri otvaranju fajla: ");
        exit(EXIT_FAILURE);
    }
    return fp;
}
void compare(const void *a, const void *b)
{
    return ((ZADATAK *)a)->prioritet - ((ZADATAK *)b)->prioritet;
}

void merge_sort(void *arr, int left, int right, int size, int (*compare)(const void *, const void *))
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, size, compare);
        merge_sort(arr, mid + 1, right, size, compare);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        void *L = malloc(n1 * size);
        void *R = malloc(n2 * size);

        memcpy(L, arr + left * size, n1 * size);
        memcpy(R, arr + (mid + 1) * size, n2 * size);

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2)
        {
            if (compare(L + i * size, R + j * size) <= 0)
            {
                memcpy(arr + k * size, L + i * size, size);
                i++;
            }
            else
            {
                memcpy(arr + k * size, R + j * size, size);
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            memcpy(arr + k * size, L + i * size, size);
            i++;
            k++;
        }

        while (j < n2)
        {
            memcpy(arr + k * size, R + j * size, size);
            j++;
            k++;
        }

        free(L);
        free(R);
    }
}

int main(int argc, char *argv[])
{

    FILE *fp_input = open_file(argv[1], "r");
    FILE *fp_output = open_file(argv[2], "w");

    ZADATAK current_task;
    int counter = 0;
    while (fscanf("%s %s %s %d", current_task.autor, current_task.zaduzeni, current_task.status, &current_task.prioritet) == 3)
    {
        counter++;
    }
    ZADATAK *tasks = (ZADATAK *)malloc(counter * sizeof(ZADATAK));
    rewind(fp_input);
    for (int i = 0; i < counter; i++)
    {
        fscanf(fp_input, "%29s %29s %14s %d",
               tasks[i].autor, tasks[i].zaduzeni, tasks[i].status, &tasks[i].prioritet);
    }
    fclose(fp_input);
    merge_sort(tasks, 0, counter, sizeof(ZADATAK), compare);

    for (int i = 0; i < counter; i++)
    {
        fprintf(fp_output, "%30s %30s %15s %d\n", tasks[i].autor, tasks[i].zaduzeni, tasks[i].status, tasks[i].prioritet);
    }
    free(tasks);
    fclose(fp_output);
}