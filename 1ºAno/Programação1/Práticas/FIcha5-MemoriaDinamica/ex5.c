#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

    if(argc != 2){
        printf("Uso: %s nome_ficheiro\n",argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Erro ao abrir o ficheiro %s\n",argv[1]);
        return 1;
    }

    int n;
    if(fscanf(fp,"%d",&n) != 1 || n<0){
        printf("Formato do ficheiro inválido!\n");
        fclose(fp);
        return 1;
    }

    int *valores = (int*)malloc(n* sizeof(int));
    if(valores == NULL){
        printf("Erro ao alocar a memória!\n");
        fclose(fp);
        return 1;
    }


    for(int i=0;i<n;i++){
        if(fscanf(fp,"%d",&valores[i])!= 1){
            printf("Erro ao ler o valor %d do ficheiro\n", i+1);
            free(valores);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    int ultimo_valor = valores[n-1];

    printf("Valores menores ou iguais a %d:\n", ultimo_valor);

    for(int i=0;i<n-1;i++){
        if(valores[i]<=ultimo_valor){
            printf("%d\n",valores[i]);

        }
    }

    free(valores);
    return 0;


}