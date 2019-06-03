#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* buffer;
int* aux;
int* dir;
int* esq;
int* j;
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
	char* pn;
	unsigned int idade,mat;
};

void alocapont(void);
void realocapont(void);
void adiciona(void);
void retira(void);
void busca(void);
void listar(void);
void insertionSort(void);
void selectionSort(void);
void bubbleSort(void);
void quickSort(void);
void mergeSort(void);
void sort(void);

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
				//insertionSort();
				//selectionSort();
				//bubbleSort();
				*dir = *countp - 1;
				*esq = 0; 
				//quickSort();
        		listar();
				*x = 0;
            	break;
        	case 5:
            	break;
    	}
    }
    
    free(buffer);

    return 0;
}

void alocapont(void){
    buffer = malloc(8*sizeof(int) + sizeof(struct auxiliar));
    aux = buffer;
	dir = aux + 1;
	esq = dir + 1;
	j = esq + 1;
    countp = j + 1;
    x = countp + 1;
    i = x + 1;
	cname = i + 1;
	pa = (struct auxiliar*)(cname + 1);
}
void realocapont(void){
	buffer = realloc(buffer,(sizeof(struct auxiliar) + 8*sizeof(int) + (*countp)*sizeof(struct pessoa) + sizeof(char)*(*cname + strlen(pa->nome) + 1)));
	aux = buffer;
	dir = aux + 1;
	esq = dir + 1;
	j = esq + 1;
    countp = j + 1;
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
		buffer = realloc(buffer,(sizeof(struct auxiliar) + 8*sizeof(int) + (*countp)*sizeof(struct pessoa) + sizeof(char)*(*cname)));
		aux = buffer;
    	dir = aux + 1;
		esq = dir + 1;
		j = esq + 1;
    	countp = j + 1;
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

void insertionSort(void){
	for((*i)=1 ; (*i)<(*countp) ; (*i)++){
		(*aux) = (*i) - 1;
		pa->pn = (p + (*i))->nome;
		pa->idade = (p + (*i))->idade;
		pa->mat = (p + (*i))->mat;
		while((*aux >= 0) && (pa->mat < (p + (*aux))->mat)){
			(p + (*aux + 1))->nome = (p + (*aux))->nome;
			(p + (*aux + 1))->idade = (p + (*aux))->idade;
			(p + (*aux + 1))->mat = (p + (*aux))->mat;
			(*aux)--; 
		}
		(p + (*aux + 1))->nome = pa->pn;
		(p + (*aux + 1))->idade = pa->idade;
		(p + (*aux + 1))->mat = pa->mat;
	}
}
void selectionSort(void){
	*x = 0;
	for((*i)=0 ; (*i)<((*countp)-1) ; (*i)++){
		(*x) = (*i);
		for((*aux)=(*i)+1 ; (*aux)<(*countp) ; (*aux)++){
			if((p + (*x))->mat > (p + (*aux))->mat){
				(*x) = (*aux);
			}
		}
		if(*i != *x){
			pa->pn = (p + (*x))->nome;
			pa->idade = (p + (*x))->idade;
			pa->mat = (p + (*x))->mat;
			(p + (*x))->nome = (p + (*i))->nome;
			(p + (*x))->idade = (p + (*i))->idade;
			(p + (*x))->mat = (p + (*i))->mat;
			(p + (*i))->nome = pa->pn;
			(p + (*i))->idade = pa->idade;
			(p + (*i))->mat = pa->mat;
		}
	}
}
void bubbleSort(void){
	for(*i=0 ; *i < (*countp-1) ; (*i)++){
		for(*aux=0 ; *aux < (*countp-1)-*i ; (*aux)++){
			if((p + (*aux))->mat > (p + (*aux + 1))->mat){
				pa->pn = (p + (*aux + 1))->nome;
				pa->idade = (p + (*aux + 1))->idade;
				pa->mat = (p + (*aux + 1))->mat;
				(p + (*aux + 1))->nome = (p + (*aux))->nome;
				(p + (*aux + 1))->idade = (p + (*aux))->idade;
				(p + (*aux + 1))->mat = (p + (*aux))->mat;
				(p + (*aux))->nome = pa->pn;
				(p + (*aux))->idade = pa->idade;
				(p + (*aux))->mat = pa->mat;
			}
		} 
	}
}
void quickSort(void){
	(*i) = (*esq);
	(*aux) = (*dir);
	*x = (p + ((*esq + *dir)/2))->mat;
	do{
		while((p + (*i))->mat < (*x)){
			(*i)++;
		}
		while((p + (*aux))->mat > (*x)){
			(*aux)--;
		}
		if((*i) <= (*aux)){
			pa->pn = (p + (*aux))->nome;
			pa->idade = (p + (*aux))->idade;
			pa->mat = (p + (*aux))->mat;
			(p + (*aux))->nome = (p + (*i))->nome;
			(p + (*aux))->idade = (p + (*i))->idade;
			(p + (*aux))->mat = (p + (*i))->mat;
			(p + (*i))->nome = pa->pn;
			(p + (*i))->idade = pa->idade;
			(p + (*i))->mat = pa->mat;
			(*i)++;
			(*aux)--;
		}
	}
	while((*i) <= (*aux));
	if(*esq < *aux){
		*dir = *aux;
		quickSort();
	}
	if(*dir > *i){
		*esq = *i;
		quickSort();
	}
}
void mergeSort(){
	if(*esq >= *dir) return;
	(*aux) = (*esq + *dir)/2;
	*dir = *aux;
	mergeSort();
	*esq = *aux + 1;
	mergeSort();
	//sort();
}
void Sort(){
	(*x) = (*esq);
	(*j) = (*aux) + 1;
	for(*i=*esq ; *i <= *dir ; (*i)++){
		
	}
}
