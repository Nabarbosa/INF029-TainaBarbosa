#ifndef ALUNO_H
#define ALUNO_H

typedef struct dtaNascimento{
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct aluno{
    int matricula;
    char nome[225];
    char sexo;
    char cpf[15];
    DataNascimento dtNascimento;
} Aluno;


void cadastrarAluno(Aluno listaAluno[], int qtdAluno);

#endif