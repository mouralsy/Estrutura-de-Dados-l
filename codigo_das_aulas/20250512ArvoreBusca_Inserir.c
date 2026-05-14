#include <stdio.h>
#include <stlib.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

structdef struct NO NO;

structdef struct NO* ArvBin;

//----------------------------------------------------//

ArvBin* criar_arvore(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if (raiz!=NULL){
        *raiz = NULL;
    }
    return raiz;
}

//-----------------------------------------------------//

int insere_ArvBin (ArvBin *raiz, int valor){
    if(raiz == NULL){return 0;}

    NO* novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){return 0;}

    novo -> info = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;

    if ((*raiz) == NULL){ //prmeiro elemento
        *raiz = novo;
    }else{
        NO *atual = *raiz;
        NO *ant = NULL;
        while(atual != NULL){
        ant = atual;
            if(valor == atual -> info){
                free(novo);
                return 0;
            }
            if(valor > atual -> info){
                atual = atual -> dir;
            }else{
                atual = atual -> esq;
            }    
        }
        if(valor > ant -> info){
            ant -> dir = novo;
        }else{
            ant -> esq = novo;
        }    
  return 1;
}

//--------------------------------------------------------//

int main(){

    printf("Arvore Binaria de Busca\n");

};
