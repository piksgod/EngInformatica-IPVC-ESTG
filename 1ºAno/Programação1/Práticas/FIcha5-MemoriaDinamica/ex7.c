#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int num;
    char *nome;
    float preco;

}Artigo;

int main(){
    Artigo a;
    int contador=0;

    printf("Diga o número do artigo: ");
    scanf("%d",&a.num);
    while(1){
        if(a.nome=='\0')
        break;

        contador++;
    }

        a.nome = (char*)malloc(contador* sizeof(char));
        if(a.nome==NULL){
            printf("Ocorreu um erro ao alocar a memória!");
            return 1;
        }

        


}