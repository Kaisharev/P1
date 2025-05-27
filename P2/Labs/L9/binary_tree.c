#include "binary_tree.h"

NODE *add_new_node(const char* str){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    malloc_check (new_node);

    strcpy (new_node->str, str);
    new_node->left = NULL; 
    new_node->right = NULL;

    return new_node;
}
NODE *add_left (NODE *node, const char* str){
    if (node == NULL) return NULL;
    if (node -> left != NULL){
        return node -> left;
    }
    NODE *new_node = add_new_node(str);
    node -> left = new_node;
    return new_node;
}

NODE *add_right (NODE *node, const char* str){
    if (node == NULL) return NULL;
    if (node -> right != NULL){
        return node -> right;
    }
    NODE *new_node = add_new_node(str);
    node -> right = new_node;
    return new_node;
}

void preorder(NODE *root){
    if (root != NULL){
        printf ("%s", root->str);
        preorder (root -> left);
        preorder (root -> right);
    }
}
void inorder(NODE *root){
    if (root != NULL){
        inorder (root -> left);
        printf ("%s", root->str);
        inorder (root -> right);
    }
}

void postorder(NODE *root){
    if (root != NULL){
        postorder (root -> left);
        postorder (root -> right);
        printf ("%s", root->str);

    }
}

void delete (NODE *root){
    if (root != NULL){
        delete (root -> left);
        delete (root -> right);
        free (root);

    }
}