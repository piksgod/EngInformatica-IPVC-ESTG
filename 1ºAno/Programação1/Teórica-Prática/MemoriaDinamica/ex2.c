#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Escreva um programa para receber o numero,o nome, e nota(decimal) de n alunos,calcular a media das notas e imprimir para o ecra a informaçao dos alunos
com nota superior à média. O numero de alunos (n) é introduzido pelo utilizador. 
O programa não deve impor limitações sobre o numero de alunos e deve reservar a memória estrimamente necessária.
*/
typedef struct aluno{
    int num;
    char nome[100];
    float nota;
}ALUNO;

int main(){
    ALUNO *alunos = NULL;
    int n = 0,i;
    float soma = 0, media =0;
    printf("Introduza o numero de alunos:\n");
    scanf("%i",&n);

    alunos = (ALUNO*)calloc(n,sizeof(ALUNO));

    if( alunos == NULL){
        printf("Out of memory!\n");return -1;

    }

    for(i=0;i<n;i++){
        printf("-----Novo Aluno-----\n");
        printf("Introduza o numero:\n");
        scanf("%i",&alunos[i].num);
        printf("Introduza a nota:\n");
        scanf("%f",&alunos[i].nota);
        printf("Introduza o nome:\n");
        scanf("%s", alunos[i].nome);
        soma += alunos[i].nota;

    }

    media = soma /n;
    printf("\n-----Alunos com nota > média-----\n");
    for(i=0;i<n;i++){
        if(alunos[i].nota > media){
            printf("Aluno(%d): Nº%i / Nome:%s / Nota:%.2f\n", i+1,alunos[i].num,alunos[i].nome,alunos[i].nota);
        }
    }
    free(alunos);
    return 0;
}