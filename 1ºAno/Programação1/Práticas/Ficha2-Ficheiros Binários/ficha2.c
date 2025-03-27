#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ficha2.h"

void recebeInformacao(){
    FILE *fp = NULL;
    int num_participantes = 0;
    Participante participante;

    fp = fopen("TranfDigital2024.dat","rb");
    if((fp!=NULL)){
        fseek(fp,0,SEEK_END);
        num_participantes = ftell(fp) / sizeof(Participante);
        fclose(fp);
    }

    if(num_participantes>=150){
        printf("Número limite de participantes atingido!\n");
        return;
    }

    fp = fopen("TranfDigital2024.dat","ab");
    if(fp == NULL){
        printf("Ocorreu um erro ao abrir o ficheiro!\n");
        exit(-1);
    }

    printf("-----NOVO PARTICIPANTE (Nº%d)-----\nDiga o seu nome:\n",num_participantes+1);
    fgets(participante.nome,100,stdin);
    participante.nome[strcspn(participante.nome,"\n")]= '\0';

    printf("Valor pago na inscrição:\n");
    scanf("%f",&participante.valorPago);
    getchar();

    printf("Tipo de participante(E-EMPRESA, A-ALUNO, C-CONVIDADO, O-OUTRO):\n");
    scanf("%c",&participante.tipoParticipante);
    
    fwrite(&participante, sizeof(Participante),1,fp);
    fclose(fp);

    printf("Participante registado com sucesso!\n");

}


void listarTodosParticipantes(){
    FILE *fp = NULL;
    fp = fopen("TranfDigital2024.dat","rb");
    if(fp == NULL){
        printf("Não existem inscrições!\n");
        return;

    }
    Participante p;
    int contador = 1;
    while(fread(&p,sizeof(Participante),1,fp)==1){
        printf("\nParticipante Nº%d\n",contador++);
        printf("Nome:%s\n",p.nome);
        printf("Valor pago: %.2f",p.valorPago);

        char *tipo;
        switch(p.tipoParticipante){
            case 'E': tipo = "Empresa";break;
            case 'A': tipo = "Aluno";break;
            case 'C': tipo = "Convidado";break;
            case 'O': tipo = "Outro";break;
            
            default: tipo = "Desconhecido";


        }
        printf("Tipo: %s (%c)\n",tipo,p.tipoParticipante);
    }


    fclose(fp);

    
}

void listarParticipantePorNumero(int numero){

    FILE *fp = fopen("TranfDigital2024.dat","rb");
    if(fp==NULL){
        printf("Ficheiro não existe ou está vazio!\n");
        return;

    }

    if( numero < 1 || numero >150){
        printf("Número tem de ser entre 1 e 150!\n");
        fclose(fp);
        return;
    }
    long posicao = (numero -1) * sizeof(Participante);
    fseek(fp,posicao,SEEK_SET);

    Participante p;

    if (fread(&p, sizeof(Participante), 1, fp) != 1) {
        printf("Erro: Participante Nº %d não encontrado.\n", numero);
    } else {
        printf("\n=== PARTICIPANTE Nº %d ===\n", numero);
        printf("Nome: %s\n", p.nome);
        printf("Valor pago: %.2f €\n", p.valorPago);
        
        char *tipo;
        switch (p.tipoParticipante) {
            case 'E': tipo = "Empresa"; break;
            case 'A': tipo = "Aluno"; break;
            case 'C': tipo = "Convidado"; break;
            case 'O': tipo = "Outro"; break;
            default: tipo = "Desconhecido";
        }
        printf("Tipo: %s (%c)\n", tipo, p.tipoParticipante);
    }

    fclose(fp);
}

float somaPagamentos(){
    FILE *fp = fopen("TranfDigital2024.dat","rb");
    if(fp==NULL){
        printf("Erro: Ficheiro não existe ou está vazio.\n");
        return 0.0;

    }

    Participante p;
    float total = 0.0;

    while(fread(&p,sizeof(Participante),1,fp)==1){
        total += p.valorPago;
    }
    fclose(fp);
    return total;   
}

int main(){
    int opcao, numero;

    do{
        printf("----MENU----\n");
        printf("1. Adicionar participantes\n");
        printf("2. Listar TODOS os participantes\n");
        printf("3. Listar Participante por número\n");
        printf("4. Somar total dos pagamentos.\n");
        printf("0. Sair!\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1: recebeInformacao(); break;
        case 2: listarTodosParticipantes(); break;
        case 3: printf("Número de inscrição: ");
                scanf("%d", &numero);
                listarParticipantePorNumero(numero);
                break;
        
        case 4: float total = somaPagamentos();
                printf("===TOTAL DE PAGAMENTOS===\n\n");
                printf("Valor total: %.2f\n\n\n",total);
                break;

        case 0: printf("A sair...\n"); break;    

        default: printf("Opção inválida!!\n");

        }

    }while(opcao !=0);

    return 0;
}
