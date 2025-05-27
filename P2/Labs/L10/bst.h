#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../UTIL/stdneb.h"

typedef struct film
{
    char naziv[64];
    char zanr[16];
    char reziser[32];
    char glumci[512];
    int godina;
} FILM;

typedef struct node
{
    FILM info;
    struct node *left, *right;
} NODE;

NODE *new_node(FILM info);
NODE *add_new_node(NODE *node, FILM info);
int search_node(NODE *node, FILM search_key);
NODE *delete_node(NODE *node, FILM key);
NODE *delete_tree(NODE *node);
