#include <stdlib.h>
#include "tree.h"

void add_int_node(tree_node* root, int data) {
    if (root->data == NULL) {
        root->data = data;
        return;
    }
}

tree_node* create_tree() {
    tree_node* root = malloc(sizeof(tree_node));
    root->data =  NULL;
    root->left_child = NULL;
    root->right_child = NULL;

    return root;
}