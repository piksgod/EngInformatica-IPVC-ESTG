#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaMDCrecursivo(int m,int n){

    if(n = 0)return m;
    if(n>0)
    return calculaMDCrecursivo(n,m%n);

}

int main(){
    int n=-1,m=-1;
    while(n < 0 || m < 0){
        printf("Digite dois números inteiros positivos(n,m):\n");
        scanf("%d %d",&n,&m);

    }

    printf("O máximo divisor comum de %d e %d é %d\n",n,m,calculaMDCrecursivo(n,m));
}