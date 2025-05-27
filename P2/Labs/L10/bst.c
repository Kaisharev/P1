#include "bst.h"

NODE *new_node(FILM info)
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    malloc_check(new_node);
    new_node->left = new_node->right = NULL;
    new_node->info = info;
}
NODE *add_new_node(NODE *node, FILM info)
{
    if (node == NULL)
    {
        return new_node(info);
    }
    int cmp_name = strcmp(toupper(node->info.naziv), toupper(info.naziv));
    if (cmp_name < 0)
    {
        node->left = add_new_node(node->left, info);
    }
    else if (cmp_name > 0)
    {
        node->right = add_new_node(node->right, info);
    }
    else
    {
        node->info = info;
    }
    return node;
}
int search_node(NODE *node, FILM search_key)
{
    if (node == NULL)
        return 0;
    else
    {
        int cmp_name = strcmp(toupper(node->info.naziv), toupper(search_key.naziv));

        if (cmp_name == 0)
        {
            return &node;
        }
        else
        {
            if (cmp_name < 0)
                return (search_node(node->left, search_key));
            if (cmp_name > 0)
                return (search_node(node->right, search_key));
        }
    }
}
NODE *delete_node(NODE *node, FILM key)
{
    if (node == NULL)
        return NULL;
    int cmp_name = strcmp(toupper(node->info.naziv), toupper(key.naziv));
    if (cmp_name < 0)
    {
        node->left = delete_node(node->left, key);
    }
    else
    {
        if (!node->left && !node->right)
        {
            free(node);
            return NULL;
        }
        else if (node->left == NULL)
        {
            NODE *q = node->right;
            free(node);
            return q;
        }
        else if (node->right == NULL)
        {
            NODE *q = node->left;
            free(node);
            return q;
        }
        else
        {
            NODE *max = node->left;
            while (max->right)
                max = max->right;
            node->info = max->info;
            node->left = deleteNode(node->left, max->info);
        }
    }

    return node;
}
NODE *delete_tree(NODE *node)
{
    if (node != NULL)
    {
        delete_tree(node->left);
        delete_tree(node->right);
        free(node);
    }
}