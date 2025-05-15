#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../UTIL/stdneb.h"
typedef struct node
{
    void *data; 
    struct node *prev, *next;
} NODE;

void add (NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
NODE *search (NODE *head, NODE *tail, const void *data, int (*cmp)(const void *, const void *));
void delete (NODE **phead, NODE **ptail, void *data, int (*cmp)(const void *, const void *));
void write(NODE *head, void (*write_one)(const void *));
void delete_list(NODE **phead, NODE **ptail);