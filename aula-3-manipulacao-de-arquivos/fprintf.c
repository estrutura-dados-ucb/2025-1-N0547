#include <stdio.h>

int main(){
    FILE* arquivo = fopen("brasileirao.txt", "w");


    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char time[100];
    int jogos, pontos, saldo;
    fprintf(arquivo, "Time - Num. de jogos - Pontos - Saldo de gols\n");
    for(int i = 0; i < 3;i++){
        printf("time: ");
        scanf("%s", time);
        printf("Num. de jogos: ");
        scanf("%d", &jogos);
        printf("Pontos: ");
        scanf("%d", &pontos);
        printf("Saldo: ");
        scanf("%d" ,&saldo);    
        fprintf(arquivo, "%s - %d - %d - %d\n", time, jogos, pontos, saldo);
    }


    fclose(arquivo);


    return 0;
}