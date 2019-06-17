#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long key;
typedef struct dados
{
    key matricula;
    char nome[30];
}dados;

typedef struct node* aponta;
typedef struct node
{
    dados registro;
    aponta left;
    aponta right;
}node;

aponta* cria()
{
    aponta* raiz;
    raiz = (aponta*)malloc(sizeof(aponta));
    if (raiz)
    {
        *raiz = NULL;
        return raiz;
    }
}

void libera_node(aponta no)
{
    if(no == NULL)
    {
        return;
    }
    libera_node(no->left);
    libera_node(no->right);
    free(no);
    no = NULL;
}
void libera_tree(aponta* raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    libera_node(*raiz);
    free(raiz);
}

int altura(aponta* raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }
    int altura_esq = altura(&((*raiz)->left));
    int altura_dir = altura(&((*raiz)->right));
    if(altura_esq > altura_dir)

    {
        return (altura_esq + 1);
    }
    else
    {
        return (altura_dir + 1);
    }
}

int nos(aponta* raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }
    int altura_esq = nos(&((*raiz)->left));
    int altura_dir = nos(&((*raiz)->right));
    return (altura_esq + altura_dir + 1);
}

void preordem(aponta* raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        printf("%s\n",(*raiz)->registro.nome);
        preordem(&((*raiz)->left));
        preordem(&((*raiz)->right));
    }
}

void central(aponta* raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        preordem(&((*raiz)->left));
        printf("%s\n",(*raiz)->registro.nome);
        preordem(&((*raiz)->right));
    }
}

void posordem(aponta* raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        preordem(&((*raiz)->left));
        preordem(&((*raiz)->right));
        printf("%s\n",(*raiz)->registro.nome);
    }
}

void insere(dados info, aponta* no)
{
    if(*no == NULL)
    {
        *no = (aponta)malloc(sizeof(node));
        (*no)->registro = info;
        (*no)->left = NULL;
        (*no)->right = NULL;
        return;
    }
    if(info.matricula < (*no)->registro.matricula)
    {
        insere(info,&((*no)->left));
        return;
    }
    if(info.matricula > (*no)->registro.matricula)
    {
        insere(info,&((*no)->right));
        return;
    }
    else
    {
        printf("\no registro ja existe na arvore!\n");
    }
}

void antecessor(aponta auxiliar, aponta* no){
    aponta aux;
    if((*no)->right != NULL)
    {
        antecessor(auxiliar,&(*no)->right);
        return;
    }
    auxiliar->registro = (*no)->registro;
    aux = *no;
    *no = (*no)->left;
    free(aux);
}

void retira(dados info, aponta* no)
{
    aponta aux;
    if(*no == NULL)
    {
        printf("\no regitro nao existe na arvore!\n");
        return;
    }
    if(info.matricula < (*no)->registro.matricula)
    {
        retira(info,&(*no)->left);
        return;
    }
    if(info.matricula > (*no)->registro.matricula)
    {
        retira(info,&(*no)->right);
        return;
    }
    if((*no)->right == NULL)
    {
        aux = *no;
        *no = (*no)->left;
        free(aux);
        return;
    }
    if((*no)->left != NULL)
    {
        antecessor(*no,&(*no)->left);
        return;
    }
    aux = *no;
    *no = (*no)->right;
    free(aux);
}
int main()
{
    aponta* raiz;
    dados dado;
    int x;
    raiz = cria();
    for(int i = 0; i < 7; i++)
    {
        printf("\ndiga um nome: ");
        scanf("%s",dado.nome);
        printf("diga uma matricula: ");
        scanf("%d",&dado.matricula);
        insere(dado,raiz);
    }
    x = altura(raiz);
    printf("\naltura: %d",x);
    x = nos(raiz);
    printf("\nnumero de nos: %d",x);
    printf("\npreordem:\n");
    preordem(raiz);
    printf("\ncentral:\n");
    central(raiz);
    printf("\nposordem:\n");
    posordem(raiz);
    printf("\n\n");
    printf("diga um item para deletar: ");
    scanf("%d",&dado.matricula);
    retira(dado,raiz);
    printf("\n");
    preordem(raiz);
    libera_tree(raiz);
    return 0;
}
