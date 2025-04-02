#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char str1[100],str2[100];

    printf("Escreva a primeira string:\n");
    fgets(str1,sizeof(str1),stdin);
    str1[strcspn(str1,"\n")]= '\0';

    printf("\n");

    printf("Escreva a segunda string:\n");
    fgets(str2,sizeof(str2),stdin);
    str2[strcspn(str2,"\n")]= '\0';

    printf("\n");

    strlen(str1)-1 == '\0';
    strlen(str2)-1 == '\0';

    
    char *str3 = (char*)malloc(strlen(str1)+strlen(str2)+1);
    if (str3 == NULL){
        printf("Ocorreu um erro ao alocar a memória!\n");
        return 1;
    }
    
    strcpy(str3,str1);
    strcat(str3,str2);

    printf("Resultado: %s\n",str3);

    free(str3);


    return 0;




}