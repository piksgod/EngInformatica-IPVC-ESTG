#include <stdio.h> 
#include <stdlib.h> 
#include "lista.h" 


int menu(){ 
    int op=0; 
    printf("\nGestao Colaboradores --> Opcoes:"); 
    printf("\n\t1 --> Inserir Colaborador"); 
    printf("\n\t2 --> lista Colaboradores"); 
    printf("\n\t3 --> dados de um colaborador"); 
    printf("\n\t4 --> Soma Salarios"); 
    printf("\n\t5 --> total de colaboradores"); 
    printf("\n\t6 --> Media Salarios"); 
    printf("\n\t7 --> Remover Colaborador"); 
    printf("\n\t8 --> Colaboradores com salario superior a"); 
    printf("\n\t9 --> Aumentar o salario de um Colaborador "); 
    printf("\n\t0 --> Sair\n"); 
    //fflush(stdin); 
    scanf("%i",&op); 
    getchar();
    return op; 
} 
int main(){ 
int op=0, numero=0; 
//... 
do{ 
 op=menu() ; 
 switch (op) { 
  case 1 : 
   //.... 
   break; 
  case 2 : 
   //listar(...); 
   break; 
  case 3 :  
   printf("\nIntroduza o numero do colaborador:"); 
   scanf("%d", &numero); 
   // listaColaborador(...); 
   break; 
  case 4 : 
   // printf(“Soma salarios=%.2f\n”, somaSal(...)); 
   break; 
case 5 : 
   // printf(“Total colaboradores=%i\n”,somacolab(...)); 
   break; 
case 6 : 
   // ... 
   break; 
case 7 : 
char NIF[10];
   printf("\nIntroduza o NIF do colaborador:"); 
   scanf("%d", &numero); 
   //removerColab(...); 
         case 0 : 
                printf("A sair ...\n"); 
                break; 
        default: printf ("Opcao errada\n");  
 } 
 }while (op != 0); 
      // limpaLista(...); 
 return 0; 
} 