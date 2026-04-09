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

//-------------- INSERIR NO FIM DA LISTA ------------------

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
    
    if ((*lista) == NULL){ // se a lista estiver vazia.
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

//-------------- INSERIR NO INICIO DA LISTA ------------------

int insere_lista_inicio (Lista *lista, int x){
    if(lista == NULL){
        return 0;
    }
    
    cel* aux = (cel*) malloc(sizeof(cel));
    if(aux == NULL){
        return 0;
    }
    
    aux -> conteudo = x;
    aux -> seg = *lista; // acessando o primeiro item da Lista
    
    *lista = aux; // a lista apota para o novo primeiro item 
    
    return 1;
}


//-------------- IMPRIMIR LISTA ------------------

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

//-------------- BUSCA COM WHILE ------------------

int busca_while(Lista* lista, int x){
    if (lista == NULL){ return 0; } // se existe a lista
    if (*lista == NULL){ return 0; } // se a lista está vazia
    cel* aux = *lista;
    
    while(aux -> seg != NULL){ // anda até o final da lista
        if(aux -> conteudo == x){
        return 1;
        }
        else{
            aux = aux -> seg;
        }
    }

    return 0;
}

//-------------- BUSCA COM FOR ------------------

int busca_for(Lista* lista, int x){
    if (lista == NULL){ return 0; } // se existe a lista
    if (*lista == NULL){ return 0; } // se a lista está vazia
    cel* aux;
    
    for(aux = *lista; aux != NULL; aux = aux -> seg){
        if(aux -> conteudo == x){
            return 1;
        }
    }

    return 0;
}

//-------------- CONTAR ITENS DA LISTA ------------------

int contar_itens(Lista *lista){
    if(lista == NULL){
            printf("\nLista não existe\n");
        }
    if(*lista == NULL){
        printf("\nLista está vazia\n");
    }
    cel *aux;
    int contador = 0;
    
    for( aux = *lista; aux != NULL; aux = aux -> seg){
        contador++;
    }
    printf("\nTotal de itens: %d \n", contador);
}    


//-------------- EXCLUIR DA LISTA ------------------

void remove_item(Lista *lista, int x){
    cel *aux = (cel*) malloc(sizeof(cel));
    aux -> conteudo = x;
    aux -> seg = NULL;
    
}

//-------------- MAIN ------------------

int main()
{
    printf("Inicio\n");
    Lista *lst;
    lst = cria_lista();
       
    insere_lista_fim(lst, 1);
    insere_lista_fim(lst, 2);
    insere_lista_fim(lst, 3);
    insere_lista_fim(lst, 4);
    
    //insere_lista_inicio(lst, 0);
    //busca_for(lst, 3);
    contar_itens(lst);
    imprimir_lista(lst);
    return 0;
}
