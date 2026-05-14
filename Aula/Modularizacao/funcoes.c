#include <stdio.h>

typedef struct pessoa{
    char nome[100];
    int idade;
    char cpf;
}pessoa;

typedef struct carro{
    char marca[100];
    char modelo[100];
    int ano;
}carro;

char asteristico(){
    for(int i = 0; i < 20; i++){
        printf("*");
    }
}

int main(){

asteristico();

}

