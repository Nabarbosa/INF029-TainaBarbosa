#include "aluno.h"
#include "validacoes.h"

// MENU DE ATUALIZAR //

void menuAtualizarAlunos(){

    printf("\n====== Menu de Atualização de Alunos ======\n");
    printf("1 - Atualizar nome do aluno(a)\n");
    printf("2 - Atualizar cpf do aluno(a)\n");
    printf("3 - Atualizar sexo do aluno(a)\n");
    printf("4 - Atualizar aniversario do aluno(a)\n");

}

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

//  ORDENAR DATA DE NASCIMENTO //

void ordenarDataNascimento(Aluno listaAluno[], int qtdAluno){

    for(int i = 0; i < qtdAluno - 1; i++){
        for(int j = i + 1; j < qtdAluno; j++){

            DataNascimento data1 = listaAluno[i].dtNascimento;
            DataNascimento data2 = listaAluno[j].dtNascimento;

            if(data1.ano > data2.ano ||
                data1.ano == data2.ano && data1.mes > data2.mes ||
                data1.ano == data2.ano && data1.mes == data2.mes && data1.dia > data2.dia){

                    Aluno aux = listaAluno[i];
                    listaAluno[i] = listaAluno[j];
                    listaAluno[j] = aux;
                }
        }
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

        int cpfExiste = 0;

        for(int i = 0; i < *qtdAluno; i++){
            if(strcmp(cpf, listaAluno[*qtdAluno].cpf) == 0){
                cpfExiste = 1;
                break;
            }
        }

        if(cpfExiste){
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
    printf("2 - Listar alunos por ordem de matrícula\n");
    printf("3 - Listar alunos por sexo(Masculino / Feminino)\n");
    printf("4 - Listar alunos por data de nascimento\n");
    printf("5 - Exibir aniversariantes do mês\n");

}

// LISTAR ALUNO //

void listarAlunos(Aluno listaAluno[], int qtdAluno, int opcao){
    if(qtdAluno == 0){
        printf("Lista de alunos vazia!\n");
        return;
    }

    Aluno copiaAluno[qtdAluno];

    for(int i = 0; i < qtdAluno; i++){
        copiaAluno[i] = listaAluno[i];
    }

    if(opcao == 1){
        // Ordenação por ordem alfabética //
        for(int i = 0; i < qtdAluno - 1; i++){
            for(int j = i + 1; j < qtdAluno; j++){
                if(copiaAluno[i].nome, copiaAluno[j].nome > 0){
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
            for(int j = i + 1; j < qtdAluno; j++){
                if(copiaAluno[i].matricula > copiaAluno[j].matricula){
                    Aluno aux = copiaAluno[i];
                    copiaAluno[i] = copiaAluno[j];
                    copiaAluno[j] = aux;
                }
            }
        }
    }

    if(opcao == 3){
        // Ordenação por sexo ( M - F ) //
        int escolha;
        printf("1 - Listar alunos do sexo Masculino\n");
        printf("2 - Listar alunos do sexo Feminino\n");
        printf("Digite sua opção:");
        scanf("%d", &escolha);

        switch(escolha){
            case 1: {
                for(int i = 0; i < qtdAluno; i++){
                    if(copiaAluno[i].sexo != 'M'){
                        continue;
                    }

                    printf("--------------- Aluno -------------\n");
                    printf("Matrícula: %d\n", copiaAluno[i].matricula);
                    printf("Nome do(a) Aluno(a): %s\n", copiaAluno[i].nome);
                    printf("CPF do(a) Aluno(a): %s\n", copiaAluno[i].cpf);
                    printf("Sexo do(a) Aluno(a): %c\n", copiaAluno[i].sexo);
                    printf("Data de nascimento: %d/%d/%d\n", copiaAluno[i].dtNascimento.dia, copiaAluno[i].dtNascimento.mes, copiaAluno[i].dtNascimento.ano);
                    printf("--------------------------------------------\n");
                }

                break;
            }

            case 2: {
                for(int i = 0; i < qtdAluno; i++){
                    if(copiaAluno[i].sexo != 'F'){
                        continue;
                    }

                    printf("--------------- Aluna -------------\n");
                    printf("Matrícula: %d\n", copiaAluno[i].matricula);
                    printf("Nome do(a) Aluno(a): %s\n", copiaAluno[i].nome);
                    printf("CPF do(a) Aluno(a): %s\n", copiaAluno[i].cpf);
                    printf("Sexo do(a) Aluno(a): %c\n", copiaAluno[i].sexo);
                    printf("Data de nascimento: %d/%d/%d\n", copiaAluno[i].dtNascimento.dia, copiaAluno[i].dtNascimento.mes, copiaAluno[i].dtNascimento.ano);
                    printf("--------------------------------------------\n");
                }

                break;
            }
        }
    }

    if(opcao == 4){
        // Ordenação por data de nascimento //
        ordenarDataNascimento(copiaAluno, qtdAluno);   
    }

    if(opcao == 5){
        // Aniversariantes do mês //
        int encontrou = 0;
        int mes;

        printf("\nInforme o mes que deseja saber se existe aniversariantes: \n");
        scanf("%d", &mes);

        printf("\n====== Aniversariantes do mês ======\n");

        for(int i = 0; i < qtdAluno; i++){
            if(copiaAluno[i].dtNascimento.mes == mes){
                printf("Nome: %s\n", copiaAluno[i].nome);
                printf("Data de nascimento: %02d/%02d/%d\n",
                    copiaAluno[i].dtNascimento.dia,
                    copiaAluno[i].dtNascimento.mes,
                    copiaAluno[i].dtNascimento.ano);

                printf("----------------------------------\n");

                encontrou = 1;
            }
        }
        if(!encontrou){
            printf("Não há aniversariantes neste mês.\n");
        }

        return;
    }
    
    int contador = 1;

    for(int i = 0; i < qtdAluno; i++){
        printf("--------------- Aluno: %d -------------\n", contador++);
        printf("Matrícula: %d\n", copiaAluno[i].matricula);
        printf("Nome do(a) Aluno(a): %s\n", copiaAluno[i].nome);
        printf("CPF do(a) Aluno(a): %s\n", copiaAluno[i].cpf);
        printf("Sexo do(a) Aluno(a): %c\n", copiaAluno[i].sexo);
        printf("Data de nascimento: %d/%d/%d\n", copiaAluno[i].dtNascimento.dia, copiaAluno[i].dtNascimento.mes, copiaAluno[i].dtNascimento.ano);
        printf("--------------------------------------------\n");
    }

    if(contador == 1){
        printf("Matricula do Aluno não foi encontrada!");
    }
}

// ATUALIZAR ALUNO //

void atualizarAluno(Aluno listaAluno[], int qtdAluno){
    if(qtdAluno == 0){
        printf("Não existe alunos cadastrados!\n");
        return;
    }
    
    printf("\n====== Atualizar Aluno(a) ======\n");
    
    int matricula;
    printf("Digite a matricula do aluno: \n");
    scanf("%d", &matricula);

    if(matricula < 0){
        printf("Matricula inválida!\n");
        return;
    }

    int indice = -1;

    for(int i = 0; i < qtdAluno; i++){
        if(listaAluno[i].matricula == matricula){
            indice = i;
            break;
        }
    }

    if(indice == -1){
        printf("Matricula do aluno não foi encontrada!\n");
        return;
    }

    menuAtualizarAlunos();

    int escolha;
    scanf("%d", &escolha);

    switch(escolha){
        case 1:{
            printf("Digite o novo nome do aluno(a): \n");
            char novoNome[MAX_NOME_PESSOAS];
            getchar();
            fgets(novoNome, sizeof(novoNome), stdin);
            novoNome[strcspn(novoNome, "\n")] = '\0';

            strcpy(listaAluno[indice].nome, novoNome);
            printf("Nome atualizado com sucesso!\n");
            
            break;
        }

        case 2:{
            printf("Digite o novo CPF do aluno(a): \n");
            char cpf[N_CPF];
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf,"\n")] = '\0';

            if(!validarCpf(cpf)){
                printf("O CPF digitado inválido. Tente novamente!\n");
                return;
            }

            strcpy(listaAluno[indice].cpf, cpf);
            printf("CPF atualizado com sucesso!\n");

            break;
        }

        case 3:{
            printf("Atualize o sexo do aluno(a): \n");
            char sexo[10];
            fgets(sexo, sizeof(sexo), stdin);

            listaAluno[indice].sexo = sexo[0];
            printf("Sexo do aluno(a) atualizado com sucesso!\n");

            break;
        }

        case 4:{
            printf("\nInforme a nova data de nascimento do aluno(a) em formato D/MM/AAAA: \n");
            int dia, mes, ano;
            scanf("%d/%d/%d", &dia, &mes, &ano);
            listaAluno[indice].dtNascimento.dia = dia;
            listaAluno[indice].dtNascimento.mes = mes;
            listaAluno[indice].dtNascimento.ano = ano;
            printf("Data de nascimento atualizada com sucesso!\n");

            break;
        }

        default:
            printf("\nOpção inválida\n");
    }
}

// EXCLUIR ALUNO //

void excluirAluno(Aluno listaAluno[], int *qtdAluno){
    if(*qtdAluno == 0){
        printf("Não existe alunos cadastrados!\n");
        return;
    }

    printf("\n====== Excluir Aluno(a) ======\n");

    int matricula;
    printf("Digite a matricula do aluno: \n");
    scanf("%d", &matricula);

    if(matricula < 0){
        printf("Matricula inválida!\n");
        return;
    }

    int encontrou = 0;

    for(int i = 0; i < *qtdAluno; i++){
        if(listaAluno[i].matricula == matricula){
            for(int j = i; j < *qtdAluno - 1; j++){
                listaAluno[j] = listaAluno[j + 1];
            }

            (*qtdAluno)--;
            encontrou = 1;
            break;
        }
    }

    if(encontrou){
        printf("Aluno(a) excluido com sucesso!\n");
    }
    else {
        printf("Matricula do aluno(a) inexistente!\n");
    }
}