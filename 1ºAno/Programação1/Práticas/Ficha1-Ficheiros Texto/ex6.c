#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    float nota1,nota2,notaTP,notaFinal;
    float somanotas1=0,somanotas2=0,somanotasTP=0;
    float notaMaximaTP = -1,notaMinimaTeste1 = 20;

    int numeroAluno,totalAlunos = 0;

    int alunosMelhorTP[100],alunosPiorTeste1[100];
    int numMelhores = 0, numPiores = 0;

    FILE *fp = NULL;
    fp = fopen("notas.txt","r");
    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        exit(-1);
    }
    while(fscanf(fp,"%d;%f;%f;%f",&numeroAluno,&nota1,&nota2,&notaTP)==4){

        totalAlunos++;
        somanotas1 += nota1;
        somanotas2 += nota2;
        somanotasTP +=notaTP;

        if(notaTP > notaMaximaTP){

            notaMaximaTP = notaTP;
            numMelhores = 0;
            alunosMelhorTP[numMelhores++] = numeroAluno;

        }else if(notaTP == notaMaximaTP){
            alunosMelhorTP[numMelhores++]= numeroAluno;
        }

        if(nota1 <notaMinimaTeste1){
            notaMinimaTeste1 = nota1;
            numPiores = 0;
            alunosPiorTeste1[numPiores++] = numeroAluno;
        }else if(nota1== notaMinimaTeste1){
            alunosPiorTeste1[numPiores++] = numeroAluno;
        }

    }

    printf("Média das notas do primeiro teste: %.2f\n",somanotas1/totalAlunos);
    printf("Média das notas do segundo teste: %.2f\n",somanotas2/totalAlunos);
    printf("Média das notas TP: %.2f\n", somanotasTP/totalAlunos);

    printf("Aluno(s) com melhor nota no TP: \n");
    for(int i =0;i< numMelhores;i++){
        printf("%d/",alunosMelhorTP[i]);

    }
    printf("\n");

    printf("Aluno(s) com pior nota no primeiro teste:\n");

    for(int i=0;i<numPiores;i++){
        printf("%d/",alunosPiorTeste1[i]);

    }
    printf("\n");

    return 0;
    
}