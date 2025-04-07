#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char *nome =NULL;
    nome = (char*)malloc(10);
    if(nome == NULL){
        printf("Out of memory!\n");
        return -1;

    }

    strcpy(nome,"Diogo\n");

    nome = (char*)realloc(nome,100);

    if(nome == NULL){
        printf("Erro!\n");
        return -1;

    }

    strcat(nome,"Filipe dos Santos Meira\n");
    printf("%s",nome);
    free(nome);
    return 0;
}