#include <stdio.h>

int main(){
    FILE* arquivo = fopen("arquivo.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    for(int i = 1;i < 200;i++){
        if(i%2 == 1){
            char num[20];
            // inteiro para string
            itoa(i, num, 10);
            fputs(num, arquivo);
            fputs(" ", arquivo);
        }
    }

    fclose(arquivo);


    return 0;
}