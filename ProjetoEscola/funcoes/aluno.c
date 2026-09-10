#include "aluno.h"
#include "validacoes.h"

// DATA DE NASCIMENTO //

void dataNascimento(Aluno lista_aluno[], int indice){
    int dia, mes, ano;

    while(1){
        scanf("%d/%d/%d", &dia, &mes, &ano);
        getchar();

        if(!validarData(dia, mes, ano)){
            printf("Data digitada inválida. Tente novamente!\n");
            continue;
        }

        lista_aluno[indice].dtNascimento.dia = dia;
        lista_aluno[indice].dtNascimento.mes = mes;
        lista_aluno[indice].dtNascimento.ano = ano;

        break;
    }
}

// CADASTRO DE ALUNO //

void cadastrarAluno(Aluno listaAluno[], int *qtdAluno){
    int matricula;
    char nomeAluno[MAX_NOME_PESSOAS];
    char buffer[50];
    char cpf[20];

    if(*qtdAluno == TAM_ALUNO){
        printf("Lista de Alunos Cheia!");
        return;
    }

    printf("\n====== Cadastro de Aluno(a) ======\n");

    printf("Digite a matricula do Aluno: \n");
    scanf("%d", &matricula);
    getchar();

    if (matricula < 0){
        printf("Matrícula Inválida!\n");
    }

    printf("Informe o nome completo do Aluno(a): \n");
    fgets(nomeAluno, sizeof(nomeAluno), stdin);
    nomeAluno[strcspn(nomeAluno, "\n")] = '\0';
    
    printf("Informe o sexo do aluno(a) em formato M - Masculino | F - Feminino: \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexoAluno = buffer[0];

    printf("Informe a data de nascimento do aluno(a) em formato D/MM/AAAA: \n");
    dataNascimento(listaAluno, *qtdAluno);

    while(1){
        printf("Informe o CPF do aluno(a): \n");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0';

        if(!validarCpf(cpf)){
            printf("O CPF digitado inválido. Tente novamente!");
            continue;
        }

        if(strcmp(cpf, listaAluno[*qtdAluno].cpf) == 0){
            printf("O CPF digitado já existe em um cadastro!");
            continue;
        }
        break;
    }
    
    listaAluno[*qtdAluno].matricula = matricula;
    listaAluno[*qtdAluno].sexo = sexoAluno;
    strcpy(listaAluno[*qtdAluno].nome, nomeAluno);
    strcpy(listaAluno[*qtdAluno].cpf, cpf);

    qtdAluno++;

}

