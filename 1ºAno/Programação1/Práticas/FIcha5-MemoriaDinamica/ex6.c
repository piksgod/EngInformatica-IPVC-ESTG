#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ordenaArray(int *val, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i,temp;
        for (int j = i + 1; j < n ;j++) {
            if (val[j]< val[min]) {
                min= j;
            }
        }
        if (min!= i) {
            temp = val[i];
            val[i] = val[min];
            val[min] = temp;
        }
    }
}
int main(){
    int n;

    printf("Introduza o número de números a introduzir: ");
    scanf("%d",&n);

    int *val = (int*)malloc(sizeof(int)*n);
    if(val == NULL){
        printf("Erro na alocação da memória!\n");
        return 1;
    }
    for(int i = 0;i<n;i++){

        printf("Introduza o %d número: \n",i+1);
        scanf("%d",&val[i]);

    }

    ordenaArray(val,n);
    printf("Array ordenado:\n");

    for(int i = 0; i<n; i++){
        printf("%d ",val[i]);
    }

    printf("\n");

    free(val);
    return 0;

}