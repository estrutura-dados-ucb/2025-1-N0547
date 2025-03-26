#ifndef ALUNOS_H
#define ALUNOS_H

struct Endereco {
	int numero;
	char rua[30];
	char uf[3];
}; 

typedef struct Aluno {
    int matricula;
	int idade;
	char nome[30];
	float nota;
	//struct Endereco end;
} Aluno;

Aluno* criaLista(int numAlunos);
void listarAlunos(Aluno *lista);
void adicionarAluno(Aluno *lista, Aluno aluno);
int buscarAluno(Aluno *lista, int matricula);
void removerAluno(Aluno *lista, int matricula);

#endif
