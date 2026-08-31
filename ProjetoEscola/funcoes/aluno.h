#ifndef ALUNO_H
#define Aluno_H

#include "include.h"

typedef struct aluno{
    int matricula;
    char nome[225];
    char sexo[225];
    int cpf;
    int dtNascimento;
} Aluno;

#endif