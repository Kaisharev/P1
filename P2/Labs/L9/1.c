#include "binary_tree.h"

int main (){
    NODE *root=add_new_node("A");
    NODE *c1 = add_left(root, "B");
    NODE *c2 = add_right(root, "C");
    c2 = add_right(c2, "F");
    add_left(c2, "I");
    c2 = add_left(c1, "D");
    add_left(c2, "G");
    c1 = add_right(c1, "E");
    c1 = add_right(c1, "H");
    add_left(c1, "J");

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    delete(root);

    return 0;
}