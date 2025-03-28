#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaArray(int arr[],int tamanho){

    if(tamanho <=0){
        return 0;
    }

    return arr[tamanho-1] + calculaArray(arr,tamanho-1);

}

int main(){

    int n,num;
    int arr[100];

    printf("Quantos numeros pretende inserir?\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Digite o %d número:\n",i+1);
        scanf("%d", &num);
        arr[i] = num;
    }

    printf("Somatório do array: %d\n",calculaArray(arr,n));

}
