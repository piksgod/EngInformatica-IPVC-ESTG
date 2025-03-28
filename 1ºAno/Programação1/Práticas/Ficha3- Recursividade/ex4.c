#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int calcularTriangular(int n){
    if(n == 1)return 1;
    if(n >1)return calcularTriangular(n-1) + n;
    
}

int main(){
    int n=0;
    
    printf("Introduza um número inteiro positivo:\n");
    scanf("%d",&n);
    
    printf("O respetivo número triangular de %d é %d\n",n,calcularTriangular(n));
}