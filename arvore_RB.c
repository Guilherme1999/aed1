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
    pont* g;
    g = grandparent(root);
    if(*g != NULL)
    {
        if((*root)->parent == (*g)->left)
        {
            return &(*g)->right;
        }
        if((*root)->parent == (*g)->right)
        {
            return &(*g)->left;
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
    aux->right->parent = (*root);
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
    if(aux->right != NULL)
    {
        aux->right->parent = (*root);
    }
    aux->parent = (*root)->parent;
    if((*root) == (*root)->parent->left)
    {
        (*root)->parent->left = aux;
    }
    else{
        (*root)->parent->right = aux;
    }
    aux->right = (*root);
    (*root)->parent = aux;
}

void case5(pont* root)
{
    pont* g;
    g = grandparent(root);
    change_color(g);
    change_color(&(*root)->parent);
    if((*g)->right != NULL && (*g)->right->right == (*root))
    {
        rotation_left(g);
    }
    if((*g)->left != NULL && (*g)->left->left == (*root))
    {
        rotation_right(g);
    }
}

void case4(pont* root)
{
    pont* u,* g;
    u = uncle(root);
    if(color_node(*u) == black && color_node((*root)->parent) == red)
    {
        g = grandparent(root);
        if((*g)->left != NULL && *root == (*g)->left->right)
        {
            rotation_left(&(*root)->parent);
            *root = (*root)->left;
            case5(root);
        }
        if((*g)->right != NULL && *root == (*g)->right->left)
        {
            rotation_right(&(*root)->parent);
            *root = (*root)->right;
        }
    }
    case5(root);
}

void case3(pont* root)
{
    pont* g,* u;
    u = uncle(root);
    if(*u != NULL && color_node(*u) == red && color_node((*root)->parent) == red)
    {
        g = grandparent(root);
        change_color(&(*root)->parent);
        change_color(u);
        change_color(g);
        case1(g);
    }
    else
    {
    case4(root);
    }
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
        if(insertion(&(*root)->left, data))
        {
            (*root)->left->parent = *root;
            case1(&(*root)->left);
            return 0;
        }
        return 0;
    }
    if(data > (*root)->data)
    {
        if(insertion(&(*root)->right, data))
        {
            (*root)->right->parent = *root;
            case1(&(*root)->left);
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
    case1(root);
    insertion(root,6);
    insertion(root,10);
    insertion(root,9);
    insertion(root,4);
    insertion(root,3);
    insertion(root,2);
    clear_tree(root);
    return 0;
}

