#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* buffer;
int* aux;
int* countp; 
int* x; 
int* i;
int* cname;
char* allnames;

struct pessoa* p;
struct auxiliar* pa;

struct pessoa{
    char *nome;
    unsigned int idade,mat;
    };
struct auxiliar{
	char nome[20];
};

void alocapont(void);
void realocapont(void);
void adiciona(void);
void retira(void);
void busca(void);
void listar(void);

int main(){
    alocapont();
	*cname = 0;
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
				printf("\n\t pessoa %d\n",(*countp) + 1);
			    printf("\ndiga o nome: ");
    			scanf("%s",pa->nome);
				(*countp) = (*countp) + 1;
            	realocapont();
            	adiciona();
				*x = 0;
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
        		listar();
            	break;
        	case 5:
            	break;
    	}
    }
    
    free(buffer);

    return 0;
}

void alocapont(void){
    buffer = malloc(5*sizeof(int) + sizeof(struct auxiliar));
    aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
	cname = i + 1;
	pa = (struct auxiliar*)(cname + 1);
}
void realocapont(void){
	buffer = realloc(buffer,(sizeof(struct auxiliar) + 5*sizeof(int) + (*countp)*sizeof(struct pessoa) + sizeof(char)*(*cname + strlen(pa->nome) + 1)));
	aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
	cname = i + 1;
	pa = (struct auxiliar*)(cname + 1);
 	p = (struct pessoa*)(pa + 1);
	if(*countp > 1){
		allnames = (char*)(p + ((*countp)-1));
		for(*i= *cname-1; *i >= 0 ; (*i)--){
			*(allnames + ((*i) + sizeof(struct pessoa))) = *(allnames + (*i));
		}
	}
	allnames = (char*)(p + (*countp));
	p->nome = allnames;
		(*i) = 1;
		for((*aux)=0 ; (*aux)<(*cname) ; (*aux)++){
			if(*(allnames + (*aux)) == '\0'){
				(p + (*i))->nome = (allnames +((*aux)+1));
				(*i)++;
			}
		}
}

void adiciona(void){
	(*x) = 0;
	(*aux) = (*countp) - 1;
	if((*countp) == 1){
		strcpy(allnames,pa->nome);
	}
	for((*i) = 0; (*i) < (*cname); (*i)++){
		if(*(allnames + (*i)) == '\0'){ 
			(*x)++;
			if((*x) == (*aux)){
				(*i)++;
				strcpy((allnames+(*i)),pa->nome);
			}
		}
	}
	
	*cname += strlen(pa->nome) + 1;
    printf("diga a idade: ");
    scanf("%d",&(p + (*aux))->idade);
    printf("diga o numero de matricula: ");
    scanf("%d",&(p + (*aux))->mat);

}

void retira(void){	
	*x = 0;
	if(*i == 0){
		for(*aux = 0;(*aux) < (*countp) && strcmp(pa->nome,(p + (*aux))->nome) != 0 ;(*aux)++)
		(*x) += strlen((p +(*aux))->nome) + 1;
	}
	else{
		for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++)
		(*x) += strlen((p +(*aux))->nome) + 1;
		strcpy(pa->nome,(p + (*aux))->nome);
	}
	if(*aux == *countp){
		printf("\n\n pessoa nao encontrada!!");
	}
	else{
		allnames = (p + (*aux))->nome;
		*x = *cname - *x; 
		for(*i = 0 ; (*i + strlen(pa->nome) + 1)  < (*x) ; (*i)++){
			*(allnames + (*i)) = *(allnames + (*i) + strlen(pa->nome) + 1);
		}
		(*cname) -= (strlen(pa->nome) + 1);
		for(;(*aux) < (*countp) - 1;(*aux)++){
			(p + (*aux))->idade = (p + ((*aux) + 1))->idade;
			(p + (*aux))->mat = (p + ((*aux) + 1))->mat;
		}
		(*countp) = (*countp) - 1;
		allnames = (char*)(p + *(countp));
		for(*i= 0; *i < *cname ; (*i)++){
			*(allnames + (*i)) = *(allnames + ((*i) + sizeof(struct pessoa)));
		} 
		buffer = realloc(buffer,(sizeof(struct auxiliar) + 5*sizeof(int) + (*countp)*sizeof(struct pessoa) + sizeof(char)*(*cname)));
		aux = buffer;
    		countp = aux + 1;
    		x = countp + 1;
    		i = x + 1;
		cname = i + 1;
		pa = (struct auxiliar*)(cname + 1);
 	    	p = (struct pessoa*)(pa + 1);
		allnames = (char*)(p + (*countp));
		p->nome = allnames;
		(*i) = 1;
		for((*aux)=0 ; (*aux)<((*cname) - 1) ; (*aux)++){
			if(*(allnames + (*aux)) == '\0'){
				(p + (*i))->nome = (allnames +((*aux)+1));
				(*i)++;
			}
		}
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
