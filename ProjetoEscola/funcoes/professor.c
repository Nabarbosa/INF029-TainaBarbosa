#include <stdio.h>
#include <string.h>
#include "professor.h"
#include "aluno.h"
#include "validacoes.h"

// DATA DE NASCIMENTO //

void dataNascimentoProfessor(Professor listaProfessor[], int indice){
    int dia, mes, ano;

    while(1){
        scanf("%d/%d/%d", &dia, &mes, &ano);
        getchar();

        if(!validarData(dia, mes, ano)){
            printf("Data digitada inválida. Tente novamente!\n");
            continue;
        }

        listaProfessor[indice].dtNascimento.dia = dia;
        listaProfessor[indice].dtNascimento.mes = mes;
        listaProfessor[indice].dtNascimento.ano = ano;

        break;
    }
}

// ORDENAR DATA DE NASCIMENTO //

void ordenarDataNascimentoProfessor(Professor listaProfessor[], int qtdProf){
    for(int i = 0; i < qtdProf - 1; i++){
        for(int j = i + 1; j < qtdProf; j++){
            DataNascimentoProfessor data1 = listaProfessor[i].dtNascimento;
            DataNascimentoProfessor data2 = listaProfessor[j].dtNascimento;

            if(data1.ano > data2.ano ||
               (data1.ano == data2.ano && data1.mes > data2.mes) ||
               (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia > data2.dia)){

                Professor aux = listaProfessor[i];
                listaProfessor[i] = listaProfessor[j];
                listaProfessor[j] = aux;
            }
        }
    }
}

// CADASTRO DE PROFESSOR //

void cadastrarProfessor(Professor listaProfessor[], Aluno listaAluno[], int *qtdProf, int *qtdAluno){
    int matricula;
    char nomeProfessor[MAX_NOME_PESSOAS];
    char buffer[50];
    char cpf[20];

    if(*qtdProf == TAM_PROFESSOR){
        printf("Lista de Profesores Cheia!\n");
        return;
    }

    printf("\n====== Cadastro de Professor(a) ======\n");
    while(1){
        printf("\nDigite a matricula do Professor: \n");
        scanf("%d", &matricula);
        getchar();

        if (matricula < 0){
            printf("Matrícula Inválida!\n");
            continue;
        }

        int matriculaExiste = 0;
        for(int i = 0; i < *qtdProf; i++){
            if(listaProfessor[i].matricula == matricula){
                matriculaExiste = 1;
                break;
            }
        }

        if(matriculaExiste){
            printf("Esta matrícula já está cadastrada! Tente outra.\n");
            continue;
        }

        int matriculaExisteEmAluno = 0;
        for(int i = 0; i < *qtdAluno; i++){
            if(listaAluno[i].matricula == matricula){
                matriculaExisteEmAluno = 1;
                break;
            }
        }
        if(matriculaExisteEmAluno){
            printf("Esta matrícula já está cadastrada em um aluno! Tente outra.\n");
            continue;
        }

        break;
    }

    printf("\nInforme o nome completo do Pofessor(a): \n");
    fgets(nomeProfessor, sizeof(nomeProfessor), stdin);
    nomeProfessor[strcspn(nomeProfessor, "\n")] = '\0';
    
    printf("\nInforme o sexo do Professor(a) em formato M - Masculino | F - Feminino: \n");
    fgets(buffer, sizeof(buffer), stdin);
    char sexoProfessor = buffer[0];

    printf("\nInforme a data de nascimento do Professor(a) em formato D/MM/AAAA: \n");
    dataNascimentoProfessor(listaProfessor, *qtdProf);

    while(1){
        printf("\nInforme o CPF do Professor(a) sem os caracteres especiais: \n");
        fgets(cpf, sizeof(cpf), stdin);
        cpf[strcspn(cpf, "\n")] = '\0';

        if(!validarCpf(cpf)){
            printf("O CPF digitado é inválido. Tente novamente!\n");
            continue;
        }

        int cpfExiste = 0;
        for(int i = 0; i < *qtdProf; i++){
            if(strcmp(listaProfessor[i].cpf, cpf) == 0){
                cpfExiste = 1;
                break;
            }
        }

        if(cpfExiste){
            printf("O CPF digitado já existe em um cadastro!\n");
            continue;
        }

        int cpfExisteEmAluno = 0;
        for(int i = 0; i < *qtdAluno; i++){
            if(strcmp(listaAluno[i].cpf, cpf) == 0){ 
                cpfExisteEmAluno = 1;
                break;
            }
        }
        if(cpfExisteEmAluno){
            printf("Este CPF já está cadastrado em um aluno! Tente outro.\n");
            continue;
        }

        break;
    }
    
    listaProfessor[*qtdProf].matricula = matricula;
    listaProfessor[*qtdProf].sexo = sexoProfessor;
    strcpy(listaProfessor[*qtdProf].nome, nomeProfessor);
    strcpy(listaProfessor[*qtdProf].cpf, cpf);

    (*qtdProf)++;
    printf("\nProfessor cadastrado com sucesso!\n");
}

// MENU LISTAGEM DE ALUNOS //

void menuListagemProfessor(){
    printf("\n====== Menu Listagem de Professor ======\n");
    printf("1 - Listar professor por ordem alfabética\n");
    printf("2 - Listar professor por ordem de matrícula\n");
    printf("3 - Listar professor por sexo(Masculino / Feminino)\n");
    printf("4 - Listar professor por data de nascimento\n");
    printf("5 - Exibir aniversariantes do mês\n");
    printf("6 - Exibir aniversariantes do mês\n");
}

// MENU DE ATUALIZAR //

void menuAtualizarProfessor(){
    printf("\n====== Menu de Atualização de Professores ======\n");
    printf("1 - Atualizar nome do professor(a)\n");
    printf("2 - Atualizar cpf do professor(a)\n");
    printf("3 - Atualizar sexo do professor(a)\n");
    printf("4 - Atualizar aniversario do professor(a)\n");
}

// LISTAR PROFESSOR //

void listarProfessores(Professor listaProfessor[], int qtdProf, int opcao){
    if(qtdProf == 0){
        printf("Lista de Professores vazia!\n");
        return;
    }

    Professor copiaProfessor[qtdProf];

    for(int i = 0; i < qtdProf; i++){
        copiaProfessor[i] = listaProfessor[i];
    }

    if(opcao == 1){
        // Ordenação por ordem alfabética
        for(int i = 0; i < qtdProf - 1; i++){
            for(int j = i + 1; j < qtdProf; j++){
                if(strcmp(copiaProfessor[i].nome, copiaProfessor[j].nome) > 0){
                    Professor aux = copiaProfessor[i];
                    copiaProfessor[i] = copiaProfessor[j];
                    copiaProfessor[j] = aux;
                }
            }
        }
    }

    else if(opcao == 2){
        // Ordenação por ordem de matricula
        for(int i = 0; i < qtdProf - 1; i++){
            for(int j = i + 1; j < qtdProf; j++){
                if(copiaProfessor[i].matricula > copiaProfessor[j].matricula){
                    Professor aux = copiaProfessor[i];
                    copiaProfessor[i] = copiaProfessor[j];
                    copiaProfessor[j] = aux;
                }
            }
        }
    }

    else if(opcao == 3){
        // Filtro por sexo
        int escolha;
        printf("1 - Listar professores do sexo Masculino\n");
        printf("2 - Listar professores do sexo Feminino\n");
        printf("Digite sua opção: ");
        scanf("%d", &escolha);

        char sexoFiltro = (escolha == 1) ? 'M' : 'F';
        int encontrou = 0;

        for(int i = 0; i < qtdProf; i++){
            if(copiaProfessor[i].sexo == sexoFiltro){
                printf("--------------- Professor -------------\n");
                printf("Matrícula: %d\n", copiaProfessor[i].matricula);
                printf("Nome do(a) Professor(a): %s\n", copiaProfessor[i].nome);
                printf("CPF do(a) Professor(a): %s\n", copiaProfessor[i].cpf);
                printf("Sexo do(a) Professor(a): %c\n", copiaProfessor[i].sexo);
                printf("Data de nascimento: %02d/%02d/%d\n", copiaProfessor[i].dtNascimento.dia, copiaProfessor[i].dtNascimento.mes, copiaProfessor[i].dtNascimento.ano);
                printf("--------------------------------------------\n");
                encontrou = 1;
            }
        }

        if(!encontrou){
            printf("Nenhum Professor encontrado para o sexo selecionado.\n");
        }
        return;
    }
    else if(opcao == 4){
        // Ordenação por data de nascimento
        ordenarDataNascimentoProfessor(copiaProfessor, qtdProf);   
    }
    else if(opcao == 5){
        // Aniversariantes do mês
        int encontrou = 0;
        int mes;

        printf("\nInforme o mes que deseja saber se existe aniversariantes: \n");
        scanf("%d", &mes);

        printf("\n====== Aniversariantes do mês ======\n");

        for(int i = 0; i < qtdProf; i++){
            if(copiaProfessor[i].dtNascimento.mes == mes){
                printf("Nome: %s\n", copiaProfessor[i].nome);
                printf("Data de nascimento: %02d/%02d/%d\n",
                    copiaProfessor[i].dtNascimento.dia,
                    copiaProfessor[i].dtNascimento.mes,
                    copiaProfessor[i].dtNascimento.ano);
                printf("----------------------------------\n");
                encontrou = 1;
            }
        }
        if(!encontrou){
            printf("Não há aniversariantes neste mês.\n");
        }
        return; 
    }

    else if(opcao == 6){
        // Encontrar professor por nome

        char busca[MAX_NOME_PESSOAS];
        int encontrou = 0;

        while(getchar() != '\n');

        printf("\nDigite pelo menos 3 letras do nome: ");
        fgets(busca, sizeof(busca), stdin);

        busca[strcspn(busca, "\n")] = '\0';

        if(strlen(busca) < 3){
            printf("Digite pelo menos 3 letras!\n");
            return;
        }

        printf("\n====== Professores encontrados ======\n");
        for(int i = 0; i < qtdProf; i++){
            if(strstr(copiaProfessor[i].nome, busca) != NULL){
                printf("--------------- Professor -------------\n");
                printf("Matrícula: %d\n", copiaProfessor[i].matricula);
                printf("Nome do(a) Professor(a): %s\n", copiaProfessor[i].nome);
                printf("CPF do(a) Professor(a): %s\n", copiaProfessor[i].cpf);
                printf("--------------------------------------------\n");
                encontrou = 1;
            }
        }

        if(!encontrou){
            printf("Nenhum professor encontrado com essa busca.\n");
        }

        return;
    }

    for(int i = 0; i < qtdProf; i++){
        printf("--------------- Professor: %d -------------\n", i + 1);
        printf("Matrícula: %d\n", copiaProfessor[i].matricula);
        printf("Nome do(a) Aluno(a): %s\n", copiaProfessor[i].nome);
        printf("CPF do(a) Aluno(a): %s\n", copiaProfessor[i].cpf);
        printf("Sexo do(a) Aluno(a): %c\n", copiaProfessor[i].sexo);
        printf("Data de nascimento: %02d/%02d/%d\n", copiaProfessor[i].dtNascimento.dia, copiaProfessor[i].dtNascimento.mes, copiaProfessor[i].dtNascimento.ano);
        printf("--------------------------------------------\n");
    }
}

// ATUALIZAR PROFESSOR //

void atualizarProfessor(Professor listaProfessor[], int qtdProf){
    if(qtdProf == 0){
        printf("Não existe professores cadastrados!\n");
        return;
    }
    
    printf("\n====== Atualizar Professor(a) ======\n");
    
    int matricula;
    printf("Digite a matricula do professor: \n");
    scanf("%d", &matricula);

    if(matricula < 0){
        printf("Matricula inválida!\n");
        return;
    }

    int indice = -1;

    for(int i = 0; i < qtdProf; i++){
        if(listaProfessor[i].matricula == matricula){
            indice = i;
            break;
        }
    }

    if(indice == -1){
        printf("Matricula do professor não foi encontrada!\n");
        return;
    }

    menuAtualizarProfessor();

    int escolha;
    scanf("%d", &escolha);
    getchar(); 

    switch(escolha){
        case 1:{
            printf("Digite o novo nome do professor(a): \n");
            char novoNome[MAX_NOME_PESSOAS];
            fgets(novoNome, sizeof(novoNome), stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';

            strcpy(listaProfessor[indice].nome, novoNome);
            printf("Nome atualizado com sucesso!\n");
            break;
        }

        case 2:{
            printf("Digite o novo CPF do professor(a): \n");
            char cpf[N_CPF];
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf,"\n")] = '\0';

            if(!validarCpf(cpf)){
                printf("O CPF digitado é inválido. Tente novamente!\n");
                return;
            }

            for(int i = 0; i < qtdProf; i++){
                if(i != indice && strcmp(listaProfessor[i].cpf, cpf) == 0){
                    printf("Este CPF já pertence a outro professor cadastrado!\n");
                    return;
                }
            }

            strcpy(listaProfessor[indice].cpf, cpf);
            printf("CPF atualizado com sucesso!\n");
            break;
        }

        case 3:{
            printf("Atualize o sexo do professor(a) (M/F): \n");
            char sexo[10];
            fgets(sexo, sizeof(sexo), stdin);

            listaProfessor[indice].sexo = sexo[0];
            printf("Sexo do professor(a) atualizado com sucesso!\n");
            break;
        }

        case 4:{
            printf("\nInforme a nova data de nascimento do professor(a) em formato D/MM/AAAA: \n");
            int dia, mes, ano;
            scanf("%d/%d/%d", &dia, &mes, &ano);
            
            if(!validarData(dia, mes, ano)){
                printf("Data digitada inválida!\n");
                return;
            }

            listaProfessor[indice].dtNascimento.dia = dia;
            listaProfessor[indice].dtNascimento.mes = mes;
            listaProfessor[indice].dtNascimento.ano = ano;
            printf("Data de nascimento atualizada com sucesso!\n");
            break;
        }

        default:
            printf("\nOpção inválida\n");
    }
}

// EXCLUIR PROFESSOR //

void excluirProfessor(Professor listaProfessor[], int *qtdProf){
    if(*qtdProf == 0){
        printf("Não existe professores cadastrados!\n");
        return;
    }

    printf("\n====== Excluir Professor(a) ======\n");

    int matricula;
    printf("Digite a matricula do professor: \n");
    scanf("%d", &matricula);

    if(matricula < 0){
        printf("Matricula inválida!\n");
        return;
    }

    int encontrou = 0;

    for(int i = 0; i < *qtdProf; i++){
        if(listaProfessor[i].matricula == matricula){
            for(int j = i; j < *qtdProf - 1; j++){
                listaProfessor[j] = listaProfessor[j + 1];
            }

            (*qtdProf)--;
            encontrou = 1;
            break;
        }
    }

    if(encontrou){
        printf("Professor(a) excluido com sucesso!\n");
    }
    else {
        printf("Matricula do professor(a) inexistente!\n");
    }
}