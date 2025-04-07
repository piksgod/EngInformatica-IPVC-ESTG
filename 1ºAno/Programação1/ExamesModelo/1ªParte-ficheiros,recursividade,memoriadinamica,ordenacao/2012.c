#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 2500
typedef struct atletas{
int cod_atleta, cod_pais;
char nome_atleta [100], modalidade[100];
} ATLETA;
//----------------------EXERCICIO 1-------------------------

/*
int main(){

    FILE *fp = NULL;
    char nome[100];
    char raca[100];
    int idade;

    fp = fopen("caninos.txt","w");

    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        exit(-1);
    }

    while(1){
       
    printf("Diga o nome do cão(END para terminar):\n");
    fgets(nome,100,stdin);
    nome[strcspn(nome,"\n")]= '\0';
    fprintf(fp,"Nome:%s\n",nome);

    if(strcmp(nome,"END")==0){
        break;
    }
  
    printf("Diga a raça do cão:\n");
    fgets(raca,100,stdin);
    raca[strcspn(raca,"\n")]='\0';
    fprintf(fp,"Raça: %s\n",raca);

    printf("Diga a idade do cão:\n");
    scanf("%d",&idade);
    fprintf(fp,"Idade:%d\n",idade);

    while(getchar()!='\n');

    }

    
fclose(fp);
return 0;
}



FIM EXERCICIO 1*/




//----------------------EXERCICIO 2A)-------------------------

/*


void escreveDados(ATLETA atletas){

    FILE *fp = NULL;
    fp = fopen("atletas.dat","wb");
    if(fp == NULL){
        printf("Erro ao abrir ficheiro!\n");
        exit(-1);
    }

    fwrite(&atletas,sizeof(ATLETA),1,fp);

    printf("Dados escritos!\n");

    fclose(fp);
}

int main() {
ATLETA atletas [TAM];
atletas->cod_atleta==12;
atletas->cod_pais==123;
atletas->modalidade=="Voleibol";
atletas->nome_atleta=="Diogo";
escreveDados(atletas[TAM]);
}

----------------------FIM EXERCICIO 2A)--------------------------- */


//----------------------EXERCICIO 2B)-------------------------
/*


void ordenaAtletas(ATLETA *atletas,int nrAtletas){
   ATLETA temp;     
    for(int i=0;i<nrAtletas-1;i++){
        for(int j=0;j<nrAtletas -i-1;j++){
            if(strcmp(atletas[j].nome_atleta,atletas[j+1].nome_atleta)>0){
                temp = atletas[j];
                atletas[j]=atletas[j+1];
                atletas[j+1] = temp;
            }
        }
    }

}

---------------------FIM EXERCICIO 2B)--------------------------- */


//----------------------EXERCICIO 2C)-------------------------
/*
int main(){
int n;
ATLETA *atletas = NULL;



printf("Diga o número de atletas:\n");
scanf("%d",&n);

if(n<0 ||n>TAM){
    printf("Número inválido de atletas!Deve ser entre 1 e %d\n",TAM);
}
atletas = (ATLETA*)malloc(n*sizeof(ATLETA));

if(atletas = NULL){
    printf("Erro na alocação dinamica da memória!\n");
    return -1;
}
free(atletas);
atletas = NULL;
return 0;
}
---------------------FIM EXERCICIO 2C)--------------------------- */


//----------------------EXERCICIO 2D)-------------------------
/*
A diferença entre a função malloc e calloc é que a calloc limpa automaticamente o espaço de memória reservado
mas sendo na mesma necessário libertá-lo. A diferença da calloc para a realloc é que a realloc é usada quando ja temos X espaço reservado
e pretendemos mais espaço, primeiro é usada a calloc e depois a realloc.

--------------------FIM EXERCICIO 2D)--------------------------- */


//----------------------EXERCICIO 3)-------------------------
/*
int calcSomat(int n){
    if(n <=0){
        return 0;
    }
    return (2*n+3)+calcSomat(n-1);
}
---------------------FIM EXERCICIO 3)--------------------------- */ 