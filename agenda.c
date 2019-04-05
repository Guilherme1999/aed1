#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[20];
    int idade,mat;
    };
void* buffer;
struct pessoa* p,*p2;
int* aux;
 int* countp;
 int* x;
 int* i;

void alocapont(void){
    buffer = malloc(sizeof(int)*4 + sizeof(struct pessoa));
    aux=(int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
    p2 = (struct pessoa*)i + 1;
}
void realocapont(void){
    *countp += *i;
    buffer = realloc(buffer,(sizeof(int)*4 + sizeof(struct pessoa)*(*countp)));
   /* aux = (int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;*/
    if((*countp)==(*i)){
		//p2 = (struct pessoa*)i + 1;
		p2 = p;
	}
    else{
		p2 = p + (*i);
	}
}
void adiciona(void){
    for(*aux = 0;(*aux) < (*i);(*aux)++){
        printf("\n\t pessoa %d\n",(*aux) + 1);
        printf("\ndiga o nome: ");
        scanf("%s",p2->nome);
        printf("diga a idade: ");
        scanf("%d",&p2->idade);
        printf("diga o numero de matricula: ");
        scanf("%d",&p2->mat);
        p2++;
    }

}
void retira(void){
	for(*aux = 0;(*aux) < (*countp) && (*x) != (p + (*aux))->mat;(*aux)++);
	for(;(*aux) < (*countp) - 1;(*aux)++){
			*(p + (*aux)) = *(p + ((*aux) + 1));
			strcpy((p + (*aux))->nome,(p + ((*aux) + 1))->nome);
			(p + (*aux))->idade = (p + ((*aux) + 1))->idade;
			(p + (*aux))->mat = (p + ((*aux) + 1))->mat;
	}
	(*countp) = (*countp) - 1;
}
void busca(void){
	for(*aux = 0;(*aux) < (*countp) && (*x) != (p + (*aux))->mat;(*aux)++);
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
	printf("\n\nlistando..\n");
    for(*aux = 0;(*aux) < (*countp);(*aux)++){
    	printf("\n\t pessoa %d\n",(*aux) + 1);
   		printf("\n%s\n",(p + (*aux))->nome);
		printf("%d\n",(p + (*aux))->idade);
       	printf("%d\n",(p + (*aux))->mat);
   	}
}


int main(){
    alocapont();
    *countp = 0;
	*x = 0;
    while((*x) != 5 ){
    	*i = 0;
    	*aux = 0;
		printf("\n\n\tdiga uma opcao: ");
		scanf("%d",x);

    	switch (*x) {

        	case 1:
            	printf("\ndiga a quantidade de pessoas que deseja adicionar a agenda: ");
            	scanf("%d",i);
            	realocapont();
            	adiciona();
            	break;
        	case 2:
        		printf("\ndiga o numero de matricula da pessoa que deseja remover da agenda: ");
        		scanf("%d",x);
        		retira();
				//buffer = realloc(buffer,(sizeof(int)*4 + sizeof(struct pessoa)*(*countp)));
        		realocapont();
				*x = 0;
            	break;
        	case 3:
        		printf("\ndiga o numero de matricula da pessoa desejada: ");
        		scanf("%d",x);
        		busca();
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