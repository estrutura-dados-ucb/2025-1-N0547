#include <stdio.h>

int main(){
    FILE* arquivo = fopen("arquivo.txt", "r");
    char linha[1000];
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while(fgets(linha, 100, arquivo) != NULL){
        fputs(linha, stdout);
        fputs("======================\n", stdout);
    }
    // printf("%s", linha);



    fclose(arquivo);


    return 0;
}