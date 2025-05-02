#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct produto {
    int id;
    char nome[100];
    float preco;

}INFO;

typedef struct elem {
    INFO info;
    struct elem *seguinte;
    struct elem *anterior;
}ELEM;

int main(){
    ELEM *inilista = NULL, *seguinte = NULL;
}

int inserirIniLista(ELEM **iniLista, ELEM **fimLista,INFO newInfo){

    ELEM *novo = NULL;

    novo = (ELEM*)calloc(1,sizeof(ELEM));
    if(novo == NULL){
        printf("Ocorreu um erro na alocação da memória!\n");
        return -1;
    }

    novo->info=newInfo;
    novo->seguinte = NULL;
    novo->anterior = NULL;
    if(*iniLista == NULL){
        *iniLista = novo;
        *fimLista = novo;
    } else {
        novo->seguinte = iniLista;
        (*iniLista)->anterior = novo;
        (*iniLista) = novo;
    }
    return 0;
}

void printListaIni(ELEM *iniLista){
    ELEM *aux = NULL;
    if(iniLista == NULL){printf("Lista Vazia!\n");
    return;
}
for(aux =iniLista;aux!=NULL;aux = aux->seguinte){
    printf("%i-%s %.2f\n",aux->info.id,aux->info.nome,aux->info.preco);
}
return;
}

void printListaFim(ELEM *fimLista){
    ELEM *aux = NULL;
    if(fimLista== NULL){
        printf("Lista Vazia!\n");
        return;
    }
    for(aux=fimLista;aux!=NULL;aux= aux->anterior){
        printf("%i-%s %.2f\n",aux->info.id,aux->info.nome,aux->info.preco);
    }
    return;
}
int inserirFimLista(ELEM**iniLista,ELEM**fimLista,INFO newInfo){
    ELEM *novo = NULL;
    novo = (ELEM*)calloc(1,sizeof(ELEM));
    if(novo==NULL){
        printf("Out of memory!\n");
        return -1;
    }
    novo->info = newInfo;
    novo->seguinte = NULL;
    novo->anterior = NULL;
    if(*fimLista == NULL){
        *iniLista = novo; *fimLista = novo;
    } else {
        novo->anterior = (*fimLista);
        (*fimLista)->seguinte = novo;
        (*fimLista) = novo;
    }
    return 0;
}

float calculaMediaLista(ELEM**iniLista){
    ELEM *aux = NULL;
    int count = 0;
    float soma = 0,media = 0;

    if(iniLista== NULL){
        printf("Lista vazia!\n");
        return 0;
    }

    for(aux = iniLista;aux=NULL;aux=aux->seguinte){
        count++;
        soma+=aux->info.preco;
    }
    return (soma/count);
}

int removeIni(ELEM **iniLista,ELEM**fimLista){
    ELEM *aux = NULL;
    if(*iniLista==NULL){return 0;}
    aux = *iniLista;
    if(aux->seguinte == NULL){
        *fimLista = NULL;
        *iniLista = NULL;
    } else { 
        aux->seguinte->anterior=NULL;
        (*iniLista) = aux->seguinte;
    }
    free(aux);
    return 0;
}

int removeFim(ELEM **iniLista, ELEM **fimLista){
    ELEM *aux = NULL;
    if(*fimLista == NULL){
        return 0;
    }
    aux = *fimLista;
    if(aux->anterior==NULL){
        *fimLista = NULL;
        *iniLista = NULL;
    }
    else{
        aux->anterior->seguinte=NULL;
        (*fimLista)= aux->anterior;
    }
    free(aux);
    return 0;
}

void libertaLista(ELEM**iniLista,ELEM**fimLista){
    ELEM *aux = NULL,*aux2=NULL;
    if(*iniLista==NULL){return;}
    aux = iniLista;

    while(aux!=NULL){
        aux2 = aux->seguinte;
        free(aux);
        aux=aux2;
    }
    *iniLista = NULL;
    *fimLista = NULL;

}