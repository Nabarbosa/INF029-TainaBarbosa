#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "validacoes.h"

typedef struct{
    int dia;
    int mes;
    int ano;
} DataNascimentoProfessor;

typedef struct professor{
    int matricula;
    char nome[MAX_NOME_PESSOAS];
    char sexo;
    char cpf[N_CPF];
    DataNascimentoProfessor dtNascimento;
} Professor;

void cadastrarProfessor(Professor listaProfessor[], int *qtdProf);
void listarProfessores(Professor listaProfessor[], int qtdProf, int opcao);
void atualizarProfessor(Professor listaProfessor[], int qtdProf);
void excluirProfessor(Professor listaProfessor[], int *qtdProf);

void menuListagemProfessor();
void menuAtualizarProfessor();

void dataNascimentoProfessor(Professor listaProfessor[], int indice);
void ordenarDataNascimentoProfessor(Professor listaProfessor[], int qtdProf);

#endif