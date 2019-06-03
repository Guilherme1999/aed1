#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define bool int
#define MAX 10

typedef struct Aluno
{
    int idade; 
    char nome[50];
}Aluno;

typedef struct Pilha 
{
    Aluno alunos[MAX];  
    int topo; 
    int base;
    int limite;
}Pilha; 

void Reset(Pilha* pilha)
{
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}
bool Empty(Pilha* pilha)
{
    return pilha->topo == 0;
}
bool Full(Pilha* pilha)
{
    return pilha->topo == MAX;
}
bool Push(Pilha* pilha,Aluno* item){
    if(!Full(pilha))
    {
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }
    else
    {
        return false;
    }
}
bool Pop(Pilha* pilha,Aluno* aluno)
{
    if(!Empty(pilha))
    {
        pilha->topo--;
        *aluno = pilha->alunos[pilha->topo];
        return true;
    } 
    else
    {
        return false;
    }
}
void Listar(Pilha* pilha)
{   
    Pilha auxiliar;
    Reset(&auxiliar);
    printf("\nListando...\n");
    Aluno aluno; 
    while (!Empty(pilha))
    {
        Pop(pilha, &aluno);
        printf("\n%i - %s", aluno.idade, aluno.nome);
        Push(&auxiliar,&aluno);
    } 
    while(!Empty(&auxiliar))
    {
        Pop(&auxiliar,&aluno);
        Push(pilha,&aluno);
    }
} 

int main()
{
    Pilha pilha;
    Aluno contato;
    int escolha;

    Reset(&pilha);
    while(escolha != 5){
        printf("\n\t1 - adiciona na pilha\n\t2 - remove da pilha\n\t3 - limpa a pilha\n\t4 - lista a pilha\n\t5 - apaga a pilha\n\n");
        scanf("%d",&escolha);
        switch (escolha){
            case 1:
                printf("nome: ");
                scanf("%s",contato.nome);
                printf("id: ");
                scanf("%d",&contato.idade);
                printf("\n\ninserindo...\n");
                if(Push(&pilha,&contato))
                    printf("\ninserido com sucesso!\n\n");
                else
                    printf("\nerro ao inserir!\n\n");
                break;
            case 2:
                printf("\n\nremovendo...\n");
                if(Pop(&pilha,&contato))
                    printf("\nremovido com sucesso!\n\n");
                else
                    printf("\npilha vazia!\n\n");
                break;
            case 3:
                printf("\nlimpando...\n\n");
                Reset(&pilha);
                break;
            case 4:
                Listar(&pilha);
                break;
            case 5:
                printf("\nsaindo...\n");
                break;
        }
    }
    return 0;
}
