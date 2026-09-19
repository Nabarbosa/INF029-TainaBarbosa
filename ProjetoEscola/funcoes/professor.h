#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "validacoes.h"

typedef struct Aluno Aluno;
typedef struct Professor Professor;

typedef struct{
    int dia;
    int mes;
    int ano;
} DataNascimentoProfessor;

typedef struct Professor{
    int matricula;
    char nome[MAX_NOME_PESSOAS];
    char sexo;
    char cpf[N_CPF];
    DataNascimentoProfessor dtNascimento;
} Professor;

void cadastrarProfessor(Professor *listaProfessor, Aluno *listaAluno, int *qtdProf, int *qtdAluno);
void listarProfessores(Professor listaProfessor[], int qtdProf, int opcao);
void atualizarProfessor(Professor listaProfessor[], int qtdProf);
void excluirProfessor(Professor *listaProfessor, int *qtdProf);

void menuListagemProfessor();
void menuAtualizarProfessor();

void dataNascimentoProfessor(Professor listaProfessor[], int indice);
void ordenarDataNascimentoProfessor(Professor listaProfessor[], int qtdProf);

#endif