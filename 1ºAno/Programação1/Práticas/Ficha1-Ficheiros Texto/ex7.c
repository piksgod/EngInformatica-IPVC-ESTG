#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void adicionarInscricoes(){

    char nome[100];

    FILE *fp = fopen("CimeiraIPVC2024.txt","a");
    if(fp==NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        exit(-1);
    }

    printf("Nova Inscrição:\nDigite os seus dados no seguinte formato: (nome,nome da sua Universidade,numero de telemóvel): ");
    fgets(nome,100,stdin);
    nome[strcspn(nome,"\n")]= '\0';
    fprintf(fp,"Inscrição\n%s\n" ,nome);
    


    fclose(fp);

    
}

void listarInscricoes(){
    char linha[100];
    FILE *fp = fopen("CimeiraIPVC2024.txt","r");
    if(fp==NULL){
        printf("Nenhuma inscrição encontrada!\n");
        exit(-1);
    }

    printf("-------Lista de inscrições-------\n");
    while(1){
        char ch = fgetc(fp);
        if(ch == EOF) break;
        putchar(ch);
    }

    fclose(fp);
}


int main(){
    adicionarInscricoes();
    listarInscricoes();


}