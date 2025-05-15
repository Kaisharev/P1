#include "node.h"

void write_string (const void *data){
    printf ("%s", (const char*) data);
}

int cmp(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main()
{
    NODE *head=0, *tail=0;
    void *days[] = {"ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota"};
    for (int i = 0; i < 6; i++)
    {
        char *str = strdup(days[i]);  
        strcpy(str, days[i]);
        add(&head, &tail, str, cmp); 
    }
    write(head, write_string);
    char *to_delete = strdup("subota");
    delete(&head, &tail, to_delete, cmp);
    free(to_delete);
    printf ("\n\nIspis bez subote: \n");
    write(head, write_string);
    delete_list(&head, &tail);
}