#pragma once
#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphviz.h"
#include "my_ASSERT.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef int tree_type;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct tree_node_t
{
    tree_type    value;
    tree_node_t* right;
    tree_node_t* left;
};

struct tree_t
{
    tree_node_t* root;
    size_t       size;
};

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

tree_node_t* constructor (tree_t* pine, tree_type value);
tree_node_t* tree_create (tree_t* pine, tree_type value);

tree_node_t* tree_link_l (tree_node_t* parent, tree_node_t* child);
tree_node_t* tree_link_r (tree_node_t* parent, tree_node_t* child);

void         graph_dump   (tree_t* pine);
tree_node_t* tree_print   (FILE* graphviz, dump_graph_t* graph_dump_set ,tree_node_t* parent, tree_node_t* child);


tree_node_t* tree_delete (tree_t* pine);