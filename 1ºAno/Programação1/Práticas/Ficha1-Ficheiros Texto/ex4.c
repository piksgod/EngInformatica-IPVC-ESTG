#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    float nota1,nota2,notaTP;
    int numeroAluno;
    char nomeFicheiro[100];


    FILE *fp = NULL;
    printf("Escreva o nome de ficheiro prentendido:\n");
    fgets(nomeFicheiro,100,stdin);
    nomeFicheiro[strcspn(nomeFicheiro,"\n")]= '\0';


    fp = fopen(nomeFicheiro,"w");

    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro\n");
        exit(-1);
    }

    

    while(1){
        printf("Escreva o número de aluno(0 para terminar):\n");
        scanf("%d",&numeroAluno);

        if(numeroAluno == 0){
            
            printf("Terminado com sucesso!\n");
            exit(0);
        
        }
            printf("Escreva a nota do primeiro teste do aluno %d :\n",numeroAluno);
            scanf("%f",&nota1);
            printf("Escreva a nota do segundo teste do aluno %d:\n",numeroAluno);
            scanf("%f",&nota2);
            printf("Escreva a nota do trabalho prático do aluno %d:\n",numeroAluno);
            scanf("%f",&notaTP);

            fprintf(fp,"%d;%.2f;%.2f;%.2f\n",numeroAluno,nota1,nota2,notaTP);
        }
        
        return 0;
        
    }
    
