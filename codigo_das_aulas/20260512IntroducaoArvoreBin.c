#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
};
typedef struct NO NO;
typedef struct NO* ArvBin;

ArvBin * cria_ArvBin(){
  ArvBin* raiz= (ArvBin*) malloc(sizeof(ArvBin));
  if(raiz!=NULL){
      *raiz = NULL;
  }
  return raiz;
}

//-------------IMPRIMIR------------------
/* Função auxiliar recursiva */
void imprime_NO(struct NO *no, const char *prefixo, int ehUltimo, char lado){
  if(no == NULL){ return;}
  printf("%s", prefixo);
  if(ehUltimo){printf("└── ");
  } else {printf("├── ");}
  if(lado == 'E'){printf("E: ");
  } else if(lado == 'D'){printf("D: ");}
  printf("%d\n", no->info);
  char novoPrefixo[1000];
  snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
  if(no->esq != NULL){
    imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
  }
  if(no->dir != NULL){
    imprime_NO(no->dir, novoPrefixo, 1, 'D');
  }
}
/* Função principal de impressão */
void imprime_ArvBin(ArvBin *raiz){
  if(raiz == NULL || *raiz == NULL){
    printf("Árvore vazia.\n");
    return;
  }
  printf("%d\n", (*raiz)->info);
  if((*raiz)->esq != NULL){
    imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
  }
  if((*raiz)->dir != NULL){
    imprime_NO((*raiz)->dir, "", 1, 'D');
  }
}


//---------------------------------------

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    NO *novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->esq =NULL;
    novo->dir =NULL;

    if(*raiz == NULL){//primeiro elemento
        *raiz = novo;
    }
    else{//folha
        NO *atual = *raiz;
        NO *ant = NULL;
        while(atual!=NULL){
            ant = atual;
            if(valor==atual->info){//repetido
                free(novo);
                return 0;
            }
            if(valor>atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor>ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

//---------------------------------------

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}
    else{
        NO *atual = *raiz;
        while(atual!=NULL){
            if(valor==atual->info){return 1;}
            if(valor>atual->info){atual = atual->dir;
            }else{atual = atual->esq;}
        }
    }
    return 0;
}


//---------------------------------------

int altura_ArvBin(ArvBin* raiz){
  return 1;
}

//---------------------------------------


int totalNosArvBin(ArvBin* raiz){
  if(raiz == NULL || (*raiz) == NULL){ return 0; }

  int no_esq = totalNosArvBin(&((*raiz) -> esq));
  int no_dir = totalNosArvBin(&((*raiz) -> dir));
  
  return no_esq + no_dir + 1;
}

//---------------------------------------


void preOrdem_arvBin(ArvBin *raiz){

}

//---------------------------------------


void emOrdem_arvBin(ArvBin *raiz){

}

//---------------------------------------


void posOrdem_arvBin(ArvBin *raiz){
  
}

//---------------------------------------


int main(void) {

  ArvBin* raiz = cria_ArvBin();
  int N = 10,dados[10] = {28,16,40,11,21,36,48,19,32,56};
  for(int i=0;i<N;i++){
    insere_ArvBin(raiz, dados[i]);
  }

  int altura = altura_ArvBin(raiz);
  printf("\nAltura: %d ",altura);
  int quantidade = totalNosArvBin(raiz);
  printf("\nQuantidade: %d ",quantidade);

  printf("\nPréOrdem:");
  preOrdem_arvBin(raiz);
  printf("\nEmOrdem:");
  emOrdem_arvBin(raiz);
  printf("\nPosOrdem:");
  posOrdem_arvBin(raiz);
  printf("\nFinalizou.\n");

  imprime_ArvBin(raiz);
  return 0;
}
