#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* buffer;
int* aux;
int* countp;
int* x;
int* i;

struct pessoa* p;
struct auxiliar* pa;

struct pessoa{
    char *nome; //nao posso mais fazer assim, tenho que criar ponterios pra char que mandem meus nomes pro final do meu buffer.
    unsigned int idade,mat;
    };
struct auxiliar{
	char *nome;
	unsigned int idade,mat;
};

void alocapont(void);
void realocapont(void);
void adiciona(void);
void retira(void);
void busca(void);
void listar(void);
void ordena(void);

int main(){
    alocapont();
    *countp = 0;
    *x = 0;
    while((*x) != 5 ){
		*i = 0;
        *aux = 0;
		printf("\n\n\t\t-----menu-----");
		printf("\n-- 1 -- adiocionar");
		printf("\n-- 2 -- remover");
		printf("\n-- 3 -- buscar");
		printf("\n-- 4 -- listar");
		printf("\n-- 5 -- sair");
		printf("\n\n\tdiga uma opcao: ");
		scanf("%d",x);

    	switch (*x) {
        	case 1:
				(*countp) = (*countp) + 1;
            	realocapont();
            	adiciona();
            	break;
        	case 2:
			    printf("\n\t--escolha tipo de remocao--\n");
				printf("\n--1-- nome");
				printf("\n--2-- matricula\n");
				scanf("%d",x);
        		if(*x == 1){
					printf("diga o nome da pessoa que deseja remover da agenda: ");
					scanf("%s",pa->nome);
					retira();
				}
				if(*x == 2){
					printf("diga o numero de matricula da pessoa que deseja remover da agenda: ");
        			scanf("%d",i);
					retira();
				}
				*x = 0;
            	break;
        	case 3:
			    printf("\n\t--escolha tipo de busca--\n");
				printf("\n--1-- nome");
				printf("\n--2-- matricula\n");
				scanf("%d",x);
        		if(*x == 1){
					printf("\ndiga o nome da pessoa desejada: ");
					scanf("%s",pa->nome);
					busca();
				}
				if(*x == 2){
					printf("\ndiga o numero de matricula da pessoa desejada: ");
        			scanf("%d",i);
					busca();
				}
				*x = 0;
            	break;
        	case 4:
                ordena();
        		listar();
            	break;
        	case 5:
            	break;
			default:
				printf("\n\nopcao invalida!!\n\n");
    	}
    }

    free(buffer);

    return 0;
}

void alocapont(void){
    buffer = malloc(4*sizeof(int));
    aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
}
void realocapont(void){
    buffer = realloc(buffer,(sizeof(struct auxiliar) + 4*sizeof(int) + (*countp)*sizeof(struct pessoa)));
    aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
	pa = (struct auxiliar*)(i + 1);
    p = (struct pessoa*)(pa + 1);
}

void adiciona(void){
	(*aux) = (*countp) - 1;
    printf("\n\t pessoa %d\n",(*countp));
    printf("\ndiga o nome: ");
    scanf("%s",(p + (*aux))->nome);
    printf("diga a idade: ");
    scanf("%d",&(p + (*aux))->idade);
    printf("diga o numero de matricula: ");
    scanf("%d",&(p + (*aux)) ->mat);
}

void retira(void){
	if(*i == 0){
		for(*aux = 0;(*aux) < (*countp) && strcmp(pa->nome,(p + (*aux))->nome) != 0 ;(*aux)++);
	}
	else{
		for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
	}
	if(*aux == *countp){
		printf("\n\n pessoa nao encontrada!!");
	}
	else{
		for(;(*aux) < (*countp) - 1;(*aux)++){
			*(p + (*aux)) = *(p + ((*aux) + 1));
			strcpy((p + (*aux))->nome,(p + ((*aux) + 1))->nome);
			(p + (*aux))->idade = (p + ((*aux) + 1))->idade;
			(p + (*aux))->mat = (p + ((*aux) + 1))->mat;
		}
		(*countp) = (*countp) - 1;
		buffer = realloc(buffer,(sizeof(struct auxiliar) + 4*sizeof(int) + (*countp)*sizeof(struct pessoa)));
	}
}

void busca(void){
	if(*i == 0){
		for(*aux = 0;(*aux) < (*countp) && strcmp(pa->nome,(p + (*aux))->nome) != 0;(*aux)++);
	}
	else{
		for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
	}
	if(*aux == *countp){
		printf("\n\n pessoa nao encontrada!!");
	}
	else{
   		printf("\n%s\n",(p + (*aux))->nome);
		printf("%d\n",(p + (*aux))->idade);
       	printf("%d\n",(p + (*aux))->mat);
	}
}

void listar(void){
	if(*countp==0){
		printf("\n\n nao ha pessoas na agenda!!");
	}
	else{
		printf("\n\nlistando..\n");
    	for(*aux = 0;(*aux) < (*countp);(*aux)++){
    		printf("\n\t pessoa %d\n",(*aux) + 1);
   			printf("\n%s\n",(p + (*aux))->nome);
			printf("%d\n",(p + (*aux))->idade);
    	   	printf("%d\n",(p + (*aux))->mat);
   		}
	}
}

void ordena(void){
for (*aux=1; *aux<*countp ; (*aux)++) {
    *i = (*aux) - 1;
    strcpy(pa->nome,(p + (*aux))->nome);
    pa->idade = (p + (*aux))->idade;
    pa->mat = (p + (*aux))->mat;

    while ( (*i >= 0) && (pa->mat < (p + (*i))->mat) ) {
        strcpy((p + ((*i)+1))->nome,(p + (*i))->nome);
        (p + ((*i)+1))->idade = (p + (*i))->idade;
        (p + ((*i)+1))->mat = (p + (*i))->mat;
        (*i)--;
    }
    strcpy((p + ((*i)+1))->nome,pa->nome);
    (p + ((*i)+1))->idade = pa->idade;
    (p + ((*i)+1))->mat = pa->mat;
    }
}
