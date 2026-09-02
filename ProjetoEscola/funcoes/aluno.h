#ifndef ALUNO_H
#define Aluno_H

#include "validacoes.h"

typedef struct aluno{
    int matricula;
    char nome[225];
    char sexo[225];
    int cpf;
    DtaNascimento dtNascimento;
} Aluno;

typedef struct dt{
    int dia;
    int mes;
    int ano;
} DtaNascimento;

#endif