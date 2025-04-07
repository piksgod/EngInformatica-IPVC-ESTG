#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Introduza o número de números pretendidos:\n");
    scanf("%d",&n);

    int *val = (int * )malloc(sizeof(int)*n);
    if(val== NULL){
        printf("Erro ao alocar a memória!\n");
        return 1;
    }

    
    
    for(int i=0;i<n;i++){
        printf("Introduza o %d número:",i+1);
        scanf("%d",&val[i]);
       
        
    }

    printf("Elementos do vetor (invertidos):\n");
    for(int i=n-1;i>=0;i--){
        printf("%d ",val[i]);
        
    }
    printf("\n");
    free(val);
    return 0;
}