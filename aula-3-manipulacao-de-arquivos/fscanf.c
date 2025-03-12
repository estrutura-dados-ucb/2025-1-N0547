#include <stdio.h>

int main(){
    FILE* arquivo = fopen("brasileirao.txt", "r");


    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char time[100];
    char cabecalho[100];
    int jogos, pontos, saldo;
    fgets( cabecalho, 100, arquivo);
    while(fscanf(arquivo, "%s - %d - %d - %d\n", time, &jogos, &pontos, &saldo) != EOF){
        printf("Time: %s\n", time);
        printf("Jogos: %d\n", jogos);
        printf("Pontos: %d\n", pontos);
    }


    fclose(arquivo);


    return 0;
}