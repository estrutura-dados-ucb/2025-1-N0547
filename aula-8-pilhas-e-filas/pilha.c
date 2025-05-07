#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node *prox;
} Node;

Node *top = NULL; // Ponteiro para topo pilha

void createNode(Node* node){
    top = node;
    node->prox = NULL;
}

void showStack(){
    Node* currNode = top;
    printf("===========================\n");
    while(currNode){
        printf("%d\n", currNode->item);
        currNode = currNode->prox;
    }
    printf("===========================\n");
}

void push(Node* node){ // inserir
    if(top == NULL){
        createNode(node);
    } else {
        node->prox = top;
        top = node;
    }
}


void pop() { // remover
    if(top){
        Node* newTop = top->prox;
        free(top);
        top = newTop;
    }
}

int stackIsEmpty(){
    if(top){
        return 1;
    }
    return 0;
}




int main(){
    Node* node1, *node2, *node3;
    node1 = (Node*) malloc(sizeof(Node));
    node2 = (Node*) malloc(sizeof(Node));
    node3 = (Node*) malloc(sizeof(Node));

    node1->item = 10;
    node2->item = 20;
    node3->item = 30;

    push(node1);
    push(node2);
    push(node3);

    showStack();

    pop();

    showStack();

    return 0;
}