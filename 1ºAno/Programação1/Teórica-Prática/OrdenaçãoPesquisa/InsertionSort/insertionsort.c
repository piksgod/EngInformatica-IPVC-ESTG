#include <stdio.h>

/*Função insertion Sort com exemplo*/


int insertionSort(int val[],int tam){
    int i = 0, j=0,aux = 0;

    for(i=1;i<tam-1;i++){
        aux= val[i];
        j=i-1;
        while(j>=0 && val[j]>aux){
            val[j+1]=val[j];
            j--;
        }
        val[j+1] = aux;
    }
}

int main(){

    int valores[10]={30,10,2,7,17,1,50,5,3,4};
    insertionSort(valores,10);

    for(int i=0; i<10;i++){
        printf("%i\n",valores[i]);
    }
    return 0;
    
}

