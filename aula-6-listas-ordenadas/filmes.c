#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // floor()
#include "filmes.h"
#define MAX 50

typedef struct Filme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
} Filme;

typedef struct ListaFilmes {
    // Filme filmes[MAX]; -> Alocação estática
    Filme *filmes;
    int numFilmes;
} ListaFilmes;



void criaLista(ListaFilmes *lista){
    lista->numFilmes = 0;
    // Criando lista de filmes com alocação dinâmica
    lista->filmes = (Filme*) malloc(MAX*sizeof(Filme));
}

void listarFilmes(ListaFilmes *lista){
    for(int i = 0; i < lista->numFilmes;i++){
        printf("nome: %s\n", lista->filmes[i].nome);
        printf("ano de lancamento: %d\n", lista->filmes[i].anoLancamento);
        printf("nome do diretor: %s\n", lista->filmes[i].diretor);
        printf("=====================================================\n");

    }
}

void adicionarFilme(ListaFilmes *lista, Filme filme){
    if(lista->numFilmes < MAX - 1){
        lista->filmes[lista->numFilmes] = filme;
        lista->numFilmes += 1;
    } else {
        printf("Lista ja esta cheia!!!");
    }
}

int buscarFilme(ListaFilmes *lista, char* nome){
    for(int i = 0;i < lista->numFilmes;i++){
        if(strcmp(lista->filmes[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}


int buscaBinariaFilme(ListaFilmes *lista, char* nomeBusca){
    int esq = 0;
    int dir = lista->numFilmes - 1;
    int m = floor((esq + dir)/2);

    while(esq <= dir){
        if(strcmp(lista->filmes[m].nome, nomeBusca) == 0){
            return m;
        }
        // Se nomeBusca a esquerda de filme na pos. m
        else if(strcmp(lista->filmes[m].nome, nomeBusca) > 0){
            dir = m - 1;
            m = floor((esq + dir)/2);
            
        } 
        // Se nomeBusca a direita de filme na pos. m
        else if(strcmp(lista->filmes[m].nome, nomeBusca) < 0){
            esq = m + 1;
            m = floor((esq + dir)/2);
        }
    }
    return -1;
}


void ordernarFilmes(ListaFilmes *lista){
    int numFilmesOrdenados = 0;
    for(int i = 0;i < lista->numFilmes;i++){
        for(int j = 0;j < lista->numFilmes - numFilmesOrdenados - 1;j++){
            if(strcmp(lista->filmes[j].nome,
                    lista->filmes[j+1].nome) > 0){
                Filme aux;
                // Inverter filme da posição j com pos. j + 1
                aux = lista->filmes[j+1];
                lista->filmes[j+1] = lista->filmes[j];
                lista->filmes[j] = aux;
            }
        }
        numFilmesOrdenados++;
    }
}


int main(){
    ListaFilmes lista;

    criaLista(&lista);
    Filme filme1, filme2, filme3, filme4;
    strcpy(filme1.nome, "duna 2");
    strcpy(filme1.diretor, "denis villenueve");
    filme1.anoLancamento = 2024;

    strcpy(filme2.nome, "avatar 2");
    strcpy(filme2.diretor, "james cameron");
    filme2.anoLancamento = 2023;

    strcpy(filme3.nome, "o menino e a garca");
    strcpy(filme3.diretor, "hayao miyazaki");
    filme3.anoLancamento = 2024;

    strcpy(filme4.nome, "questao de tempo");
    strcpy(filme4.diretor, "richard curtis");
    filme4.anoLancamento = 2013;


    adicionarFilme(&lista, filme1);
    adicionarFilme(&lista, filme2);
    adicionarFilme(&lista, filme3);
    adicionarFilme(&lista, filme4);

    printf("\n\nLista desordenada:\n");
    listarFilmes(&lista);
    printf("-----------------------------------------\n");

    int i = buscarFilme(&lista, "questao de tempo");
    if(i >= 0){
        printf("Filme encontrado: %s, %s, %d", lista.filmes[i].nome, lista.filmes[i].diretor, lista.filmes[i].anoLancamento);

    }

    ordernarFilmes(&lista);

    printf("\n\nLista ordenada:\n");
    listarFilmes(&lista);

    i = buscaBinariaFilme(&lista, "questao de tempo");
    if(i >= 0){
        printf("Filme encontrado: %s, %s, %d", lista.filmes[i].nome, lista.filmes[i].diretor, lista.filmes[i].anoLancamento);

    }
}