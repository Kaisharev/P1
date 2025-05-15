
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "../../UTIL/stdneb.h"
void push(STACK_NODE **top, int data) {
    STACK_NODE *new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    malloc_check(new_node);
    new_node->data = data;
    new_node->prev = *top;
    *top = new_node;
}

bool pop(STACK_NODE **top, int *data) {
    if (!top || !*top) {
        return false;
    }
    
    STACK_NODE *temp = *top;
    *data = temp->data;
    *top = temp->prev;
    free(temp);
    return true;
}
