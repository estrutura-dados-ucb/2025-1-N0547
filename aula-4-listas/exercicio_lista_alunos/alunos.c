#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"
#include <string.h>

int ultimaPosLivre = 0;

Aluno* criaLista(int numAlunos){
    //Aluno alunos[numAlunos];
    Aluno *alunos = (Aluno*) malloc(numAlunos*sizeof(Aluno));

    return alunos;
}

void adicionarAluno(Aluno *lista, Aluno aluno){
    lista[ultimaPosLivre] = aluno;
    ultimaPosLivre++;
}

void listarAlunos(Aluno *lista){

    for(int i = 0;i < ultimaPosLivre;i++){
        printf("======================================\n");
        printf("Matricula do aluno: %d\n", lista[i].matricula);
        printf("Idade do aluno: %d\n", lista[i].idade);
        printf("Nome do aluno: %s\n", lista[i].nome);
        printf("Nota do aluno: %f\n", lista[i].nota);
    }
    printf("======================================\n");


}

int buscarAluno(Aluno *lista, int matricula){
    for(int i = 0;i < ultimaPosLivre;i++){
        if(lista[i].matricula == matricula){
            return i;
        }
    }
    return -1;
}

void removerAluno(Aluno *lista, int matricula){
    int indiceAluno = buscarAluno(lista, matricula);
    if(indiceAluno >= 0){
        int indiceAtual = indiceAluno;
        while(indiceAtual + 1 < ultimaPosLivre){
            lista[indiceAtual] = lista[indiceAtual + 1];
            lista[indiceAtual + 1].idade = -1;
            lista[indiceAtual + 1].nota = -1;
            lista[indiceAtual + 1].matricula = -1;
            strcpy(lista[indiceAtual + 1].nome, "");
            indiceAtual++;
        }
    }
    ultimaPosLivre--;
}


int main(){

    int numAlunos = 5;
    Aluno *alunos = criaLista(numAlunos);
    Aluno aluno1 = {1, 22, "romario", 10};
    Aluno aluno2 = {2, 34, "pedro", 9};
    Aluno aluno3 = {3, 18, "zico", 10};
    Aluno aluno4 = {4, 52, "messi", 7};
    Aluno aluno5 = {5, 22, "gerson", 10};


    adicionarAluno(alunos, aluno1);
    adicionarAluno(alunos, aluno2);
    adicionarAluno(alunos, aluno3);
    adicionarAluno(alunos, aluno4);
    adicionarAluno(alunos, aluno5);

    listarAlunos(alunos);

    removerAluno(alunos, 3);
    printf("\n\nApos remover aluno com matricula '3':\n");
    listarAlunos(alunos);

    return 0;
}