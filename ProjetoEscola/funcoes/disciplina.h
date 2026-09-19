#ifndef DISCIPLINA_H
#include DISCIPLINA_H

#include "validacoes.h"
#include "aluno.h"
#include "professor.h"

typedef struct Disciplina{
    char nomeDisciplina[MAX_NOME_MATERIA];
    int codigoDisciplina;
    int semestre;
    int qtdVagas;
    Professor professor;
    Aluno aluno[MAX_ALUNOS];
    int qtdAlunos;
} Disciplina;


#endif
