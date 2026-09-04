#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_ALUNO 3
#define TAM_DISCIPLINA 4
#define TAM_PROFESSOR 2
#define MAX_NOME_PESSOAS 256
#define N_CPF 15 

int anoAtual();
int validarData(int dia, int mes, int ano);
void dataNascimento(Aluno lista_aluno[], int indice);

int validarCpf(char cpf[]);

#endif