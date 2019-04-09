#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[20];
    int idade,mat;
};

void* buffer;
int* aux;
int* countp; 
int* x; 
int* i;
struct pessoa* p;


void alocapont(void){
    buffer = malloc(4*sizeof(int));
    aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
}
void realocapont(void){
	(*countp) = (*countp) + 1;
    buffer = realloc(buffer,(4*sizeof(int))+((*countp)*(sizeof(struct pessoa))));
    aux = buffer;
    countp = aux + 1;
    x = countp + 1;
    i = x + 1;
    p = i + 1;
}
/*void adiciona(void){
	for(*aux = 1; *aux < *countp; (*aux)=(*aux)+1){
		p2 = p2 + 1;
	}
	printf("\n\t pessoa %d\n",*countp);
	printf("\ndiga o nome: ");
	scanf("%s",&p2->nome);
	printf("diga a idade: ");
	scanf("%d",&p2->idade);
    printf("diga o numero de matricula: ");
	scanf("%d",&p2->mat);

}*/
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
	if(*countp==0){
		printf("\n\n nao ha pessoas na agenda!!");
	}	
	else{
		for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
		for(;(*aux) < (*countp) - 1;(*aux)++){
			*(p + (*aux)) = *(p + ((*aux) + 1));
			strcpy((p + (*aux))->nome,(p + ((*aux) + 1))->nome);
			(p + (*aux))->idade = (p + ((*aux) + 1))->idade;
			(p + (*aux))->mat = (p + ((*aux) + 1))->mat;
		}
		(*countp) = (*countp) - 1;
		buffer = realloc(buffer,(4*sizeof(int))+((*countp)*(sizeof(struct pessoa))));
	}
}
void busca(void){
	for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
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

int main(){
    alocapont();
    *countp = 0;
    *x = 0;
    while((*x) != 5 ){
        *aux = 0;
    	*i = 0;
		printf("\n\n\t\t-----menu-----");
		printf("\n-- 1 -- adiocionar");
		printf("\n-- 2 -- remover");
		printf("\n-- 3 -- buscar");
		printf("\n-- 4 -- listar");
		printf("\n\n\tdiga uma opcao: ");
		scanf("%d",x);
		
    	switch (*x) {
        	case 1:
            	realocapont();
            	adiciona();
            	break;
        	case 2:
        		printf("diga o numero de matricula da pessoa que deseja remover da agenda: ");
        		scanf("%d",i);
        		retira();
            	break;
        	case 3:
        		printf("diga o numero de matricula da pessoa desejada: ");
        		scanf("%d",i);
        		busca();
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