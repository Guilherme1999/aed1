#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0

typedef struct Aluno
{
    int idade;
    char nome[30];
}Aluno;

typedef struct Pilha
{
    Aluno* alunos;
    Aluno* topo;
    Aluno* base;
    int limite;
}Pilha;

void Reset(Pilha* pilha)
{
    pilha->alunos = (Aluno*)malloc(sizeof(Aluno));
    pilha->alunos = NULL;
    pilha->topo = NULL;
    pilha->base = NULL;
    pilha->limite = 0;
}
bool Empty(Pilha* pilha)
{
    return pilha->alunos == NULL;
}

void Clear(Pilha* pilha)
{
    free(pilha->alunos);
    pilha->alunos = NULL;
}

bool Push(Pilha* pilha,Aluno* dado)
{   
    pilha->limite++;  
    pilha->alunos = (Aluno*)realloc(pilha->alunos,sizeof(Aluno)*pilha->limite);   
    if(!pilha->alunos)
    {
        printf("\nerro ao alocar memoria!\n\n");
        return false;
    }
    pilha->alunos[pilha->limite - 1] = *dado;
    pilha->topo = &pilha->alunos[pilha->limite - 1];
    pilha->base = pilha->alunos;
    return true;   
}
bool Pop(Pilha* pilha, Aluno* aluno)
{
    if(Empty(pilha))
    {
        return false;
    }
    *aluno = *pilha->topo;
    pilha->limite--;
    if(pilha->limite  == 0)
    {
        Clear(pilha);
        return true;
    }
    pilha->alunos = (Aluno*)realloc(pilha->alunos,sizeof(Aluno)*pilha->limite);  
    pilha->topo = &pilha->alunos[pilha->limite - 1];
    
    pilha->base = pilha->alunos;
    return true;
}
void Listar(Pilha* pilha)
{
    Aluno aluno;
    Pilha* auxiliar;
    auxiliar = (Pilha*)malloc(sizeof(Pilha));
    Reset(auxiliar);
    while(!Empty(pilha))
    {
        Pop(pilha,&aluno);
        printf("\n%d - %s",aluno.idade, aluno.nome);
        Push(auxiliar,&aluno);
    }
    while(!Empty(auxiliar))
    {
        Pop(auxiliar,&aluno);
        Push(pilha,&aluno);
    }
    Clear(auxiliar);
}
void Remove_Nome(Pilha* pilha, char* nome)
{
    Pilha* auxiliar;
    auxiliar = (Pilha*)malloc(sizeof(Pilha));
    Reset(auxiliar);
    Aluno desempilha;
    while(strcmp(nome,pilha->topo->nome) != 0)
    {
        Pop(pilha,&desempilha);
        Push(auxiliar,&desempilha);
    }
    Pop(pilha,&desempilha);
    while(!Empty(auxiliar))
    {
        Pop(auxiliar,&desempilha);
        Push(pilha,&desempilha);
    }
    Clear(auxiliar);
}

int main()
{
    Pilha* pilha;
    Aluno contato;
    int escolha = 0;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    Reset(pilha);
    while(escolha != 5)
    {
        printf("\n\n\t0 - insere pessoa\n\t1 - deleta pessoa topo\n\t2 - deleta pessoa por nome\n\t3 - limpa pilha\n\t4 - listar pessoas\n\t5 - sair\n\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
            case 0:
                printf("nome: ");
                scanf("%s",contato.nome);
                printf("idade: ");
                scanf("%d",&contato.idade);
                printf("\ninserindo...\n\n");
                if(Push(pilha,&contato))
                {
                    printf("\ninserido com sucesso!!\n");
                }
                else
                {
                    printf("\nerro ao inserir!!\n");    
                }
                break;
            case 1:
                printf("\nremovendo...\n\n");
                 if(Pop(pilha,&contato))
                 {
                    printf("\nremovido com sucesso!!\n");
                 }
                 else
                 {
                    printf("\nerro ao remover!!\n\n");
                 }
                break;
            case 2:
                printf("nome: ");
                scanf("%s",contato.nome);
                printf("\nremovendo...\n\n");
                Remove_Nome(pilha,contato.nome);
                printf("\nremovido com sucesso!!\n");
                break;
            case 3:
                printf("\nlimpando...\n\n");
                Clear(pilha);
                break;
            case 4:
                printf("\nlistando...\n\n");
                Listar(pilha);
                    
                break;
            case 5:
                printf("\nsaindo...\n\n");
                Clear(pilha);
                free(pilha);
                break;
        }
    }
    return 0;
}
