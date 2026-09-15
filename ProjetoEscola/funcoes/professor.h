#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "validacoes.h"

typedef struct dtaNascimento{
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct professor{
    int matricula;
    char nome[MAX_NOME_PESSOAS];
    char sexo;
    char cpf[N_CPF];
    DataNascimento dtNascimento;
} Professor;


#endif