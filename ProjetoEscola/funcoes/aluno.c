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

    printf("\nDigite a matricula do Aluno: \n");
    scanf("%d", &matricula);
    getchar();

    if (matricula < 0){
        printf("Matrícula Inválida!\n");
    }

    printf("\nInforme o nome completo do Aluno(a): \n");
    fgets(nomeAluno, sizeof(nomeAluno), stdin);
    nomeAluno[strcspn(nomeAluno, "\n")] = '\0';
    
    printf("\nInforme o sexo do aluno(a) em formato M - Masculino | F - Feminino: \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexoAluno = buffer[0];

    printf("\nInforme a data de nascimento do aluno(a) em formato D/MM/AAAA: \n");
    dataNascimento(listaAluno, *qtdAluno);

    while(1){
        printf("\nInforme o CPF do aluno(a) sem os caracteres especiais: \n");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0';

        if(!validarCpf(cpf)){
            printf("O CPF digitado inválido. Tente novamente!\n");
            continue;
        }

        if(strcmp(cpf, listaAluno[*qtdAluno].cpf) == 0){
            printf("O CPF digitado já existe em um cadastro!\n");
            continue;
        }
        break;
    }
    
    listaAluno[*qtdAluno].matricula = matricula;
    listaAluno[*qtdAluno].sexo = sexoAluno;
    strcpy(listaAluno[*qtdAluno].nome, nomeAluno);
    strcpy(listaAluno[*qtdAluno].cpf, cpf);

    (*qtdAluno)++;

}

// MENU LISTAGEM DE ALUNOS //

void menuListagemAlunos(){

    printf("\n====== Menu Listagem de Alunos ======\n");
    printf("1 - Listar alunos por ordem alfabética\n");
    printf("1 - Listar alunos por ordem de matrícula\n");
    printf("2 - Listar alunos por sexo(Masculino / Feminino)\n");
    printf("3 - Listar alunos por data de nascimento\n");
    printf("4 - Exibir aniversáriantes do mês\n");

}

// LISTAR ALUNO //

void listarAlunos(Aluno listarAluno[], int qtdAluno, int opcao){
    if(qtdAluno == 0){
        printf("Lista de alunos vazia!\n");
        return;
    }

    Aluno copiaAluno[qtdAluno];

    for(int i = 0; i < qtdAluno; i++){
        copiaAluno[i] = listarAluno[i];
    }

    if(opcao == 1){
        // Ordenação por ordem alfabética //
        for(int i = 0; i < qtdAluno - 1; i++){
            for(int j = i + 1; j < qtdAluno){
                if(strcmp(copiaAluno[i].nome, copiaAluno[j].nome) > 0){
                    Aluno aux = copiaAluno[i];
                    copiaAluno[i] = copiaAluno[j];
                    copiaAluno[j] = aux;
                }
            }
        }
    }

    if(opcao == 2){
         // Ordenação por ordem de matricula //
        for(int i = 0; i < qtdAluno - 1; i++){
            for(int j = i + 1; j < qtdAluno){
                if(strcmp(copiaAluno[i].matricula, copiaAluno[j].matricula) > 0){
                    Aluno aux = copiaAluno[i];
                    copiaAluno[i] = copiaAluno[j];
                    copiaAluno[j] = aux;
                }
            }
        }
    }

    if(opcao == 3){
        int escolha;
        printf("1 - Listar alunos do sexo Masculino\n");
        printf("1 - Listar alunos do sexo Feminino\n");
        printf("Digite sua opção:");
        scanf("%d", &escolha);

        switch(escolha){
            case 1: {

            }
        }
    }
}