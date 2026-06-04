#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float nota1;
    float nota2;
}Aluno;

float media(Aluno *aluno){
    float media = (aluno->nota1 + aluno->nota2) / 2;

    return media;
}

int main(){
    Aluno *aluno = malloc(5 * sizeof(Aluno));
    float m[5];

    for(int i = 0; i < 5; i++){
        printf("\nDigite o seu nome: ");
        scanf("%s", aluno->nome);

        printf("\nDigite a sua primeira nota: ");
        scanf("%f", &aluno->nota1);

        printf("\nDigite a sua segunda nota: ");
        scanf("%f", &aluno->nota2);

        m[i] = media(aluno);

    }

    for(int i = 0; i < 5; i++){
        printf("\n--- %dº Aluno ---\n", i + 1);
        printf("\nNome: %s", aluno->nome);
        printf("\nPrimeira nota: %.2f", aluno->nota1);
        printf("\nSegunda nota: %.2f", aluno->nota2);
        printf("\nMédia do Aluna(o)\: %.2f", m[i]);
    }

    

    return 0;
}