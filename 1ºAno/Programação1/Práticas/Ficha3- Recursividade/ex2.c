#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calculaTamStringRecursiva(char *str){
        
        if(*str=='\0')return 0;
        return 1 + calculaTamStringRecursiva(str +1 );
    }
int calculaTamStringIterativa(char *str){
    int contador = 0;
    for(int i=0;str[i]!='\0';i++){
        contador++;
    }
    return contador;
}
int main(){
    char texto[100];

    strcpy(texto,"Ola sou o Diogo!");

    printf("Tamanho da string usando a função recursiva: %d\n",calculaTamStringRecursiva(texto));
    printf("Tamanho da string usando a função iterativa:%d\n",calculaTamStringIterativa(texto));

}