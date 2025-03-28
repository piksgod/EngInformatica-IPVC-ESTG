#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaQuadratico(int n){
    if(n == 1) return 1;
    if(n>1) return calculaQuadratico(n-1)+ 2*n-1;
}

int main(){
    int n=0;
    
    printf("Introduza um número inteiro positivo:\n");
    scanf("%d",&n);
    
    printf("O respetivo número quadrático de %d é %d\n",n,calculaQuadratico(n));
}