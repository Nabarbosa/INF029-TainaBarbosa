#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAM_ALUNO 4
#define TAM_DISCIPLINA 4
#define TAM_PROFESSOR 3
#define MAX_NOME_PESSOAS 256
#define N_CPF 15 
#define MAX_NOME_MATERIA 50
#define MAX_ALUNOS 40


int validarData(int dia, int mes, int ano);
int mesAtual();
int anoAtual();

int validarCpf(char cpf[]);

#endif