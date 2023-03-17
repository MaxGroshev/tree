#include "tree.h"

void graph_dump (tree_t* pine)
{
    FILE* graphviz       = fopen ("./dump_info/tree_dump.dot", "w");
    MY_ASSERT (graphviz != NULL)
    dump_graph_t graph_dump_set  = {};
    graph_dump_set.orientation   = "";
    init_graph (graphviz, &graph_dump_set);

    tree_node_t* current = pine->root;
    tree_print (graphviz, &graph_dump_set, current, current->left);

    run_graphviz (graphviz, &graph_dump_set);

    fclose (graphviz);
}

tree_node_t* tree_print (FILE* graphviz, dump_graph_t* graph_dump_set, tree_node_t* parent, tree_node_t* child)
{
    make_node (graphviz, graph_dump_set, &parent->value, graph_dump_set->nodes[0], &parent->right->value, &parent->left->value, parent->value);
    if (parent->left == NULL)
    {
        if   (parent->right == NULL) return NULL;
        else
        {
            parent = parent->right;
            tree_print (graphviz, graph_dump_set, parent, parent->right);
        }
    }
    else
    {
        parent = parent->left;
        tree_print (graphviz, graph_dump_set, parent, parent->left);
    }
    // make_node (graphviz, &graph_dump_set, &current->data, graph_dump_set.nodes[1], &current->next->data, &current->prev->data, current->data);
    // make_edge (graphviz, &graph_dump_set, &current->data, &current->prev->data, graph_dump_set.edges[edge_count]);

    //if (parent->)
}
