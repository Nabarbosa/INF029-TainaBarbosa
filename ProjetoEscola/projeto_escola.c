#include "funcoes/disciplina.h"
#include "funcoes/aluno.h"
#include "funcoes/professor.h"
#include "funcoes/validacoes.h"

int main(void) {

    Aluno listaAluno[TAM_ALUNO] = {0};
    Aluno listaProfessor[TAM_PROFESSOR] = {0};
    Aluno listaDisciplina[TAM_DISCIPLINA] = {0};

    int qtdAluno = 0;
    int opcao;

    int sair = 0;

    while (!sair){
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Módulo Aluno\n");
        printf("2 - Módulo Professor\n");
        printf("3 - Módulo Disciplina\n");
    
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
                    printf("0 - Voltar ao Menu\n");
                    printf("1 - Cadastrar Aluno\n");
                    printf("2 - Listar Aluno\n");
                    printf("3 - Atualizar Aluno\n");
                    printf("4 - Excluir Aluno\n");
                    scanf("%d", &opcaoAluno);

                    switch (opcaoAluno){
                        case 0:{
                            sairAluno = 1;
                            break;
                        }
                        case 1:{
                            cadastrarAluno(listaAluno, qtdAluno);
                        }
                        case 2:{
                            printf("\nListar Alunos\n");
                            for(int i = 0; i < qtdAluno; i++){
                                printf("Matricula: %d\n", listaAluno[i]);
                            }
                            break;
                        }
                        case 3:{
                            printf("\nAtualizar Aluno(a)\n");
                            break;
                        }
                        case 4:{
                            printf("\nExcluir Aluno(a)\n");
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