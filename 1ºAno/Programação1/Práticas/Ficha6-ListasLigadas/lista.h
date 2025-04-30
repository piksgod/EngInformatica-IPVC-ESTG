#include <stdio.h> 
#include <stdlib.h> 

typedef struct Colab {
    int numero;
    char nome[50];
    char NIF[10];
    char dataNasc[11];
    float salario;
}INFO;
// 
//FUNÇOES AUXILIARES

int criarLista();

int limpaLista();

int gravaDados(char nomeFicheiro[]);

int leDados(char nomeFicheiro[]);

int existeColab(char NIF[]);

int existeColabNum(int numero);

//FUNÇOES PRINCIPAIS

int insereColab(INFO colaborador);

int listaColaboradores();

int listaColaborador(int numero);

float somaSalRecursivo();

int numeroColab();

float mediaSal();

int removerColab(char NIF[]);

int listaColabSalarioSuperior(float salario);

int aumentarSalario(float percentual);


