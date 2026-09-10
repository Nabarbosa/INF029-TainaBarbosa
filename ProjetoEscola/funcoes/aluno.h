#ifndef ALUNO_H
#define ALUNO_H

#include "validacoes.h"

typedef struct dtaNascimento{
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct aluno{
    int matricula;
    char nome[MAX_NOME_PESSOAS];
    char sexo;
    char cpf[N_CPF];
    DataNascimento dtNascimento;
} Aluno;


void cadastrarAluno(Aluno listaAluno[], int *qtdAluno);
void dataNascimento(Aluno lista_aluno[], int indice);

#endif