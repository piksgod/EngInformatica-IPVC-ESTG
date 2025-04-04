#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno{
    int num;
    char nome[100];
    char curso[100];
}INFO;

typedef struct elem{
    INFO info;
    struct elem *seguinte;
}ELEM;

int inserirIniLista(ELEM **iniLista, INFO newinfo){
    ELEM *novo = NULL;
    novo = (ELEM*)malloc(sizeof(ELEM));

    if(novo == NULL){
        printf("Out of memory!\n");
        return -1;
    }
    novo->info = newinfo;
    novo->seguinte =NULL;
    
    if(*iniLista==NULL){
        *iniLista=novo;
    }
    else{

        novo->seguinte = *iniLista;
        *iniLista = novo;
    }
    return 0;
}
INFO getInfo(){
    INFO aluno;
    printf("Int. o num:\n");
    scanf("%i",&aluno.num);
    printf("Nome:\n");
    scanf("%s",aluno.nome);
    printf("Curso:\n");
    scanf("%s",aluno.curso);
    return aluno;
}
int printLista(ELEM *iniLista){

    ELEM *aux = NULL;

    if(iniLista==NULL){

        printf("Lista Vazia\n");
        return -1;

    }
    
    for(aux=iniLista;aux!=NULL;aux=aux->seguinte){
        printf("%i-%s-%s\n",aux->info.num,aux->info.nome,aux->info.curso);
    }
    return 0;
}
int main(){
    ELEM *iniLista = NULL;
    INFO aluno;
    int opcao = 0;

    do{
        printf("Int. a opcao:\n1-Inserir\n2-Listar\n0-Sair\n");
        scanf("%i",&opcao);
        switch(opcao){

            case 1: aluno = getInfo();
            inserirIniLista(&iniLista,aluno);
            break;
            case 2: printLista(iniLista);
            break;
            case 0: break;
        }

    }while(opcao);
}