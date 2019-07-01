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
        return &(*root)->parent->parent;
    }
    return NULL;
}

pont* uncle(pont* root)
{
    if((*root)->parent->parent != NULL)
    {
        if((*root)->parent->parent->right != NULL && (*root)->parent->left == (*root))
        {
            return &(*root)->parent->parent->right;
        }
        if((*root)->parent->parent->left != NULL && (*root)->parent->right == (*root))
        {
            return &(*root)->parent->parent->left;
        }
    }
    return NULL;
}

void change_color(pont* root)
{
    (*root)->color = !(*root)->color;
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

void rotation_left(pont* root)
{
    pont aux;
    aux = (*root)->right;
    (*root)->right = aux->left;
    aux->parent = (*root)->parent;
    (*root)->parent = aux;
    aux->left = (*root);
    (*root) = aux;
}

void rotation_right(pont* root)
{
    pont aux;
    aux = (*root)->left;
    (*root)->left = aux->right;
    aux->parent = (*root)->parent;
    (*root)->parent = aux;
    aux->right = (*root);
    (*root) = aux;
}

void case5(pont* root)
{
    pont* g;
    g = grandparent(root);
    change_color(&(*root)->parent);
    change_color(root);
    if((*root)->parent->right == (*root))
    {
        change_color(&(*root)->right);
        rotation_left(&(*root)->parent);
    }
    if((*root)->parent->left == (*root))
    {
        change_color(&(*root)->left);
        rotation_right(&(*root)->parent);
    }
}

void case4(pont* root)
{
    pont* u,* g;
    u = uncle(root);
    if(color_node(*u) == black && color_node((*root)->parent) == red)
    {
        g = grandparent(root);
        if(root == &(*g)->left->right)
        {
            rotation_left(&(*root)->parent);
            case5(root);
        }
        if(root == &(*g)->right->left)
        {
            rotation_right(&(*root)->parent);
        }
    }
    case5(root);
}

void case3(pont* root)
{
    pont* g,* u;
    u = uncle(root);
    if(u)
    {
        g = grandparent(root);
        if(color_node(*u) == red && color_node((*root)->parent) == red)
        {  
            change_color(&(*root)->parent);
            change_color(u);
            change_color(g);
            case1(g);
        }
    }
    case4(root);  
}

void case2(pont* root)
{
    if(color_node((*root)->parent) == black)
    {
        return;//arvore válida
    }
    case3(root);
}

int case1(pont* root)
{
    if((*root)->parent == NULL)
    {
        change_color(root);
    }
    else
    {
        case2(root);
    }
    return 1;
}

int insertion(pont* root, int data)
{
    if((*root) == NULL)
    {
        (*root) = (pont) malloc (sizeof(node));
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->parent = NULL;
        (*root)->data = data;
        (*root)->color = red;
        return 1;
    }
    if(data < (*root)->data)
    {
        insertion(&(*root)->left, data);
        (*root)->left->parent = *root;
        if(case1(&(*root)->left))
        {
            return 0;
        }
        return 0;
    }
    if(data > (*root)->data)
    {
        insertion(&(*root)->right, data);
        (*root)->right->parent = *root;
        if(case1(&(*root)->left))
        {
            return 0;
        }
        return 0;
    }
    printf("\n o dado ja existe na arvore!!\n");
}


int main()
{
    pont* root = NULL;
    root = reset(root);
    insertion(root,8);
    insertion(root,6);
    insertion(root,10);
    insertion(root,9);
    insertion(root,4);
    insertion(root,3);
    insertion(root,2);
    clear_tree(root);
    return 0;
}
