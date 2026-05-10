/*

Faça uma função que receba uma string principal e uma palavra de busca. A função deve:

Remover todos os caracteres especiais '@' da string principal antes da busca;
Encontrar todas as ocorrências consecutivas da palavra de busca dentro da string tratada;
Retornar:
a quantidade total de ocorrências;
e armazenar em um vetor as posições inicial e final de cada ocorrência encontrada.

Considere que as posições começam em 1.
*/

#include<string.h>
#include<stdio.h>

void removerCaracter(char texto[], char caracter) {
    int j = 0;
    for(int i = 0; i < strlen(texto); i++){
        if(texto[i] != caracter){
            texto[j] = texto[i];
            j++;
        }
    }

    texto[j] = '\0';
}

void qtdOcorrencias(char texto[], char ocorrencia[], int posicao[30]) {
    int pos = 0;
    for(int i = 0; i < strlen(texto); i++){
        if(texto[i] == ocorrencia[0]){
            int qtd = 1;
            for(int j = 1; j < strlen(ocorrencia); j++){
                if(texto[i + j] != ocorrencia[j]){
                    break;
                }
                qtd++;
            }

            if(qtd == strlen(ocorrencia)){
                posicao[pos] = i + 1;
                pos++;
                posicao[pos] = i + qtd;
                pos++;
            }
        }
    }
}

void printPos(int posicao[30]){
    for(int i = 0; posicao[i] != 0; i++){
        printf("[%d]\n", posicao[i]);
    }
}

int main() {
    char texto[] = "pro@grama@cao";
    char caracter = '@';
    char ocorrencia[] = "grama";
    int posicao[30] = {0};

    printf("%s\n", texto);

    removerCaracter(texto, caracter);

    qtdOcorrencias(texto, ocorrencia, posicao);

    printf("%s\n", texto);
    printPos(posicao);

    return 0;
}
