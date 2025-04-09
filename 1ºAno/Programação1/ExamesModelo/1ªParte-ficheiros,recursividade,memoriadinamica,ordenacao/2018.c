#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//----------------------EXERCICIO 1a)-------------------------

/*
//devolve -1 se der erro,1 se ok
int writeCanoistas(char *canoistas[][],int n){

    FILE *fp = NULL;
    fp = fopen("canoistas2018.txt","w");
    if(fp==NULL){
        printf("Ocorreu um erro ao abrir o ficheiro texto!\n");
        exit(-1);
        }
    
    for(int i=0;i<n;i++){
        
            fprintf(fp,"%s\n",canoistas[i]);

        
    }
    fclose(fp);
    return 1;

}

//----------------------FIM EXERCICIO 1a)-------------------------*/


//----------------------EXERCICIO 1b)-------------------------

/*
void ordenaCanoistas(char *canoistas[][],int n){
    int i=0,j=0;
    char temp[100];

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(canoistas[j],canoistas[j+1])>0){
                strcpy(temp,canoistas[j]);
                strcpy(canoistas[j],canoistas[j+1]);
                strcpy(canoistas[j+1],temp);
            }
        }
    }
}

//----------------------FIM EXERCICIO 1a)-------------------------*/


//----------------------EXERCICIO 2)-------------------------
typedef struct ciclista{ 
    int n_inscricao, nCC;       
    char  nome[100], email[50]; 
} CICLISTA;


//----------------------EXERCICIO 2a)-------------------------

/*
int gravaCiclistas(CICLISTA ciclistas[],int tot_insc){

    FILE *fp = NULL;
    fp = fopen("ciclistas2018.dat","wb");
    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro binário!\n");
        return -1;
    }

  
        size_t elem_escritos = fwrite(ciclistas,sizeof(CICLISTA),tot_insc,fp);

        fclose(fp);
        

        if(elem_escritos != tot_insc){
            printf("Ocorreu um erro ao escrever no ficheiro binário!\n");
            return -1;
        }

        return 0;

}

//----------------------FIM EXERCICIO 2a)-------------------------*/

//----------------------EXERCICIO 2b)-------------------------
/*
int main(){
    int tot_insc =0;
    CICLISTA *ciclistas = NULL;

    printf("Diga o número total de ciclistas:\n");
    scanf("%d",&tot_insc);

    if(tot_insc<0 || tot_insc>600){
        printf("Erro! O número de ciclistas deve ser entre 0 e 600!\n");
        exit(-1);

    }

    ciclistas = (CICLISTA*)malloc(sizeof(CICLISTA)*tot_insc);
    if(ciclistas == NULL){
        printf("Ocorreu um erro na alocação dinâmica da memória!\n");
        exit(-1);
    }

    free(ciclistas);
    ciclistas = NULL;
    return 0;

   
}
//----------------------FIM EXERCICIO 2b)-------------------------*/

//----------------------EXERCICIO 2c)-------------------------
/*
int pesquisaBinNum(CICLISTA ciclistas[],int tot_insc,int num){
    int meio=0,ini=0,fim = tot_insc -1;

    while(ini<=fim){
        meio = (fim + ini)/2;
        if(num == ciclistas[meio].n_inscricao){
            return meio;
        }
        if(num < ciclistas[meio].n_inscricao){
            fim = meio -1;
        }else{
            ini = meio +1;
        }
    }
    return -1;
}
//----------------------FIM EXERCICIO 2a)-------------------------*/

//----------------------EXERCICIO 3)--------------------------
computSeq(int n){
    if(n<=0)return 0;
    return 4*(n*n*n) + computSeq(n-1);
}