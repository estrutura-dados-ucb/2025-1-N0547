#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "filmes.h"
#define MAX 50

typedef struct Filme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
} Filme;

int NUM_FILMES = 0;
int MAX_FILMES = 10;

Filme* criaLista(Filme *filme){
    filme = (Filme*) malloc(NUM_FILMES*sizeof(Filme));
    return filme;
}

void listarFilmes(Filme *filmes){
    for(int i = 0; i < NUM_FILMES;i++){
        printf("nome: %s\n", filmes[i].nome);
        printf("ano de lancamento: %d\n", filmes[i].anoLancamento);
        printf("nome do diretor: %s\n", filmes[i].diretor);
        printf("=====================================================\n");

    }
}

void adicionarFilme(Filme *filmes, Filme filme){
    if(NUM_FILMES < MAX_FILMES - 1){
        filmes[NUM_FILMES] = filme;
        NUM_FILMES += 1;
    } else {
        printf("Lista ja esta cheia!!!");
    }
}



int main(){
    Filme *filmes = criaLista(filmes);
    Filme filme1 = {"Conclave", 2024, "Edward Berger"};

    Filme filme2 = {"duna 2", 2024, "denis villenueve"};

    adicionarFilme(filmes, filme1);
    adicionarFilme(filmes, filme2);


    printf("\n\nLista de filmes:\n");
    listarFilmes(filmes);


}