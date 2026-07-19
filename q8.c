#include <stdio.h>
#define TAM 3

void iniciarTabuleiro(char tabuleiro[TAM][TAM]);
void mostrarTabuleiro(char tabuleiro[TAM][TAM]);
int jogadaValida(char tabuleiro[TAM][TAM], int l, int c);
int verificarVencedor(char tabuleiro[TAM][TAM]);

int main(){
    char tabuleiro[TAM][TAM];
    char jogada[TAM];
    int linha, coluna;
    int jogador = 1;
    int totalJogadas = 0;

    iniciarTabuleiro(tabuleiro);

    while(totalJogadas < 9){

        mostrarTabuleiro(tabuleiro);

        printf("Jogador %d (%c), Informe a sua jogada: ", 
            jogador, jogador == 1 ? 'X' : 'O');
        scanf("%s", jogada);

        if(jogada[0] >= 'a' && jogada[0] <= 'z'){
            jogada[0] -= 32;
        }

        linha = jogada[0] - 'A';
        coluna = jogada[1] - '1';

        if(!jogadaValida(tabuleiro, linha, coluna)){
            printf("Jogada Inválida!!");
            continue;
        }

        if(jogador == 1){
            tabuleiro[linha][coluna] = 'X';
        } else {
            tabuleiro[linha][coluna] = 'O';
        }

        totalJogadas++;

        if(verificarVencedor(tabuleiro)){
            mostrarTabuleiro(tabuleiro);
            printf("Jogador nº %d Você Venceu !!!\n", jogador);
            return 0;
        }

        jogador = (jogador == 1) ? 2 : 1;    
    }

    mostrarTabuleiro(tabuleiro);
    printf("EMPATE!!\n");

    return 0;
}



void iniciarTabuleiro(char tabuleiro[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiro(char tabuleiro[TAM][TAM]){
    printf("\n   1   2   3\n");
    printf("A  %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  ---|---|---\n");
    printf("B  %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  ---|---|---\n");
    printf("C  %c | %c | %c\n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int jogadaValida(char tabuleiro[TAM][TAM], int l, int c){
    if(l < 0 || l > 2 || c < 0 || c > 2){
        return 0;
    } 

    if(tabuleiro[l][c] != ' '){
        return 0;
    }

    return 1;
}

int verificarVencedor(char tabuleiro[TAM][TAM]){
    int i;

    for(i = 0; i < TAM; i++){
        if(tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2] &&
            tabuleiro[i][0] != ' ') return 1;

        if(tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i] &&
            tabuleiro[0][i] != ' ') return 1;
    }

    if(tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2] &&
        tabuleiro[0][0] != ' ') return 1;

    if(tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0] &&
        tabuleiro[0][2] != ' ') return 1;

    return 0;
}


