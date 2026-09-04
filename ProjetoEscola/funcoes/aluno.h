#ifndef ALUNO_H
#define ALUNO_H

#include "validacoes.h"

typedef struct aluno{
    int matricula;
    char nome[225];
    char sexo;
    int cpf;
    dtaNascimento dtNascimento;
} Aluno;

typedef struct dtaNascimento{
    int dia;
    int mes;
    int ano;
} dtaNascimento;

void cadastrarAluno(Aluno listaAluno[], int qtdAluno);

#endif