#include <stdio.h>

/*Pesquisa binária interativa*/

int pesquisaBin(int val[], int tam, int valor){
    int inicio=0,fim=0,meio=0;
    fim = tam-1;
    while(inicio <= fim){
        meio = (inicio + fim ) / 2;
        if(val[meio]==valor){return (meio+1);}
        if(valor > val[meio]){
            inicio = meio + 1;
        }
        else {
            fim = meio -1;
        }
    }
    return 0;
}

int main(){
int valores[20]={1,3,7,8,9,10,15,17,20,25,30,33,35,37,40,42,45,52,55,60};

int valor = 0;

printf("Introduza um valor a pesquisar:\n");
scanf("%i",&valor);
int res = pesquisaBin(valores,20,valor);

if(res>0){
    printf("Existe na posição %i\n",res);

}else{
    printf("Não existe\n");

}
return 0;
}