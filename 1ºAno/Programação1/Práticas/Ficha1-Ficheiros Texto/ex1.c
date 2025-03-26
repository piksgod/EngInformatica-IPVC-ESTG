#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int numero;
    char nomeCurso[100],disciplinas[100],nome[100];

    FILE *fp = NULL;

    fp = fopen("curriculum.txt","w");
    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro\n");
        exit(-1);

    }
    else 
    {
        printf("Escreva o seu nome:\n");
        fgets(nome,100,stdin);
        nome[strcspn(nome,"\n")]= '\0';
        fprintf(fp,"Nome: %s\n",nome);

        printf("Escreva o seu número de aluno:\n");
        scanf("%d",&numero);
        while(getchar()!= '\n');
        fprintf(fp,"Número de Aluno: %d\n",numero);

        printf("Escreva o nome do seu curso:\n");
        fgets(nomeCurso,100,stdin);
        nomeCurso[strcspn(nomeCurso,"\n")] = '\0';
        fprintf(fp,"Nome do Curso: %s\n",nomeCurso);
        
        printf("Indique as cadeiras feitas e quando terminar escreva 'fechar' :\n");
        while(1){

            printf("> ");
            fgets(disciplinas,100,stdin);
            disciplinas[strcspn(disciplinas, "\n")]= '\0';

            if (strcmp(disciplinas, "fechar")== 0){

                break;
            }

            fprintf(fp,"Disciplina: %s\n",disciplinas);

            
        }
       

        
    }

    fclose(fp);
    
}