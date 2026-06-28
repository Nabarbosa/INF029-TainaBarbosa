#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct
{
    int *vetor;
    int tamanho;
    int qtdElementos;
} Auxiliar;

Auxiliar vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;

    if (posicao < 1 || posicao > TAM)
    {
        // se posição é um valor válido {entre 1 e 10}
        retorno = POSICAO_INVALIDA;
    }
    else if (tamanho < 1)
    {
        // o tamanho nao pode ser menor que 1
        retorno = TAMANHO_INVALIDO;
    }
    else
    {
        posicao--;

        if (vetorPrincipal[posicao].vetor != NULL)
        {
            // a posicao pode já existir estrutura auxiliar
            retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        }
        else
        {
            int *vetorAux = malloc(tamanho * sizeof(int));

            if (vetorAux == NULL)
            {
                // o tamanho ser muito grande
                retorno = SEM_ESPACO_DE_MEMORIA;
            }
            else
            {
                vetorPrincipal[posicao].vetor = vetorAux;
                vetorPrincipal[posicao].tamanho = tamanho;
                vetorPrincipal[posicao].qtdElementos = 0;
                // deu tudo certo, crie
                retorno = SUCESSO;
            }
        }
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao < 1 || posicao > TAM)
        retorno = POSICAO_INVALIDA;

    else
    {
        Auxiliar *vetorAux = &vetorPrincipal[posicao - 1];

        // testar se existe a estrutura auxiliar
        if (vetorAux->vetor != NULL)
            existeEstruturaAuxiliar = 1;

        if (existeEstruturaAuxiliar)
        {
            if (vetorAux->qtdElementos < vetorAux->tamanho)
                temEspaco = 1;

            if (temEspaco)
            {
                // insere
                vetorAux->vetor[vetorAux->qtdElementos] = valor;
                vetorAux->qtdElementos++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > TAM)
        retorno = POSICAO_INVALIDA;

    else
    {
        posicao--;

        if (vetorPrincipal[posicao].vetor != NULL)
        {
            if (vetorPrincipal[posicao].qtdElementos == 0)
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            else
                vetorPrincipal[posicao].qtdElementos--;
        }
        else
            retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > TAM)
        retorno = POSICAO_INVALIDA;

    else
    {
        posicao--;

        Auxiliar *vetorAux = &vetorPrincipal[posicao];

        if (vetorAux->vetor == NULL)
            return SEM_ESTRUTURA_AUXILIAR;

        if (vetorAux->qtdElementos == 0)
            return ESTRUTURA_AUXILIAR_VAZIA;

        for (int i = 0; i < vetorAux->qtdElementos; i++)
        {
            if (vetorAux->vetor[i] == valor)
            {
                for (int j = i; j < vetorAux->qtdElementos - 1; j++)
                {
                    vetorAux->vetor[j] = vetorAux->vetor[j + 1];
                }

                vetorAux->qtdElementos--;

                return SUCESSO;
            }
        }
    }

    return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}

int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int invalido = ehPosicaoValida(posicao);

    if (invalido != SUCESSO)
        retorno = POSICAO_INVALIDA;

    else
    {
        posicao--;

        Auxiliar *aux = &vetorPrincipal[posicao];

        if (aux->vetor == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;

        else
        {
            for (int i = 0; i < aux->qtdElementos; i++)
                vetorAux[i] = aux->vetor[i];

            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    int invalido = ehPosicaoValida(posicao);

    if (invalido != SUCESSO)
        retorno = POSICAO_INVALIDA;

    else
    {
        posicao--;

        Auxiliar *aux = &vetorPrincipal[posicao];

        if (aux->vetor == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;

        else
        {
            // Pegar os elementos de vetor e jogar em vetorAux
            for (int i = 0; i < aux->qtdElementos; i++)
                vetorAux[i] = aux->vetor[i];

            // Bubble Sort - Para ordenar
            for (int i = 0; i < aux->qtdElementos - 1; i++)
            {
                for (int j = 0; j < aux->qtdElementos - 1 - i; j++)
                {
                    if (vetorAux[j] > vetorAux[j + 1])
                    {
                        int temp = vetorAux[j];
                        vetorAux[j] = vetorAux[j + 1];
                        vetorAux[j + 1] = temp;
                    }
                }
            }

            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int vazio = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0)
            vazio = 0;
    }

    if (vazio)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    else
    {
        int posicaoAtual = 0;

        for (int i = 0; i < TAM; i++)
        {
            Auxiliar *aux = &vetorPrincipal[i];

            for (int j = 0; j < aux->qtdElementos; j++)
            {
                vetorAux[posicaoAtual] = aux->vetor[j];
                posicaoAtual++;
            }
        }

        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int vazio = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0)
            vazio = 0;
    }

    if (vazio)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    else
    {
        int posicaoAtual = 0;

        for (int i = 0; i < TAM; i++)
        {
            Auxiliar *aux = &vetorPrincipal[i];

            for (int j = 0; j < aux->qtdElementos; j++)
            {
                vetorAux[posicaoAtual] = aux->vetor[j];
                posicaoAtual++;
            }
        }

        for (int i = 0; i < posicaoAtual - 1; i++)
        {
            for (int j = 0; j < posicaoAtual - 1 - i; j++)
            {
                if (vetorAux[j] > vetorAux[j + 1])
                {
                    int temp = vetorAux[j];
                    vetorAux[j] = vetorAux[j + 1];
                    vetorAux[j + 1] = temp;
                }
            }
        }

        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    int invalido = ehPosicaoValida(posicao);

    if (invalido != SUCESSO)
        return POSICAO_INVALIDA;

    else
    {
        posicao--;

        Auxiliar *vetorAux = &vetorPrincipal[posicao];

        if (vetorAux->vetor == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;
        else
        {
            int tamanhoFinal = vetorAux->tamanho + novoTamanho;

            if (tamanhoFinal < 1)
                retorno = NOVO_TAMANHO_INVALIDO;
            else
            {
                int *aux = realloc(vetorAux->vetor, tamanhoFinal * sizeof(int));

                if (aux == NULL)
                    retorno = SEM_ESPACO_DE_MEMORIA;
                else
                {
                    vetorAux->vetor = aux;
                    vetorAux->tamanho = tamanhoFinal;

                    if (novoTamanho < 0)
                        vetorAux->qtdElementos += novoTamanho;

                    retorno = SUCESSO;
                }
            }
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    posicao--;

    Auxiliar *aux = &vetorPrincipal[posicao];

    if (aux->vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->qtdElementos == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return aux->qtdElementos;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No *montarListaEncadeadaComCabecote()
{
    int empty = 1;
    for(int i = 0; i < TAM; i++)
    {
        if(vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0)
        {
            empty = 0;
        }
    }

    if(empty)
        return NULL;
    else
    {
        No *cabecote = malloc(sizeof(No));
        cabecote->prox = NULL;

        No *atual = cabecote;
        
        for(int i = 0; i < TAM; i++)
        {
            if(vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0)
            {
                Auxiliar *aux = &vetorPrincipal[i];
                
                for(int j = 0; j < aux->qtdElementos; j++)
                {
                    No *novo = malloc(sizeof(No));
                    novo->conteudo = aux->vetor[j];
                    novo->prox = NULL;
    
                    atual->prox = novo;
                    atual = novo;
                }
            }
            
        }

        return cabecote;
    }

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio->prox;
    int i = 0;

    while(atual != NULL)
    {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *atual = *inicio;
    No *prox;

    while(atual != NULL)
    {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    for (int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].vetor = NULL;
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].qtdElementos = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetor)
        {
            free(vetorPrincipal[i].vetor);
            vetorPrincipal[i].tamanho = 0;
            vetorPrincipal[i].qtdElementos = 0;
        }
    }
}