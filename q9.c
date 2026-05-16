#include <stdio.h>

#define QTD_NAVIOS 2
#define TAM_TAB 10

void mostrarTab(char tab[TAM_TAB][TAM_TAB]);
void iniciarTab(char tab[TAM_TAB][TAM_TAB]);
int posicaoNavioValida(int l, int c);
void inserirNavios(char tabJogador[TAM_TAB][TAM_TAB]);
void transformarEmChar(int linha, int coluna);

int main(){
    char tabJogador1[TAM_TAB][TAM_TAB];

    iniciarTab(tabJogador1);
    mostrarTab(tabJogador1);    

    inserirNavios(tabJogador1);

    mostrarTab(tabJogador1);
}

void iniciarTab(char tab[TAM_TAB][TAM_TAB]){
    for(int i = 0; i < TAM_TAB; i++){
        for(int j = 0; j < TAM_TAB; j++){
            tab[i][j] = ' ';
        }
    }
}

void mostrarTab(char tab[TAM_TAB][TAM_TAB]){
    printf("\n");
    printf("\n   1   2   3   4   5   6   7   8   9   10\n");
    printf("A  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[0][0], tab[0][1], tab[0][2], tab[0][3], tab[0][4], tab[0][5], tab[0][6], tab[0][7], tab[0][8], tab[0][9]);
    printf("------------------------------------------\n");
    printf("B  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[1][0], tab[1][1], tab[1][2], tab[1][3], tab[1][4], tab[1][5], tab[1][6], tab[1][7], tab[1][8], tab[1][9]);
    printf("------------------------------------------\n");
    printf("C  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[2][0], tab[2][1], tab[2][2], tab[2][3], tab[2][4], tab[2][5], tab[2][6], tab[2][7], tab[2][8], tab[2][9]);
    printf("------------------------------------------\n");
    printf("D  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[3][0], tab[3][1], tab[3][2], tab[3][3], tab[3][4], tab[3][5], tab[3][6], tab[3][7], tab[3][8], tab[3][9]);
    printf("------------------------------------------\n");
    printf("E  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[4][0], tab[4][1], tab[4][2], tab[4][3], tab[4][4], tab[4][5], tab[4][6], tab[4][7], tab[4][8], tab[4][9]);
    printf("------------------------------------------\n");
    printf("F  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[5][0], tab[5][1], tab[5][2], tab[5][3], tab[5][4], tab[5][5], tab[5][6], tab[5][7], tab[5][8], tab[5][9]);
    printf("------------------------------------------\n");
    printf("G  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[6][0], tab[6][1], tab[6][2], tab[6][3], tab[6][4], tab[6][5], tab[6][6], tab[6][7], tab[6][8], tab[6][9]);
    printf("------------------------------------------\n");
    printf("H  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[7][0], tab[7][1], tab[7][2], tab[7][3], tab[7][4], tab[7][5], tab[7][6], tab[7][7], tab[7][8], tab[7][9]);
    printf("------------------------------------------\n");
    printf("I  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", tab[8][0], tab[8][1], tab[8][2], tab[8][3], tab[8][4], tab[8][5], tab[8][6], tab[8][7], tab[8][8], tab[8][9]);
    printf("------------------------------------------\n");
    printf("J  %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n",tab[9][0], tab[9][1], tab[9][2], tab[9][3], tab[9][4], tab[9][5], tab[9][6], tab[9][7], tab[9][8], tab[9][9]); 
    printf("------------------------------------------\n");
    printf("\n");
}

void inserirNavios(char tabJogador[TAM_TAB][TAM_TAB]){
    int tam_navio = 0;
    int linha, coluna;
    int totalNavios = 0;
    char jogada[TAM_TAB];
    int direcao = 0;

    while(totalNavios < QTD_NAVIOS){
        printf("Informe o tamanho do navio: 1 - 2 - 3 - 4\n");
        scanf("%d", &tam_navio);

        if(tam_navio == 1){
            printf("Informe a posição do seu navio, jogador\n");
            scanf("%s", jogada);

            transformarEmChar(linha, coluna);

            if(!posicaoNavioValida(linha, coluna)){
                printf("Jogada Inválida!!");
                continue;
            }

            tabJogador[linha][coluna] = 'N';
            totalNavios++;

            continue;
        }

        printf("Informe a direção que seu navio irá ficar, - 1 para cima, - 2 para baixo, - 3 para a direita, - 4 para a esquerda:\n");
        scanf("%d", &direcao);

        switch(direcao){   
            // CIMA
            case 1:

                printf("Informe a posição do seu navio, jogador\n");
                scanf("%s", jogada);

                transformarEmChar(linha, coluna);

                if(linha - tam_navio + 1 < 0){
                    printf("Navio maior que o limite!\n");
                    continue;
                }

                if(!posicaoNavioValida(linha, coluna)){
                    printf("Jogada Inválida!!");
                    continue;
                }
                
                for(int k = linha + tam_navio; k > linha; k--){
                    tabJogador[k][coluna] = 'N';
                }

                totalNavios++;
                
                break;
            
            // BAIXO
            case 2:

                printf("Informe a posição do seu navio, jogador\n");
                scanf("%s", jogada);

                transformarEmChar(linha, coluna);

                if(linha + tam_navio > TAM_TAB){
                    printf("Navio maior que o limite!\n");
                    continue;
                }
                
                if(!posicaoNavioValida(linha, coluna)){
                    printf("Jogada Inválida!!");
                    continue;
                }

                for(int k = linha; k < linha + tam_navio; k++){
                    tabJogador[k][coluna] = 'N';
                }

                totalNavios++;
                
                break;

            // DIREITA
            case 3:

                printf("Informe a posição do seu navio, jogador\n");
                scanf("%s", jogada);

                transformarEmChar(linha, coluna);

                if(coluna + tam_navio > TAM_TAB){
                    printf("Navio maior que o limite!\n");
                    continue;
                }

                if(!posicaoNavioValida(linha, coluna)){
                    printf("Jogada Inválida!!");
                    continue;
                }

                for(int k = coluna; k < coluna + tam_navio; k++){
                    tabJogador[linha][k] = 'N';
                }

                totalNavios++;
                
                break;

            // ESQUERDA
            case 4:

                printf("Informe a posição do seu navio, jogador\n");
                scanf("%s", jogada);

                transformarEmChar(linha, coluna);

                if(coluna - tam_navio + 1 < 0){
                    printf("Navio maior que o limite!\n");
                    continue;
                }

                if(!posicaoNavioValida(linha, coluna)){
                    printf("Jogada Inválida!!");
                    continue;
                }

                for(int k = coluna + tam_navio; k > coluna; k--){
                    tabJogador[linha][k] = 'N';
                }

                totalNavios++;
                
                break;

            default:

        }
    }
}

void navioAbatido(char tabJogador[TAM_TAB][TAM_TAB], char navio){
    char jogada[TAM_TAB];
    int tiros = TAM_TAB * TAM_TAB;
    int linha, coluna;
    int i = 0;

    while(jogada < tiros * 2 || jogada < QTD_NAVIOS){
        printf("Informe em que posição deseja atirar: \n");
        scanf("%s", jogada);

        transformarEmChar(linha, coluna);

        if(!posicaoNavioValida(linha, coluna)){
            printf("Jogada Inválida!!");
        }

        if(jogada == 'N'){
            tabJogador[linha][coluna] = 'O';

            while(jogada == 'N'){
                printf("Informe em que posição deseja atirar: \n");
                scanf("%s", jogada);

                transformarEmChar(linha, coluna);

                if(!posicaoNavioValida(linha, coluna)){
                    printf("Jogada Inválida!!");
                }

                tabJogador[linha][coluna] = 'O';
            }

        } else {
            tabJogador[linha][coluna] = 'X';
        }
    }
}

int posicaoNavioValida(int l, int c){
    if(l < 0 || l > 9 || c < 0 || c > 9){
        return 0;
    }

    return 1;
}

void transformarEmChar(int linha, int coluna){
    char jogada[TAM_TAB];

    if(jogada[0] >= 'a' && jogada[0] <= 'z'){
        jogada[0] -= 32;
    }

    linha = jogada[0] - 'A';
    coluna = jogada[1] - '1';
}