#ifndef FICHA2_H
#define FICHA2_H

typedef struct {
    char nome[100];
    char tipoParticipante;
    float valorPago;
}Participante;

void recebeInformacao();
void listarTodosParticipantes();
void listarParticipantePorNumero(int numero);
float somaPagamentos();

#endif