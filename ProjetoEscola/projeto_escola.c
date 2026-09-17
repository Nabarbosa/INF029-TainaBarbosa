#include "funcoes/disciplina.h"
#include "funcoes/aluno.h"
#include "funcoes/professor.h"
#include "funcoes/validacoes.h"

// cd ./ProjetoEscola/
// gcc projeto_escola.c funcoes/*.c -I funcoes -o projeto_escola && ./projeto_escola 

int main(void) {

    Aluno listaAluno[TAM_ALUNO] = {0};
    Professor listaProfessor[TAM_PROFESSOR] = {0};
    // Disciplina listaDisciplina[TAM_DISCIPLINA] = {0};

    int qtdAluno = 0;
    int qtdProf = 0;

    int opcao;

    int sair = 0;

    while (!sair){
        printf("\n========= Projeto Escola =========\n");
        printf("\t0 - Sair\n");
        printf("\t1 - Módulo Aluno\n");
        printf("\t2 - Módulo Professor\n");
        printf("\t3 - Módulo Disciplina\n");
        printf("===================================\n");
    
        scanf("%d", &opcao);
    
        switch (opcao){
            case 0:{
                sair = 1;
                break;
            }
            case 1:{
                printf("\nMódulo Aluno\n");

                int sairAluno = 0;
                int opcaoAluno;

                while(!sairAluno){
                    printf("\n======================================= \n");
                    printf("\t0 - Voltar ao Menu\n");
                    printf("\t1 - Cadastrar Aluno\n");
                    printf("\t2 - Listar Aluno\n");
                    printf("\t3 - Atualizar Aluno\n");
                    printf("\t4 - Excluir Aluno\n");
                    printf("======================================= \n");
                    scanf("%d", &opcaoAluno);

                    switch (opcaoAluno){
                        case 0:{
                            sairAluno = 1;
                            break;
                        }
                        case 1:{
                            printf("\n====== Cadastar Alunos ======\n");
                            cadastrarAluno(listaAluno, &qtdAluno);
                            break;
                        }
                        case 2:{
                            menuListagemAlunos();
                            int escolha;
                            scanf("%d", &escolha);

                            printf("\n====== Listar Alunos ======\n");
                            listarAlunos(listaAluno, qtdAluno, escolha);
                            break;
                        }
                        case 3:{
                            printf("\n====== Atualizar Aluno(a) ======\n");
                            atualizarAluno(listaAluno,qtdAluno);
                            break;
                        }
                        case 4:{
                            printf("\n====== Excluir Aluno(a) ======\n");
                            excluirAluno(listaAluno, &qtdAluno);
                            break;
                        }
                        
                        default:{
                            printf("\nOpção Inválida!\n");
                        }
                    }
                }

                break;
            }

            case 2:{
                printf("\nMódulo Professor\n");

                int sairProfessor = 0;
                int opcaoProf;

                while(!sairProfessor){
                    printf("\n======================================= \n");
                    printf("\t0 - Voltar ao Menu\n");
                    printf("\t1 - Cadastrar Professor\n");
                    printf("\t2 - Listar Professor\n");
                    printf("\t3 - Atualizar Professor\n");
                    printf("\t4 - Excluir Professor\n");
                    printf("======================================= \n");
                    scanf("%d", &opcaoProf);

                    switch (opcaoProf){
                        case 0:{
                            sairProfessor = 1;
                            break;
                        }
                        case 1:{
                            printf("\n====== Cadastar Professores ======\n");
                            cadastrarProfessor(listaProfessor, &qtdProf);
                            break;
                        }
                        case 2:{
                            menuListagemProfessor();
                            int escolha;
                            scanf("%d", &escolha);

                            printf("\n====== Listar Professores ======\n");
                            listarProfessores(listaProfessor, qtdProf, escolha);
                            break;
                        }
                        case 3:{
                            printf("\n====== Atualizar Professor(a) ======\n");
                            atualizarProfessor(listaProfessor, qtdProf);
                            break;
                        }
                        case 4:{
                            printf("\n====== Excluir Professor(a) ======\n");
                            excluirProfessor(listaProfessor, &qtdProf);
                            break;
                        }
                        
                        default:{
                            printf("\nOpção Inválida!\n");
                        }
                    }
                }

                break;
            }

            case 3:{
                printf("\nMódulo Disciplina\n");
                break;
            }
    
            default:{
                printf("\nOpção Inválida!\n");  
            }
        }
    }
    
}