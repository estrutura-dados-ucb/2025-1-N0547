#ifndef FILMES_H
#define FILMES_H

typedef struct Filme Filme;
typedef struct ListaFilmes ListaFilmes;

void criaLista(ListaFilmes *filmes);
void listarFilmes(ListaFilmes *filmes);
void adicionarFilme(ListaFilmes *filmes, Filme filme);
int buscarFilme(ListaFilmes *filmes, char* nomeFilme);
void removerFilme(ListaFilmes *filmes, char* nomeFilme);
void ordernarFilmes(ListaFilmes *lista);

#endif