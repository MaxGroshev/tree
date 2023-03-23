#include "tree.h"

void graph_dump (tree_t* pine)
{
    FILE* graphviz       = fopen ("./dump_info/tree_dump.dot",  "w");
    FILE* html_logs      = fopen ("./dump_info/tree_dump.html", "a");
    MY_ASSERT (graphviz != NULL && html_logs != NULL)
    dump_graph_t graph_dump_set  = {};
    graph_dump_set.info.size = pine->size;
    graph_dump_set.info.head = &pine->root->value;
    init_graph (graphviz, html_logs, &graph_dump_set);

    tree_print (graphviz, html_logs, &graph_dump_set, pine->root);

    run_graphviz (graphviz, html_logs, &graph_dump_set);

    fclose (graphviz);
}

tree_node_t* tree_print (FILE* graphviz, FILE* html_logs, dump_graph_t* graph_dump_set, tree_node_t* parent)
{
    make_node (graphviz, html_logs, graph_dump_set, &parent->value, *graph_dump_set->nodes, &parent->right->value, &parent->left->value, parent->value);

    if (parent->left != NULL)
    {
        make_edge  (graphviz, html_logs, graph_dump_set, &parent->value, &parent->left->value, *graph_dump_set->edges);
        tree_print (graphviz, html_logs, graph_dump_set, parent->left);
    }
    if (parent->right != NULL)
    {
        make_edge  (graphviz, html_logs, graph_dump_set, &parent->value, &parent->right->value, *graph_dump_set->edges);
        tree_print (graphviz, html_logs, graph_dump_set, parent->right);
    }
}

// void print_html_logs (const char* tree_log)
// {
//     FILE* html_logs = fopen ("./dump_info/tree_dump.html", "a");
//     fwrite (html_logs, "%s", tree_log );
//     fclose (html_logs);
// }
