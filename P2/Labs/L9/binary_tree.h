#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../UTIL/stdneb.h"

typedef struct node
{
    char str[100]; // informacioni sadrzaj
    struct node *left, *right;
} NODE;

NODE *add_new_node(const char *str);
NODE *add_left(NODE *node, const char *str);
NODE *add_right(NODE *node, const char *str);
void preorder(NODE *root);
void inorder(NODE *root);
void postorder(NODE *root);
void delete(NODE *root);
