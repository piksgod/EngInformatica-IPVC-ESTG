#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
/*
Recorrendo ao uso de operações sobre stacks implemente um validador de expressões matemáticas. O validador deve verificar se o número e a ordem dos
parentesis curvos na expressão esta correta.

Exemplo : ((x+y))
*/
#define TAM 50

// Function prototypes
int push(char stack[], int *top, char c);
char pop(char stack[], int *top);
int isEmpty(int top);

int main() {
    char expressao[100];
    char stack[TAM];
    int top = 0;

    printf("Introduza a expressão matemática:\n");
    scanf("%s", expressao);

    for(int i = 0; i < strlen(expressao); i++) {
        if(expressao[i] == '(') {
            push(stack, &top, expressao[i]);
        } 
        else if(expressao[i] == ')') {  
            if(isEmpty(top)) {
                printf("Expressão matemática errada! Falta abrir parentesis!\n");
                return 0;
            }
            else {
                pop(stack, &top);  
            }
        }
    }

    if(isEmpty(top)) {
        printf("Expressão correta!\n");
    }
    else {
        printf("Expressão errada! Fechar parentesis em falta!\n");
    }
    
    return 0;
}

int push(char stack[], int *top, char c) {
    if(*top >= TAM) {
        printf("Stack overflow\n");
        return -1;
    }
    stack[*top] = c;
    (*top)++;
    return 0;
}

char pop(char stack[], int *top) {
    char aux = '\0';

    if((*top) <= 0) {
        printf("Stack underflow\n");  // Changed from "overflow" to "underflow"
    }
    else {
        (*top)--;
        aux = stack[*top];
    }
    return aux;
}

int isEmpty(int top) {
    return top <= 0;  // Simplified the return
}