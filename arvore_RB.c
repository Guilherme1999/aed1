#include <stdio.h>
#include <stdlib.h>
#define  black 1 
#define  red 0

typedef struct node* pont;
typedef struct node
{
    int data;
    pont right;
    pont left;
    pont parent;
    int color;
}node;

int color_node(pont root)
{
    if(root == NULL)
    {
        return black;
    }
    return root->color;
}

pont* grandparent(pont* root)
{
    if((*root)->parent != NULL)
    {
        return (*root)->parent->parent;
    }
    return NULL;
}

pont* uncle(pont* root)
{
    if((*root)->parent->parent != NULL)
    {
        if((*root)->parent->parent->right != NULL && (*root)->parent->left == (*root))
        {
            return (*root)->parent->parent->right;
        }
        if((*root)->parent->parent->left != NULL && (*root)->parent->right == (*root))
        {
            return (*root)->parent->parent->left;
        }
    }
    return NULL;
}

void change_color(pont* root)
{
    (*root)->color = !(*root)->color;
    if((*root)->right != NULL) 
    {
        (*root)->right->color = !(*root)->right->color;
    }
    if((*root)->left != NULL)
    {
        (*root)->left->color = !(*root)->left->color;
    }
}

void clear_node(pont node)
{
    if(node == NULL)
    {
        return;
    }
    clear_node(node->left);
    clear_node(node->right);
    free(node);
}

void clear_tree(pont* root)
{
    if(root)
    {
        clear_node(*root);
        free(root);
    }
}

pont* reset(pont* oldroot)
{
    clear_tree(oldroot);
    pont* root;
    root = (pont*) malloc (sizeof(pont));
    (*root) = NULL;
    return root;
}
void insertion(pont* root, int data)
{
    if((*root) == NULL)
    {
        (*root) = (pont) malloc (sizeof(node));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->color = red;
        case1(root);
        return;
    }
    if(data < (*root)->data)
    {
        insertion(&(*root)->left,data);
        return;
    }
    if(data > (*root)->data)
    {
        insertion(&(*root)->right,data);
        return;
    }
}

void case1(pont* root)
{

}
