#ifndef FILMES_H
#define FILMES_H

typedef struct Filme {
    char nome[50];
    int anoLancamento;
    char diretor[50];
    struct Filme *prox;
    struct Filme *ant;
} Filme;


void criaLista();
void listarFilmes();
void adicionarFilme(Filme *filmes);
Filme* buscarFilme(char* nome);
void removerFilme(char* nome);
int contarNumFilmes(Filme *filmes);

#endif
