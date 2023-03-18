#include "tree.h"

tree_node_t* constructor (tree_t* pine, tree_type value)
{
    MY_ASSERT (pine != NULL);

    pine->size = 1;
    pine->root = (tree_node_t*) calloc (pine->size, sizeof (tree_node_t));
    MY_ASSERT (pine->root != NULL);

    pine->root->value = value;
    pine->root->left  = NULL;
    pine->root->right = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

tree_node_t* tree_create (tree_t* pine, tree_type value)
{
    tree_node_t* tmp_node = (tree_node_t*) calloc (1, sizeof (tree_node_t));
    MY_ASSERT (tmp_node != NULL);

    pine->size++;
    tmp_node->value = value;
    tmp_node->left  = NULL;
    tmp_node->right = NULL;

    return tmp_node;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

tree_node_t* tree_link_l (tree_node_t* parent, tree_node_t* child)
{
    MY_ASSERT (parent != NULL && child != NULL);

    if (parent->left == NULL)
    {
        parent->left  = child;
        return parent->left;
    }
    fprintf (stderr, "Impossible to add node to not terminal\n");
    return NULL;
}

tree_node_t* tree_link_r (tree_node_t* parent, tree_node_t* child)
{
    MY_ASSERT (parent != NULL && child != NULL);

    if (parent->right == NULL)
    {
        parent->right  = child;
        return parent->right;
    }
    fprintf (stderr, "Impossible to add node to not terminal\n");
    return NULL;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

tree_node_t* tree_delete (tree_node_t* tree_root)
{
    if (tree_root->left != NULL)
    {
        tree_delete (tree_root->left);
    }
    if (tree_root->right != NULL)
    {
        tree_delete (tree_root->right);
    }
    free (tree_root);
}
