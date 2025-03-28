#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaPotenciaRec(int x, int y);

int calculaPotenciaRec(int x,int y){
    
    if(y == 0) return 1;

    return x *calculaPotenciaRec(x,y-1);


}

int calcularPotenciaInterativa(int x,int y){

    int res=1;

    for(int i=0;i<y;i++){
        res *= x;
    }

    return res;


}

int main(){

    int x,y;
    printf("---------------\n");
    printf("Introduza uma base X:\n");
    scanf("%d",&x);
    printf("Introduza um expoente Y:\n");
    scanf("%d",&y);

    printf("---------------\nResultado recursivo: %d\n",calculaPotenciaRec(x,y));
    printf("---------------\nResultado Iterativo: %d\n",calcularPotenciaInterativa(x,y));



}