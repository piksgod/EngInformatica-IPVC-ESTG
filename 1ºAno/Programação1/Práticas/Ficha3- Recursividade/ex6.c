#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int seqRecursiva(int n){
    if(n <= 10){
        return 10;
    }
    if(n>10){
        return 2 * n - seqRecursiva(n-1) + 4;
    }

}

int main(){
    int num;
    printf("Digite um número inteiro:\n");
    scanf("%d",&num);

    printf("Resultado: %d\n",seqRecursiva(num));
}