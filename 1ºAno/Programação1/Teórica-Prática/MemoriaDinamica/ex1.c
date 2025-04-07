#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Implementar um programa que receba do utilizador um nº indeterminado de valores inteiros e apresente para o ecra os numeros que sao superios à media*/
int main(){
    int *valores = NULL;
    int i,n=0,soma = 0;
    float media = 0;

    printf("Introduza a quantidade de valores:\n");
    scanf("%d",&n);

    //valores = (int*)malloc(n* sizeof(int));
    valores = (int *)calloc(n,sizeof(int));
    if(valores==NULL){
        printf("Out of memory!\n");return -1;
    }

    for(i=0;i<n;i++){
        printf("Introduza o valor:\n");
        scanf("%i",&valores[i]);
        soma += valores[i];
    }

    media =(float)soma /n;
    printf("-----------\nMédia: %.2f",media);

    for(i=0;i<n;i++){
        if(valores[i]>media){
            printf("\n----------Valores superiores a media-----------\n");
            printf("%i\n",valores[i]);
        }
    }

    free(valores);
    return 0;
}