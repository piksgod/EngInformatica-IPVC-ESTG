#include <stdio.h>
#define MAX_SIZE 100

int bubbleSort(int val[], int qtd) {
   int i=0, x=0, aux=0, contador = 0;
   for(x=0; x<qtd-1; x++) {
      for (i=0; i<qtd-i-1; i++) {
         if( val[i]>val[i+1]) {
            aux=val[i];
            val[i]=val[i+1];
            val[i+1]=aux;
            contador++;
         }
       }
    }
      return contador;
   }
int main() {
  int n,i;
  int arr[MAX_SIZE];

  printf("Digite o tamanho do vetor(max %d): ", MAX_SIZE);
  scanf("%d", &n);
  if(n > MAX_SIZE) n = MAX_SIZE;

  printf("Digite os elementos do vetor:");
  for(i=0; i<n;i++){
   scanf("%d", &arr[i]);

  }

  printf("Trocas feitas: %d\n", bubbleSort(arr,n));

  printf("Vetor ordenado: ");
  for(i = 0; i<n;i++){
   printf("%d " , arr[i]);
  }
}