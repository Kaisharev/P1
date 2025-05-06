#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdneb.h>
typedef struct node
{
    void *data; // dinamicki podatak
    struct node *prev, *next;
} NODE;
void add(NODE **phead, NODE **ptail, void *data,
         int (*cmp)(const void *, const void *))
{
    NODE *node_exists = search(*phead, *ptail, data, cmp);
    if (node_exists != NULL)
        return;

    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    malloc_check(new_node);
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*phead == NULL)
    {
        *phead = *ptail = new_node;
        return;
    }
    NODE *current = *phead;
    while (current != NULL && cmp(data, current->data) > 0)
    {
        current = current->next;
    }
}
NODE *search(NODE *head, NODE *tail, const void *data,
             int (*cmp)(const void *, const void *));
