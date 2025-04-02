#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n,soma=0;
    
    float media;

    printf("Introduza a quantidade pretendida de números: \n");
    scanf("%d",&n);

    int *val= (int*) malloc(sizeof(int)*n);
    if(val== NULL){
        printf("Erro na alocação da memória!\n");
        return 1;
    }

    for(int i=0;i<n;i++){

        printf("Introduza o %d número: \n",i+1);
        scanf("%d", &val[i]);
        soma += val[i];


    }

    media = (float)soma / n;
    printf("Números inferiores à média (%.2f): \n",media);
    for(int i=0;i<n;i++){
        if(val[i]< media){
            printf("%d\n",val[i]);
        }

    }

    free(val);

    return 0;

}