#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = NULL;
    char nome[100];
    int ch;

    printf("Escreva o nome do ficheiro incluindo a extensão:\n");
    scanf("%99s",nome);

    fp = fopen(nome,"r");

    if(fp == NULL){
        printf("Erro ao abrir o ficheiro\n");
        exit(-1);
    }

    
    while(1){
        ch = fgetc(fp);
        if(ch == EOF) break;
        putchar(ch);
    }

    fclose(fp);
    return 0;
    
}