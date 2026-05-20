/*
    1) Crie um programa que tenha um vetor de caracteres. Esse vetor deve ter um tamanho máximo
    TAM = 10. Nenhum parâmetro pode ser global. Utilize boas práticas de modularização.
    O programa deve ter:

    a. a função main, responsável por interagir com o usuário, informando os resultados das operações
    das demais funções

    b. uma função “insere caractere”. Ela deve solicitar o caractere ao usuário, e inserir no vetor, na
    primeira posição vazia, se ainda tiver espaço. Deve retornar se foi inserido ou não.

    c. Uma função “troca caractere”. Essa função solicita um novo caractere ao usuário. A função deve
    procurar no vetor o primeiro caractere que é maior que o caractere informado, quando achar, fazer
    a troca. A função deve retornar se houve a troca ou não. Quando houver a troca, a função principal
    (main) deve ser capaz de imprimir qual foi o caractere que saiu do vetor.

    d. Uma função para remover caracteres. A remoção deve ser lógica, no final do vetor. Basta nesse
    caso decrementar o topo.

    e. Uma função para listar os caracteres.

    f. uma função que imprime cada um dos caracteres distintos e a quantidade de vezes que ele
    aparece no vetor
*/

#include <stdio.h>
#define TamVetor 10

int  inserirCaracter(char vetor[], int *topo, char caracter);
char trocaCaracter(char vetor[], int  topo, char caracter);
void removerCaracter(int *topo);
void listarCaracter(char vetor[], int  topo);
void caracteresDistintos(char vetor[], int  topo);


int main() {
    char vetor[TamVetor] = {'a', 'b', 'b', 'd', 'e'};
    int  topo = 5;  
    char caracter;

    /* ── INSERIR ─────────────────────────────────────────────── */
    printf("Informe o caractere que deseja inserir: ");
    scanf(" %c", &caracter);

    int inserido = inserirCaracter(vetor, &topo, caracter);

    if (inserido)
        printf("Caractere '%c' inserido. Topo: %d\n", caracter, topo);
    else
        printf("Vetor cheio. Caractere nao inserido.\n");

    /* ── TROCAR ──────────────────────────────────────────────── */
    printf("\nInforme o caractere para troca: ");
    scanf(" %c", &caracter);

    char saiu = trocaCaracter(vetor, topo, caracter);

    if (saiu == '\0')
        printf("Nenhum caractere maior encontrado. Sem troca.\n");
    else
        printf("Houve troca. Caractere que saiu: '%c'\n", saiu);

    /* ── LISTAR ──────────────────────────────────────────────── */
    printf("\nCaracteres no vetor: ");
    listarCaracter(vetor, topo);

    /* ── DISTINTOS ───────────────────────────────────────────── */
    printf("\nCaracteres distintos:\n");
    caracteresDistintos(vetor, topo);

    /* ── REMOVER ─────────────────────────────────────────────── */
    removerCaracter(&topo);
    printf("\nApos remocao logica. Topo: %d\n", topo);

    printf("\nCaracteres apos remocao: ");
    listarCaracter(vetor, topo);

    return 0;
}


int inserirCaracter(char vetor[], int *topo, char caracter) {
    if (*topo >= TamVetor)
        return 0;         

    vetor[*topo] = caracter;
    (*topo)++;
    return 1;
}


char trocaCaracter(char vetor[], int topo, char caracter) {
    for (int i = 0; i < topo; i++) {
        if (vetor[i] > caracter) {
            char saiu = vetor[i];
            vetor[i]  = caracter;
            return saiu;
        }
    }
    return '\0';
}


void removerCaracter(int *topo) {
    if (*topo > 0)
        (*topo)--;
    else
        printf("Vetor ja esta vazio.\n");
}

void listarCaracter(char vetor[], int topo) {
    if (topo == 0) {
        printf("(vazio)\n");
        return;
    }
    for (int i = 0; i < topo; i++)
        printf("[%c] ", vetor[i]);
    printf("\n");
}

void caracteresDistintos(char vetor[], int topo) {
    if (topo == 0) {
        printf("Vetor vazio.\n");
        return;
    }

    int visto[TamVetor] = {0};  

    for (int i = 0; i < topo; i++) {
        if (visto[i]) continue;

        int qtd = 1;
        visto[i] = 1;

        for (int j = i + 1; j < topo; j++) {
            if (vetor[j] == vetor[i]) {
                qtd++;
                visto[j] = 1;   
            }
        }
        printf("'%c' - %d vez(es)\n", vetor[i], qtd);
    }
}