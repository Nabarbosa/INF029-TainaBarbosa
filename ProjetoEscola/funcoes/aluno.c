#include "aluno.h"

// CADASTRO DE ALUNO //

void cadastrarAluno(Aluno listaAluno[], int qtdAluno)
{
    int matricula;
    char nomeAluno[MAX_NOME_PESSOAS];
    char cpf[20];
    char sexoAluno[20];

    if(qtdAluno == TAM_PESSOAS){
        printf("Lista de Alunos Cheia!");
        return;
    }

    printf("\n====== Cadastro de Aluno(a) ======\n");

    printf("Digite a matricula do Aluno: \n");
    scanf("%d", &matricula);

    if (matricula <= 0){
        printf("Matrícula Inválida!\n");
    }

    printf("Informe o nome do Aluno(a): \n");
    scanf("%s", &nomeAluno);
    
    printf("Informe o sexo do aluno(a): \n");
    scanf("%s", &sexoAluno);

    printf("Informe a data de nascimento do aluno(a): \n");
    dataNascimento(listaAluno, qtdAluno);

    printf("Informe o CPF do aluno(a): \n");
    scanf("%s", &cpf);

    if(!validarCpf(cpf)){
        printf("O CPF digitado inválido. Tente novamente!");
        return;
    }

    if(cpf == listaAluno[qtdAluno].cpf){
        printf("O CPF digitado já existe em um cadastro!");
        return;
    }
    
    listaAluno[qtdAluno].matricula = matricula;
    //listaAluno[qtdAluno].nome = nomeAluno;
    //listaAluno[qtdAluno].sexo = sexoAluno;
    listaAluno[qtdAluno].cpf = cpf;

    qtdAluno++;

}