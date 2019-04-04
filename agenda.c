#include <stdio.h>
#include <stdlib.h>

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
    buffer = malloc(4*sizeof(int)+sizeof(struct pessoa));
    aux=(int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
    p2 = (struct pessoa*)i + 1;
}
void realocapont(void){
    *countp += *i;
    buffer = realloc(buffer,4*sizeof(int) + (*countp)*sizeof(struct pessoa));
    aux = (int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
    if((*countp)==(*i)) p2 = (struct pessoa*)i + 1;
    else p2 = (struct pessoa*)p + (*i);
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
	for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
	for(;(*aux) < (*countp) - 1;(*aux)++){
			*(p + (*aux)) = *(p + ((*aux) + 1));
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
    while((*x) != 5 ){
    	*i = 0;
    	*aux = 0;
    	*x = 0;
		printf("\n\n\tdiga uma opcao: ");
		scanf("%d",x);

    	switch (*x) {

        	case 1:
            	printf("diga a quantidade de pessoas que deseja adicionar a agenda: ");
            	scanf("%d",i);
            	realocapont();
            	adiciona();
            	break;
        	case 2:
        		printf("diga o numero de matricula da pessoa que deseja remover da agenda: ");
        		scanf("%d",i);
        		retira();
        		realocapont();
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