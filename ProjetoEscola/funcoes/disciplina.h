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

void cadastrarDisciplina(Disciplina listaDisciplina[], int *qtdDisciplina, Professor listaProfessor[], int qtdProfessor);
void listarDisciplinas(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor, Aluno listaAluno[], int qtdAluno, int opcao);
void cadastrarAlunoDisciplina(Disciplina listaDisciplina[], int *qtdDisciplina, Aluno listaAluno[], int *qtdAluno);
void excluirAlunoDisciplina(Disciplina listaDisciplina[], int *qtdDisciplina, Aluno listaAluno[], int *qtdAluno);

void menuListagemDisciplina();

#endif
