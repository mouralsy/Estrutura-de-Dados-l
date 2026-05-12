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
    if((*raiz) == NULL){
        *raiz = aux;
    }

    NO* aux = (NO*) malloc(sizeof(NO));
    if(aux == NULL){return 0;}

    aux -> info = valor;

    if(valor < raiz){
        if(aux -> esq == NULL){}
            NO *temp;
            temp = *raiz;
            while(temp -> esq != NULL){
                temp = temp -> esq;
            }
            temp -> info = aux;
        }
    }
    else{
        if(aux -> dir == NULL){
            NO *temp;
            temp = *raiz;
            while(temp -> dir != NULL){
                temp = temp != dir;
            }
            temp -> info = aux;
        }
    }
    return 1;
}

//--------------------------------------------------------//

int main(){

    printf("Arvore Binaria de Busca\n");

};
