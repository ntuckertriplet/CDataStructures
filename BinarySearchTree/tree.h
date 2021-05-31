#ifndef TREE_H
#define TREE_H

typedef struct tree_node {
    int data;
    tree_node* left_child;
    tree_node* right_child;
} tree_node;

void add_node(tree_node* root, int data);
tree_node* create_tree();

#endif