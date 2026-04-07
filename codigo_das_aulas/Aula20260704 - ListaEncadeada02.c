/******************************************************************************

fazer inserção de celula no começo da lista...

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
    
}cel;

typedef struct cel* Lista;

Lista* cria_lista (){
    Lista *li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

-----------------------------------------------------

int insere_lista_fim (Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    cel* aux = (cel*) malloc(sizeof(cel));
    if (aux == NULL){
        return 0;
    }
    aux -> conteudo = x;
    aux -> seg = NULL;
    
    if ((*lista) == NULL){ // se a lsta estiver vazia.
        *lista = aux;
    }
    else{
        cel *temp;
        temp = *lista;
        while(temp -> seg != NULL){ // anda até o final da lista
            temp = temp -> seg;
        }
        temp -> seg = aux;
    }
    return 1;
}

-----------------------------------------------------

int insere_lista_inicio (Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    /*cel *temp; 
    temp = *lista;
    aux = temp -> seg;
        
    cel* aux = head;*/
    
    if (aux == NULL){
        return 0;
    }
    aux -> conteudo = x;
    aux -> seg = NULL;
    
    if ((*lista) == NULL){ // se a lsta estiver vazia.
        *lista = aux;
    }
    /*else{
        cel *temp;
        temp = *lista;
        temp -> seg = aux;
    }*/
    return 1;
}

-----------------------------------------------------

void imprimir_lista(Lista* lista){
    if(lista == NULL){
        printf("\nLista não existe\n");
    }
    if(*lista == NULL){
        printf("\nLista está vazia\n");
    }
    cel *temp;
        temp = *lista;
        printf("\nLista: ");
        while(temp != NULL){ // anda até o final da lista
        printf(" %d |", temp -> conteudo);
            temp = temp -> seg;
        }
        printf("\n");
}

-----------------------------------------------------

int main()
{
   printf("Inicio\n");
   Lista *lst;
   lst = cria_lista();
   
   insere_lista_fim(lst, 1);
   insere_lista_fim(lst, 2);
   insere_lista_fim(lst, 3);
   insere_lista_fim(lst, 4);

    imprimir_lista(lst);
    return 0;
}
