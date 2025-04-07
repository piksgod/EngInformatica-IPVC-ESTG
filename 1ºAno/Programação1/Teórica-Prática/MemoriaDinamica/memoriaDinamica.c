#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char *apt = NULL;
    apt = (char*)malloc(100);
    if(apt == NULL){
        printf("Out of memory!\n");
        return -1;
    }

    strcpy(apt,"Viana do Castelo\n");
    printf("%s",apt);
    free(apt);
    return 0;
}