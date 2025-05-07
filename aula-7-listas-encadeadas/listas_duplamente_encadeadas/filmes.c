#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"


Filme *inicio;

void criaLista(Filme *filme){
    inicio = filme;
    inicio->prox = NULL;
    inicio->ant = NULL;
}


void adicionarFilme(Filme *filme){
    if(inicio == NULL){
        criaLista(filme);
    } else {
        filme->prox = inicio;
        inicio->ant = filme;
        inicio = filme;
    }
}

void listarFilmes(){
    printf("Listando filmes...\n");
    Filme *filmeAtual = inicio;

    while(filmeAtual != NULL){
        printf("nome do filme: %s\n", filmeAtual->nome);
        printf("nome do filme: %d\n", filmeAtual->anoLancamento);
        printf("nome do filme: %s\n", filmeAtual->diretor);
        printf("===================================\n");
        filmeAtual = filmeAtual->prox;
    }
}

Filme* buscarFilme(char* nomeBusca){
    Filme *filmeAtual = inicio;

    while(filmeAtual != NULL){
        if(strcmp(filmeAtual->nome, nomeBusca) == 0){
            printf("Filme encontrado!\n");
            return filmeAtual;
        }
        filmeAtual = filmeAtual->prox;
    }
    return NULL;

}

void removerFilme(char *nome){
    printf("Tentando remover %s\n", nome);
    Filme* filmeAtual = inicio;
    Filme* proxFilme = filmeAtual->prox;

    // se for o primeiro filme
    if(strcmp(filmeAtual->nome, nome) == 0){
        printf("Removendo %s...\n", nome);
        free(filmeAtual);
        inicio = proxFilme;
        proxFilme->ant = NULL;
    }

    else {
        while(proxFilme != NULL){
            // achei o filme
            if(strcmp(proxFilme->nome, nome) == 0){
                printf("Removendo %s...\n", nome);
                filmeAtual->prox = proxFilme->prox;
                // Se o filme a ser removido não é o último
                // Se o filme estiver no meio da lista
                if(proxFilme->prox){
                    proxFilme->prox->ant = proxFilme->ant;
                }
                free(proxFilme);
                break;
            }

            filmeAtual = filmeAtual->prox;
            proxFilme = proxFilme->prox;
        }
    }
}



int main(){
    Filme *filme1, *filme2;
    filme1 = (Filme*) malloc(sizeof(Filme));
    filme2 = (Filme*) malloc(sizeof(Filme));

    strcpy(filme1->nome, "duna 2");
    strcpy(filme1->diretor, "denis villenueve");
    filme1->anoLancamento = 2024;

    strcpy(filme2->nome, "avatar 2");
    strcpy(filme2->diretor, "james cameron");
    filme2->anoLancamento = 2023;

    adicionarFilme(filme1);
    adicionarFilme(filme2);

    listarFilmes();

    Filme *retornoBusca = buscarFilme("duna 2");
    if(retornoBusca) {
        printf("Filme encontrado: %s\n", retornoBusca->nome);
    } else {
        printf("Filme nao encontrado!\n");
    }

    removerFilme("duna 2");

    listarFilmes();

    return 0;
}