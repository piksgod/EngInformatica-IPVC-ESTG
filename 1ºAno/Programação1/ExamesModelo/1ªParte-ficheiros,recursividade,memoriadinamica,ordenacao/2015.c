#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
//----------------------EXERCICIO 1-------------------------
/*
int escreveLicenciaturas(char licenciaturas[MAX][100]){
    
    FILE *fp = NULL;
    fp= fopen("licenciatura.txt","w");
    if(fp==NULL){
        printf("Erro ao abrir o ficheiro!\n");
        return -1;
    }

    for(int i = 0 ; i<MAX;i++){
        if(licenciaturas[i][0] != '\0'){
        fprintf(fp,"%s\n",licenciaturas[i]);
        }
    }
    fclose(fp);
    return 0;

}
int main(){
    char licenciaturas[MAX][100] = {
        "Programacao",
        "Sistemas Operativos",
        "Matematica",
        "Fisica",
        ""  // string vazia indica fim das licenciaturas
    };
    
    escreveLicenciaturas(licenciaturas);
    return 0;
}

//----------------------FIM EXERCICIO 1-------------------------*/


//----------------------EXERCICIO 2-------------------------

typedef struct  curso{ 
    char  nome[100], instituicao[100]; 
    char tipo;       // L-Licenciatura; M- Mestrado; C- CET; O-outros 
    int  nVagas; 
} CURSO; 
//----------------------EXERCICIO 2a-------------------------
/*
int gravaCursos(CURSO cursos[],int total){

    FILE *fp = fopen("cursos.dat","wb");

    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        return -1;
    }

    fwrite(cursos, sizeof(CURSO), total, fp);

    printf("Dados escritos!\n");


    fclose(fp);
    return 0;

}
int main() { 
CURSO cursos [1500];  int total=1 ; 
strcpy(cursos[0].instituicao, "IPVC");
strcpy(cursos[0].nome, "EngInf");
cursos[0].nVagas = 12;
cursos[0].tipo = 'L';
gravaCursos(cursos,total);
return 0;
}
//----------------------FIM EXERCICIO 2a-------------------------*/


//----------------------EXERCICIO 2b-------------------------
/*
int ordenaCursos(CURSO *cursos,int tam){
    CURSO temp;
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-i-1;j++){
            if(strcmp(cursos[j].nome,cursos[j+1].nome)>0){
                temp = cursos[j];
                cursos[j]=cursos[j+1];
                cursos[j+1]=temp;

            }
        }
    }
}

//----------------------FIM EXERCICIO 2b-------------------------*/

//----------------------EXERCICIO 2c-------------------------
/*
int main(){

    CURSO *cursos;int total=0;

    printf("Diga o número total de cursos:\n");
    scanf("%d",&total);
    if(total <=0|| total >1500){
        printf("Tem de ser um número entre 1 e 1500.\n");
        return -1;
    }

    
    
    cursos = (CURSO*)malloc(sizeof(CURSO)*total);
    if(cursos == NULL){
        printf("Erro na alocação dinâmica da memória!\n");
        return -1;
    }
    free(cursos);
    cursos = NULL;
    return 0;
}

//----------------------FIM EXERCICIO 2c-------------------------*/


//----------------------EXERCICIO 3-------------------------


