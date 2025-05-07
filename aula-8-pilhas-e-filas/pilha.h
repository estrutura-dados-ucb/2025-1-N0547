#ifndef PILHA_H
#define PILHA_H

typedef struct Node;


void createNode(Node* node);
void showStack();
void push(Node* node); // inserir
void pop(); // remover
int stackIsEmpty();

#endif
