#include "disciplina.h"

// CADASTRAR DISCIPLINA //

void cadastrarDisciplina(Disciplina listaDisciplina[], int *qtdDisciplina, Professor listaProfessor[], int qtdProfessor){
    char nomeMateria[MAX_NOME_MATERIA];
    
    if(*qtdDisciplina == TAM_DISCIPLINA){
        printf("Lista de disciplina cheia!\n");
        return;
    }

    printf("\n====== Cadastro de Disciplinas ======\n");

    printf("Digite o codigo da disciplina: \n");
    scanf("%d", &listaDisciplina[*qtdDisciplina].codigoDisciplina);

    if(listaDisciplina[*qtdDisciplina].codigoDisciplina <= 0){
        printf("Codigo da disciplina digitado inválido!\n");
    }

    printf("Digite o nome da matéria: \n");
    getchar();
    fgets(nomeMateria, sizeof(nomeMateria), stdin);
    nomeMateria[strcspn(nomeMateria, "\n")] = '\0';

    printf("Informe a matricula do professor que irá lecionar a matéria: \n");
    int matriculaProf;
    scanf("%d", &matriculaProf);

    int encontrou = -1;
    for(int i = 0; i < qtdProfessor; i++){
        if(matriculaProf == listaProfessor[i].matricula){
            encontrou = i;
            break;
        }
    }

    if(encontrou == -1){
        printf("Erro: Professor com a matricula %d, não foi encontrado!", matriculaProf);
        return;
    }

    printf("Informe o semestre da disciplina: \n");
    scanf("%d", &listaDisciplina[*qtdDisciplina].semestre);

    printf("Informe a quantidade de vagas que a disciplina possui: \n");
    scanf("%d", &listaDisciplina[*qtdDisciplina].qtdVagas);

    listaDisciplina[*qtdDisciplina].professor = listaProfessor[encontrou];
    strcpy(listaDisciplina[*qtdDisciplina].nomeDisciplina, nomeMateria);

    (*qtdDisciplina)++;

    printf("Disciplina Cadastrada com Sucesso!\n");
}

// MENU LISTAGEM DISCIPLINA //

void menuListagemDisciplina(){
    printf("\n====== Menu Listagem de Disciplina ======\n");
    printf("\t 1 - Listar disciplinas (sem dados dos alunos)\n");
    printf("\t 2 - Listar disciplinas (com os dados dos alunos)\n");
    printf("\t 3 - Listar disciplinas com professores(extrapolam 40 vagas)\n");
}

// LISTAR DISCIPLINA //

void listarDisciplinas(Disciplina listaDisciplina[], int qtdDisciplina, Professor listaProfessor[], int qtdProfessor, Aluno listaAluno[], int qtdAluno, int opcao){
    if(qtdDisciplina == 0){
        printf("Lista de disciplinas vazia!");
        return;
    }

    Disciplina copiaDisciplina[qtdDisciplina];

    for(int i = 0; i < qtdDisciplina; i++){
        copiaDisciplina[i] = listaDisciplina[i];
    }

    if(opcao == 1){
        // Sem dados de alunos
        int contador = 1;

        for(int i = 0; i < qtdDisciplina; i++){
            printf("\n====== Disciplina %d ======\n", contador);
            printf("Codigo da disciplina: %d\n", copiaDisciplina[i].codigoDisciplina);
            printf("Nome da disciplina: %s\n", copiaDisciplina[i].nomeDisciplina);
            printf("Semestre da disciplina: %d\n", copiaDisciplina[i].semestre);
            printf("Vagas da disciplina: %d\n", copiaDisciplina[i].qtdVagas);
            printf("Professor(a) da disciplina: %s\n", copiaDisciplina[i].professor.nome);
        }
    }

    else if(opcao == 2){
        // Listar disciplina com os dados dos alunos
        printf("Informe o codigo da disciplina: \n");
        int cod_disciplina;
        scanf("%d", &cod_disciplina);

        if(cod_disciplina <= 0){
            printf("\nCodigo da disciplina inválido!\n");
            return;
        }

        int encontrou = -1;
        for(int i = 0; i < qtdDisciplina; i++){
            if(cod_disciplina == listaDisciplina[i].codigoDisciplina){
                encontrou = i;
                break;
            }
        }

        if(encontrou == -1){
            printf("\nErro: Disciplina com o codigo %d não foi encontrada!\n", cod_disciplina);
            return;
        }

        int contador = 1;
        printf("\n====== Dados da Disciplina %d ======\n", contador);
        printf("Codigo da disciplina: %d\n", copiaDisciplina[encontrou].codigoDisciplina);
        printf("Nome da disciplina: %s\n", copiaDisciplina[encontrou].nomeDisciplina);
        printf("Professor(a) da disciplina: %s\n", copiaDisciplina[encontrou].professor.nome);

        printf("\n====== Alunos Matriculados ======\n");

        if(listaDisciplina[encontrou].qtdAlunos == 0){
            printf("Nenhum aluno matriculado nesta matricula!\n");
        } else {
            for(int i = 0; i < listaDisciplina[encontrou].qtdAlunos; i++){
                printf("\t Alunos %s \t(Matricula: %d)\n", 
                        listaDisciplina[encontrou].aluno[i].nome,
                        listaDisciplina[encontrou].aluno[i].matricula);
            }
        }
        
    }

    else if(opcao == 3){
        // Disciplinas que extrapolam 40 vagas

        int contador = 1;
        int encontrou = 0;

        for(int i = 0; i < qtdDisciplina; i++){
            if(copiaDisciplina[i].qtdVagas > 40){
                printf("\n====== Disciplina %d ======\n", contador);
                printf("Codigo da disciplina: %d\n",copiaDisciplina[i].codigoDisciplina);
                printf("Nome da disciplina: %s\n",copiaDisciplina[i].nomeDisciplina);
                printf("Semestre da disciplina: %d\n",copiaDisciplina[i].semestre);
                printf("Vagas da disciplina: %d\n",copiaDisciplina[i].qtdVagas);
                printf("Professor(a) da disciplina: %s\n",copiaDisciplina[i].professor.nome);

                contador++;
                encontrou = 1;
            }
        }

        if(!encontrou){
            printf("\nNão existem disciplinas que extrapolam 40 vagas!\n");
        }

        return;
    }
}

// INSERIR ALUNOS NA MATÉRIA //

void cadastrarAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno){
    printf("\n====== Cadastrar Aluno em uma Disciplina ======\n");
    printf("Informe o codigo da disciplina que deseja cadastrar o aluno: \n");
    int cod_disciplina = 0;
    scanf("%d", &cod_disciplina);

    if(cod_disciplina <= 0){
        printf("Codigo da disciplina inválida!\n");
        return;
    }

    int encontrarDisciplina = -1;
    for(int i = 0; i < qtdDisciplina; i++){
        if(cod_disciplina == listaDisciplina[i].codigoDisciplina){
            encontrarDisciplina = i;
            break;
        }
    }

    if(encontrarDisciplina == -1){
        printf("Erro: Disciplina com o codigo %d não encontrado!", cod_disciplina);
        return;
    }

    if(listaDisciplina[encontrarDisciplina].qtdAlunos >= listaDisciplina[encontrarDisciplina].qtdVagas){
        printf("Erro: Disciplina sem vagas diponiveis!\n");
        return;
    }

    printf("Informe a matricula do aluno:\n");
    int matricula_aluno = 0;
    scanf("%d", &matricula_aluno);

    int encontrarAluno = -1;
    for(int i = 0; i < qtdAluno; i++){
        if(matricula_aluno == listaAluno[i].matricula){
            encontrarAluno = i;
        }
    }

    if(encontrarAluno == -1){
        printf("Erro: nenhum aluno encontrado com a matricula %d\n", matricula_aluno);
        return;
    }

    int alunoMatriculado = 0;
    for(int i = 0; i < qtdDisciplina; i++){
        for(int j = 0; j < qtdAluno; j++){
            if(listaDisciplina[i].aluno[j].matricula == matricula_aluno){
                alunoMatriculado = 1;
                break;
            }
        }
    }

    if(alunoMatriculado){
        printf("Esta matrícula já está cadastrada! Tente outra.\n");
        return;
    }

    int posicaoAluno = listaDisciplina[encontrarDisciplina].qtdAlunos;
    listaDisciplina[encontrarDisciplina].aluno[posicaoAluno] = listaAluno[encontrarAluno];
    listaDisciplina[encontrarDisciplina].qtdAlunos++;

    printf("Aluno matriculado na disciplina com sucesso!\n");
}

// EXCLUIR ALUNO DA DISCIPLINA //

void excluirAlunoDisciplina(Disciplina listaDisciplina[], int qtdDisciplina, Aluno listaAluno[], int qtdAluno){
    printf("\n====== Excluir Aluno em uma Disciplina ======\n");
    printf("\nDigite o codigo da disciplina: \n");
    int codigo_disciplina = 0;
    scanf("%d", &codigo_disciplina);

    if(codigo_disciplina <= 0){
        printf("Codigo da disciplina inválido!\n");
        return;
    }

    int encontrou_disciplina = -1;
    for(int i = 0; i < qtdDisciplina; i++){
        if(codigo_disciplina == listaDisciplina[i].codigoDisciplina){
            encontrou_disciplina = i;
            break;
        }
    }

    if(encontrou_disciplina == -1){
        printf("Erro: o codigo %d da disciplina não foi encontrado!\n", codigo_disciplina);
        return;
    }

    printf("\nInforme a matricula do aluno: \n");
    int matricula; 
    scanf("%d", &matricula); 

    int encontrar_aluno = -1;
    for(int i = 0; i < qtdAluno; i++){
        if(matricula == listaAluno[i].matricula){
            encontrar_aluno = i;
            break;
        }
    }

    if(encontrar_aluno == -1){
        printf("Erro: Aluno de matricula %d não encontrado!\n", matricula);
        return;
    }

    int achou_aluno_disciplina = -1;
    for(int i = 0; i < listaDisciplina[encontrou_disciplina].qtdAlunos; i++){
        if(listaDisciplina[encontrou_disciplina].aluno[i].matricula == matricula){
            achou_aluno_disciplina = i;
            break;
        }
    }

    if(achou_aluno_disciplina != -1){
        for(int j = achou_aluno_disciplina; j < listaDisciplina[encontrou_disciplina].qtdAlunos - 1; j++){
            listaDisciplina[encontrou_disciplina].aluno[j] = listaDisciplina[encontrou_disciplina].aluno[j+1];
        }

        listaDisciplina[encontrou_disciplina].qtdAlunos--;
        printf("\nAluno excluido da disciplina com sucesso!\n");

    } else {
        printf("\nEste aluno não está matriculado nesta matéria!\n");
    }
}
