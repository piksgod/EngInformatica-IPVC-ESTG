#include <stdio.h>
#include <string.h>

int pesquisaBinStrings(char nomes[][100], int tam,char nome[]){
    int inicio=0,meio = 0, fim = tam-1;
    
    while(inicio <= fim){
        meio = (inicio + fim ) / 2;
        int res = strcmp(nome,nomes[meio]);
        if(res == 0){return(meio+1);}
        if(res >0){
            inicio = meio +1;

        } else {
            fim = meio -1;
        }


}
return -1;
}

int main(){
    char cidades[10][100] = {"Aveiro","Beja","Coimbra","Guarda","Leiria","Lisboa","Moncao","Melgaco","Porto","Viana"};

    char nome[100];
    int res = 0;

    printf("Introduza o nome da cidade:\n");

    gets(nome);
    res = pesquisaBinStrings(cidades,10,nome);
    if(res>0){
        printf("Existe na posicao %i\n",res);

    }
    else {
        printf("Não existe\n");
    }
    return 0;

}