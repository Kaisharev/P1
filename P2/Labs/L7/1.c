#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdneb.h>

typedef struct node
{
    void *data; 
    struct node *prev, *next;
} NODE;

void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    NODE *node_exists = search(*phead, *ptail, data, cmp);
    if (node_exists != NULL) return;

    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    malloc_check(new_node);
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;


    /*Traženje trenutne pozicije */
    NODE *current_position = *phead;
    while (current_position != NULL && cmp(data, current_position->data) > 0)
    {
        current_position = current_position->next;
    }

    /*Ubacivanje na kraj */
    if (current_position == NULL){
        new_node->prev = *ptail;
        (*ptail) ->next = new_node;
        *ptail = new_node;
    }
    /*Ubacivanje na početak*/
    else if (current_position = *phead){
        new_node->next = *phead;
        (*phead)->prev = new_node;
        *phead = new_node;

    }
    /*Ubacivanje bilo gdje drugo u listi*/ 
    else{
        new_node->prev = current_position->prev;
        new_node->next = current_position;
        current_position->prev->next = new_node;
        current_position->prev = new_node;
    }

}
NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *)){

    NODE *current_position = head;
    while (current_position != NULL){
        if (cmp (data, current_position->data)) return current_position;
        if (cmp (data, current_position->data)) return NULL;
        current_position = current_position ->next;
    }
    return NULL;
}


void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *)){
    NODE *delete_node = search (phead, ptail, data, cmp);
    if (delete_node == NULL) return;

    if (*phead == *ptail) *phead=*ptail=NULL;

    if (delete_node == *phead){
        *phead = (*phead)->next;
        (*phead)->prev = NULL;
    }
    else if (delete_node = *ptail){
        *ptail = (*ptail)->prev;
        (*ptail) -> next = NULL;
    } else {
        delete_node->prev->next = delete_node->next;
        delete_node->next->prev = delete_node->prev;
    }
    free (delete_node->data);
    free(delete_node);
}

void write(NODE *head, void (*write_one)(const void *)){
    NODE *current = head;
    while (current){
        write_one(current->data);
        printf ("\n");
        current = current->next;
    }
}
void delete_list(NODE **phead, NODE **ptail) {
    NODE *current = *phead;
    while (current != NULL) {
        NODE *next = current->next; 
        free(current->data);       
        free(current);             
        current = next;           
    }
    *phead = NULL; 
    *ptail = NULL;  
}

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
        void *str = calloc(sizeof(char), strlen(days[i])+1); 
        strcpy(str, days[i]);
        add(&head, &tail, str, cmp); 
    }
    write(head, write_string);
    delete_node(&head, &tail, days[5], cmp);
    write(head, write_string);
    delete_list(&head, &tail);
    return 0;
}