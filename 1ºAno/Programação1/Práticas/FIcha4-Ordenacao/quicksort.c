#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void quicksort(int v[],int left,int right){
    int i=left;
    int j=right;
    int pivot = v[(left+right)/2];
    int temp;

    while(i<=j){
        while(v[i]<pivot)i++;
        while(v[j]>pivot)j--;

        if(i<=j){
            //troca os elementos
            temp = v[i];
            v[i]= v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    if(left < j) quicksort(v,left,j);
    if(i<right) quicksort(v,i,right);
}

int pesquisaBin(int v[],int tam,int x){
    int meio=0, inicio = 0,fim = tam-1;
    int resultado = -1;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        
        if (v[meio]>x){
            resultado = v[meio];
            fim = meio - 1;

        }

        else{
            inicio = meio - 1;

        }
    }
        return resultado;
}

int main(){
    int v[]={5,3,9,1,6};
    int size = sizeof(v)/ sizeof(v[0]);
}