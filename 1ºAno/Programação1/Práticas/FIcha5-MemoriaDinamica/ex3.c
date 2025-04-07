#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
    int n,soma=0,contador=0;
    int *val = NULL;

    printf("Introduza os valores (0 para terminar a introdução):\n");   

    while(1){

    scanf("%d",&n);
    if(n==0){
        break;
    }

    int *temp = realloc(val,(contador + 1)* sizeof(int));

    if(temp == NULL){
        printf("Erro ao alocar memória!\n"); 
        free(val);
        return 1;
    }

    val = temp;
    val[contador]= n;
    soma += n;
    contador++;



}

if(contador == 0){
    printf("Nenhum valor foi introduzido!\n");
}
else{ printf("Soma dos valores: %d \n",soma);
}

free(val);
return 0;
}