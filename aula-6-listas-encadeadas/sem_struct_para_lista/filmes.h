#ifndef FILMES_H
#define FILMES_H

typedef struct Filme Filme;

Filme* criaLista(Filme *filmes);
void listarFilmes(Filme *filmes);
void adicionarFilme(Filme *filmes, Filme filme);
int buscarFilme(Filme *filmes, char* nome);
void removerFilme(Filme *filmes, char* nome);
int contarNumFilmes(Filme *filmes);

#endif