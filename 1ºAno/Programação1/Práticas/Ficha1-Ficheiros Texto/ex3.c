#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int multiplos[100],j=0;

    FILE *fp = NULL;

    fp = fopen("numMul7.txt","w");

    if(fp == NULL){
        printf("Erro ao abrir o ficheiro!\n");
        exit(-1);

    }


    for(int i = 300;i<=600;i++){
        int res = 0;
        if(i%7 == 0){
            j++;
            fprintf(fp,"Número[%d]: %d\n",j,i);
        }
        
    }

    fclose(fp);
    return 0;
    
}