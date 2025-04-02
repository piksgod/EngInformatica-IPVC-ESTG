#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaFormula(int n){
    
    if(n ==0) return 3;
    return 2 * (n-1)^2 +3;
}


int main() {
    int num;
    printf("Digite um número inteiro:\n");
    scanf("%d",&num);

    printf("Resultado recursivo:%d\n",calculaFormula(num));
}
