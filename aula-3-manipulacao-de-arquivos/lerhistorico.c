#include <stdio.h>

int main(){
    FILE *f = fopen("historico.txt", "r+");

    if(f == NULL){
        printf("erro\n");
    }
    //fprintf(f, "joao\n03/06/2025\n4discos\n14\n");
    //fprintf(f, "---------------------------------\n");
    char historico[100], nome[100], data[100], modo[100], mov[100];
    fscanf(f, "%s", nome);
    printf("nome: %s\n", nome);
    fscanf(f, "%s", data);
    printf("data: %s\n", data);
    //fscanf(f, "%s %s %s %s", nome, data, modo, mov);
    
    //printf("nome: %s\ndata: %s\nmov.: %s\n", nome, data, mov);
    fclose(f);
    return 0;

}
