#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ficha4.h"
/*EXERCICIO Pretende-se implementar um programa para fazer a gestão da informação sobre os
colaboradores de uma empresa. Sobre cada colaborador é necessário guardar o número de
colaborador, o nome, o NIF e salário. Na empresa não existem mais que 120 colaboradores.
O programa deverá permitir:*/

Employee employees[MAX_EMPLOYEES];
int nrEmployees = 0;

/*EXERCICIO 1 - Receber informação sobre um funcionário - O programa deverá pedir ao utilizador os
dados de um funcionário e acrescentar aos dados já armazenados. O número deve ser
atribuído sequencialmente pelo próprio programa.
*/

int saveEmployee(Employee e){
    if(nrEmployees >= MAX_EMPLOYEES)
    {
        return -1;
    }
    e.number = nrEmployees + 1;
    employees[nrEmployees] = e;
    nrEmployees++;
    return e.number;
}

/*EXERCICIO 2- Listar a informação – desenvolver a função listaInfo() que escreve para o ecrã toda a
informação existente.*/

int listaInfo(){

    char header1[] = "Number";
    char header2[] = "Name";
    char header3[] = "NIF";
    char header4[] = "Salary";
    printf("%-6s | %-50s | %-9s | %-11s\n", header1,header2,header3,header4);
    for(int i = 0; i< nrEmployees; i++){
        printf("%-6d | %-50.50s | %-9lu | %-9.2f\n", employees[i].number, employees[i].name,employees[i].nif,employees[i].salary);
    }
    return nrEmployees;
    //return -1; otherwise
}

/*EXERCICIO 3 - Ordenar por nome – Desenvolver a função ordenaNome(), que, recorrendo ao algoritmo
bubbleSort ordena alfabeticamente os colaboradores pelo nome. */

void ordenaNome() {
    for (int i = 0; i < nrEmployees - 1; i++) {
        for (int j = 0; j < nrEmployees - i - 1; j++) {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

/*EXERCICIO 4- Ordenar por NIF - Desenvolver a função ordenaNIF(), que, recorrendo ao algoritmo
selectionSort, deverá ordenar a informação sobre o funcionários por ordem crescente do
NIF*/
void ordenaNIF() {
    for (int i = 0; i < nrEmployees - 1; i++) {
        int min = i;
        for (int j = i + 1; j < nrEmployees; j++) {
            if (employees[j].nif < employees[min].nif) {
                min= j;
            }
        }
        if (min!= i) {
            Employee temp = employees[i];
            employees[i] = employees[min];
            employees[min] = temp;
        }
    }
}

/*EXERCICIO 5- Criar o ficheiro de texto “colaboradores.txt” com a informação sobre todos os
funcionários. A informação deve estar ordenada por nome*/

int salvarColaboradoresTXT() {
    FILE *file = fopen(FILENAME, "rb"); // Abre o ficheiro binário para leitura
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return;
    }

    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    while (fread(&employees[count], sizeof(Employee), 1, file) == 1 && count < MAX_EMPLOYEES) {
        count++;
    }
    fclose(file);

    ordenaNome(employees, nrEmployees); // Ordena os funcionários por nome

    FILE *txtFile = fopen(TXT_FILENAME, "w"); // Abre o ficheiro de texto para escrita
    if (txtFile == NULL) {
        perror("Erro ao criar o ficheiro de texto");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(txtFile, "Número: %d\nNome: %s\nNIF: %lu\nSalário: %.2f\n", employees[i].number, employees[i].name, employees[i].nif, employees[i].salary);
        fprintf(txtFile, "----------------------------------\n");
    }
    fclose(txtFile);
    return nrEmployees;
}
