#include "tree.h"

int main ()
{
    struct tree_t pine = {};
    constructor (&pine, 1);

    tree_node_t* node1 = tree_create (&pine, 2);
    tree_node_t* node2 = tree_create (&pine, 3);
    tree_node_t* node3 = tree_create (&pine, 4);
    tree_node_t* node4 = tree_create (&pine, 5);
    tree_node_t* node5 = tree_create (&pine, 6);
    tree_node_t* node6 = tree_create (&pine, 7);
    tree_node_t* node7 = tree_create (&pine, 8);

    tree_link_l (pine.root, node1);
    tree_link_r (pine.root, node2);
    tree_link_l (node1,     node3);
    tree_link_r (node1,     node4);
    tree_link_l (node2,     node5);
    tree_link_r (node2,     node6);
    tree_link_l (node3,     node7);

    //printf ("%p %d\n", node2->right, node2->right->value);
    //tree_remove  (&pine, node6);
    //free  (node2->right);
    //free  (node6);
    // printf ("%p \n", node6);

    graph_dump  (&pine);
    tree_delete (pine.root);
}
