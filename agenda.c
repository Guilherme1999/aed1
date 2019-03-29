#include <stdio.h>
#include <stdlib.h>

struct pessoa{
    char nome[20];
    int idade,mat;
    };

void alocapont(void* buffer, struct pessoa* p, int* aux, int* countp, int* x){
    buffer = malloc(3*sizeof(int)+sizeof(struct pessoa));
    aux=(int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    p = (struct pessoa*)x + 1;
}
void realocapont(void* buffer, struct pessoa* p, int* aux, int* countp, int* x){
    *countp += *aux;
    buffer = realloc(buffer,(*countp)*sizeof(struct pessoa));
    aux = (int*)buffer;
    countp = (int*)aux + 1;
    x = (int*)countp + 1;
    p = (struct pessoa*)x + 1;
}
void adiciona(void* buffer, struct pessoa* p, int* aux, int* countp, int* x){
    realocapont(buffer,p,aux,countp,x);
}


int main(){
    void* buffer;
    struct pessoa* p = NULL;
    int*aux,*countp,*x;
    alocapont(buffer,p,aux,countp,x);
    *aux=0;
    *countp=0;
    *x=0;

    switch (*x) {
        case 1:
            adiciona();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;

    }


    free(buffer);

    return 0;
}
