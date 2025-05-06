#include <stdio.h> 
#include <stdlib.h> 


typedef struct info { 
    int numero;
    char nome[100];
    int idade;

}INFO;

typedef struct Elem {

 INFO node;
 struct Elem *proximo;
 struct Elem *anterior;
}ELEMENTO;

//funcao de inserir à cabeça

int inserirInicio(ELEMENTO **inicio,ELEMENTO **fim,INFO pessoa){
    ELEMENTO *novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    if(novo == NULL){
        return 0;

    }

    novo->node = pessoa;

    if(*inicio == NULL){
        novo->proximo = NULL;
        novo->anterior = NULL;
        *inicio = novo;
        *fim = novo;
    }
    else {
        novo->proximo = *inicio;
        novo->anterior = NULL;
        (*inicio)->anterior = novo;
        *inicio = novo;
    }
    return 1;
}

//eliminar um elemento no inicio da lista

int eliminarInicio(ELEMENTO **inicio,ELEMENTO **fim){
    
    //se a lista estiver vazia
    if(*inicio == NULL){
        return 0;
    }

    //caso exista apenas um elemento na lista

    ELEMENTO *temp = *inicio;
    if(*fim == *inicio){

        *inicio = NULL;
        *fim = NULL;

    }
    else{
        *inicio = (*inicio)->proximo;
        (*inicio)->anterior = NULL;
    }
    
    free(temp);
    return 1;

}

//eliminar um elemento no fim da lista

int eliminarFim(ELEMENTO **fim,ELEMENTO **inicio){
    //se a lista estiver vazia
    if(*inicio == NULL){
        return 0;
    }

    //caso exista apenas um elemento na lista

    ELEMENTO *temp = *fim;
    if(*fim == *inicio){

        *inicio = NULL;
        *fim = NULL;

    }
    else{
        *inicio = (*inicio)->proximo;
        (*inicio)->anterior = NULL;
    }
    
    free(temp);
    return 1;
}

//listar elementos do fim para o principio da lista

void imprimeListaFimPrincipio(ELEMENTO *fim){
     ELEMENTO *temp = fim;
     while(temp != NULL){
        printf("Nome: %s, Idade:%d\n",temp->node.nome,temp->node.idade);
        temp = temp->anterior;
     }
}

//funcao que espera por tecla e imprime msg

void esperaTeclaMsg(){}



//funcao principal

void main(){

    //definir inicio e fim da lista duplamente ligada
    ELEMENTO *inicio = NULL;
    ELEMENTO *fim = NULL;
    INFO pessoa1 = {1,"Joao",12};
    INFO pessoa2 = {2,"Maria",22};
    INFO pessoa3 = {3,"Jose",25};

    inserirInicio(&inicio,pessoa1);
    inserirInicio(&inicio,pessoa2);
    inserirInicio(&inicio,pessoa3);

}