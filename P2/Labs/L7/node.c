#include "node.h"
void add(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *))
{
    NODE *node_exists = search(*phead, *ptail, data, cmp);
    if (node_exists != NULL) return;

    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (!new_node) return;  // malloc_check replacement
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    /* Empty list case */
    if (*phead == NULL) {
        *phead = *ptail = new_node;
        return;
    }

    NODE *current = *phead;
    while (current != NULL && cmp(data, current->data) > 0) {
        current = current->next;
    }

    if (current == *phead) {
        new_node->next = *phead;
        (*phead)->prev = new_node;
        *phead = new_node;
    }
    else if (current == NULL) {
        new_node->prev = *ptail;
        (*ptail)->next = new_node;
        *ptail = new_node;
    }
    else {
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }
}
NODE *search(NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *)){

    NODE *current_position = head;
    while (current_position != NULL){
        if (cmp (data, current_position->data) == 0) return current_position;
        current_position = current_position ->next;
    }
    return NULL;
}


void delete(NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *)){
    if (phead == NULL || *phead == NULL) return;

    NODE *delete_node = search (*phead, *ptail, data, cmp);
    if (delete_node == NULL) return;

    if (*phead == *ptail){
        free (delete_node ->data);
        free (delete_node);
        *phead=*ptail=NULL;
        return;
    } 

    if (delete_node == *phead){
        *phead = (*phead)->next;
        (*phead)->prev = NULL;
    }
    else if (delete_node == *ptail){
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
