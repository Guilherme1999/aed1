#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[20];
    int idade,mat;
    };

/*void* alocapont(void* buffer, struct pessoa* p, int* aux, int* countp, int* x, int* i){
    buffer = malloc(3*sizeof(int)+sizeof(struct pessoa));
    aux=(int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
    return buffer;
}*/
void realocapont(void* buffer, struct pessoa* p, int* aux, int* countp, int* x, int* i){
    //*countp += *aux;
    buffer = realloc(buffer,(*countp)*sizeof(struct pessoa));
    aux = (int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
}
void adiciona(struct pessoa* p, int* countp, int* aux){
    for(*aux = 0;(*aux) < (*countp);(*aux)++){
        printf("\n\t pessoa %d\n",(*aux) + 1);
        printf("\ndiga o nome: ");
        scanf("%s",(p + (*aux))->nome);
        //fgets((p + (*aux))->nome,20,stdin);
        printf("diga a idade: ");
        scanf("%d",&(p + (*aux))->idade);
        printf("diga o numero de matricula: ");
        scanf("%d",&(p + (*aux))->mat);
    }
}
void retira(struct pessoa* p, int* countp, int* aux, int* i){
	for(*aux = 0;(*aux) < (*countp) && (*i) != (p + (*aux))->mat;(*aux)++);
	for(;(*aux) < (*countp) - 1;(*aux)++){
			*(p + (*aux)) = *(p + ((*aux) + 1));	
	}
}
void busca(struct pessoa* p, int* countp, int* aux, int* i){
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
void listar(struct pessoa* p, int* countp, int* aux){
	printf("\n\nlistando..\n");
    for(*aux = 0;(*aux) < (*countp);(*aux)++){
    	printf("\n\t pessoa %d\n",(*aux) + 1);
   		printf("\n%s\n",(p + (*aux))->nome);
		printf("%d\n",(p + (*aux))->idade);
       	printf("%d\n",(p + (*aux))->mat);
   	}
}


int main(){
    void* buffer;
    struct pessoa* p = NULL;
    int*aux, *countp, *x, *i;
	buffer = malloc(4*sizeof(int)+sizeof(struct pessoa));
    aux = (int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    i = (int*)x + 1;
    p = (struct pessoa*)i + 1;
    //buffer = alocapont(buffer,p,aux,countp,x);
    *countp = 0;
    while((*x) != 5 ){
    	*i = 0;
    	*x = 0;
    	*aux = 0;
		printf("\n\n\tdiga uma opcao: ");
		scanf("%d",x);
		
    	switch (*x) {
    
        	case 1:
            	printf("diga a quantidade de pessoas que deseja adicionar a agenda: ");
            	scanf("%d",countp);
            	realocapont(buffer,p,aux,countp,x,i);
            	adiciona(p,countp,aux);
            	break;
        	case 2:
        		printf("diga o numero de matricula da pessoa que deseja remover da agenda: ");
        		scanf("%d",i);
        		retira(p,countp,aux,i);
        		//realocapont(buffer,p,aux,countp,x,i);*/
        	    buffer = realloc(buffer,((*countp)--)*sizeof(struct pessoa));
    			aux = (int*)buffer;
    			countp = (int*)aux + 1;
   				x = (int*)countp + 1;
   				i = (int*)x + 1;
    			p = (struct pessoa*)i + 1;
            	break;
        	case 3:
        		printf("diga o numero de matricula da pessoa desejada: ");
        		scanf("%d",i);
        		busca(p,countp,aux,i);
            	break;
        	case 4:
        		listar(p,countp,aux);
            	break;
        	case 5:
            break;
    	}
    }
    
    free(buffer);

    return 0;
}
