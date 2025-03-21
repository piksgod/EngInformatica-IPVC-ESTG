#include <stdio.h>
#include <string.h>

int insertionSort(char nomes[][100],int tam){
    int i = 0, j=0;
    char aux[100];

    for(i=1;i<tam;i++){
        strcpy(aux,nomes[i]);
        j=i-1;
        while(j>=0 && strcmp(nomes[j],aux)>0){
            strcmp(nomes[j+1],nomes[i]);
            j--;
        }
        strcpy(nomes[j+1],aux);
    }
}

int main(){
    char nomes[10][100] = {"Fiat","Volvo","Tesla","Toyota","Opel","Bmw","Audi","Mercedes","Renault","Byd"};

    insertionSort(nomes,10);

    for(int i=0;i<10;i++){
        printf("%s\n",nomes[i]);
    }
    return 0;
}