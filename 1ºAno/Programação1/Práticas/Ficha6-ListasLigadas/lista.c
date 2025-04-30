#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "lista.h"

//implementacao com lista ligada
//definicao de um NO da lista

typedef struct Elem{
        INFO colaborador;
        struct Elem*next;

}ELEMENTO;

//definicao da lista em memoria
ELEMENTO *lista = NULL;

//FUNCOES AUXILIARES

int criaLista(){
    lista = NULL;
    return 1;
}

int limpaLista(){

    ELEMENTO *aux=lista;
    ELEMENTO *proximo = NULL;

    while(aux != NULL){
        proximo = aux->next;
        free(aux);
        aux = proximo;
    }
    lista = NULL;
    printf("Lista limpa!\n");
    return 1;

}

int gravarDados(char nomeFicheiro[]){

    /*
    PARA FAZER COISAS CORRIDAS EM LISTAS:
    1º criar apontador temporario para o inicio
    2º iterar(com while normalmente) enquanto o temp for != de NULL
    3º fazer o que pretendemos
    4º avançar na lista
    */

      FILE *fp = NULL;
      fp = fopen(nomeFicheiro,"wb");

      if(fp == NULL){
      printf("Erro ao abrir o ficheiro!\n");
      return 0;
      }

      ELEMENTO *aux = lista;

      while(aux != NULL){
        fwrite(&aux->colaborador,sizeof(INFO),1,fp);
        aux = aux->next;
      }

      fclose(fp);
      return 1;
}

int leDados(char nomeFicheiro[]){

    FILE *fp = NULL;

    fp = fopen(nomeFicheiro,"rb");
    if(fp == NULL){
        printf("Erro ao abrir o ficheiro!\n");
        return 0;
    } else {
        criarLista();
    }

    ELEMENTO *novo=NULL;

    while(!feof(fp)){
        INFO temp;
        fread(&temp,sizeof(INFO),1,fp);

        //insere no inicio da lista
        novo = (ELEMENTO *)malloc(sizeof(ELEMENTO)); //criar apontador temp para inicio
        novo->colaborador = temp;
        novo->next= lista;
        lista = novo;
    }

    fclose(fp);
    return 1;

}

int existeColab(char NIF[]){

    if(lista == NULL){
        return 0;
    }

    ELEMENTO *aux = lista;

    while(aux != NULL){
        if(strcmp(aux->colaborador.NIF,NIF)==0){
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

int existeColabNum(int numero){

    if(lista == NULL){
        return 0;
    }

    ELEMENTO *aux = lista;

    while(aux != NULL){

        if(aux->colaborador.numero == numero){
            return 1;
        }
        aux = aux->next;
        }
        return 0;
}


//FUNCOES PRINCIPAIS

int insereColab(INFO colaborador){
    
    if(existeColab(colaborador.NIF)==1){
        printf("Erro: Já existe um colaborador com o NIF %s\n", colaborador.NIF);
        return 0;
    }else if(existeColabNum(colaborador.numero)==1){
        printf("Erro: Já existe um colaborador com o número %d\n", colaborador.numero);
        return 0;
    }

    ELEMENTO *novo = (ELEMENTO *)malloc(sizeof(ELEMENTO));

    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return 0;
    }

    novo->colaborador = colaborador;
    novo->next = lista;
    lista = novo;
    return 1;


}

int listaColaboradores(){

    ELEMENTO *atual = lista;
    int count = 0;

    printf("\n--- Lista de Colaboradores---\n");

    if(atual == NULL){
        printf("Não há colaboradores registados.\n");
        return;
    }

    while(atual != NULL){
        printf("\nColaborador #%d\n", ++count);
        printf("Número: %d\n", atual->colaborador.numero);
        printf("Nome: %s\n", atual->colaborador.nome);
        printf("NIF: %s\n", atual->colaborador.NIF);
        printf("Data Nascimento: %s\n", atual->colaborador.dataNasc);
        printf("Salário: %.2f\n", atual->colaborador.salario);
        
        atual = atual->next;
    }
    return 1;
}

int listaColaborador(int numero){
    ELEMENTO *atual = lista;
    int count = 0;

    

    if(atual == NULL){
        printf("Não há colaboradores registados.\n");
        return;
    }

    while(atual != NULL){
        printf("\nColaborador #%d\n", ++count);
        printf("Número: %d\n", atual->colaborador.numero);
        printf("Nome: %s\n", atual->colaborador.nome);
        printf("NIF: %s\n", atual->colaborador.NIF);
        printf("Data Nascimento: %s\n", atual->colaborador.dataNasc);
        printf("Salário: %.2f\n", atual->colaborador.salario);
        
        return 1;
    }
    

}

//funcao auxiliar recursiva 
float somaSalRecursivoAux(ELEMENTO *l){
    if(l == NULL){
        return 0;
    }
    return lista->colaborador.salario + somaSalRecursivoAux(l->next);
}
float somaSalRecursivo(){
    if(lista == NULL){
        return 0;
    }
    return somaSalRecursivoAux(lista);
}

int numeroColab(){
    int total = 0;

    ELEMENTO *atual = lista;

    while(atual != NULL){
        total++;
        atual = atual->next;
    }
    printf("\n---Total de Colaboradores---\n");
    printf("A empresa tem %d colaborador(es) no momento!\n",total);

}

float mediaSal(){
    float media;
    int soma = somaSalRecursivo();
    
    media = soma / numeroColab();

    return media;
}