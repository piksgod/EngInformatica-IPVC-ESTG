#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    int numeroAluno,contador=0;
    float nota1,nota2,notaTP;
    float notaFinal;

    FILE *fp = NULL;
   
    fp = fopen("notas.txt","r");
    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        exit(-1);
    }

    while (fscanf(fp, "%d;%f;%f;%f", &numeroAluno, &nota1, &nota2, &notaTP) == 4) {
        
        notaFinal = (nota1 * 0.25) + (nota2*0.25) + (notaTP*0.5);
        if(notaFinal>=9.5){
            printf("O aluno %d aprovou com nota %.2f\n",numeroAluno,notaFinal);
            contador++;
        }
    }
printf("Número de alunos aprovados: %d\n",contador);
return 0;
}