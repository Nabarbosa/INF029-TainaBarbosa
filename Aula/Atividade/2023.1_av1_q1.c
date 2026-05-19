#include <stdio.h>

float calcular(int a, int b){
    float div;
    float soma = a + b;
    float sub = a - b;
    float mult = a * b;

    if(b == 0){
        printf("Nao se divide por 0");
    } else {
        float div = a / b;
    }

    printf("Soma: %d + %d = %.2f\n", a ,b ,soma);
    printf("Subtracao: %d + %d = %.2f\n", a, b, sub);
    printf("Multiplicacao: %d + %d = %.2f\n", a, b, mult);
    printf("Divisao: %d + %d = %.2f\n", a, b, div);
}

int main() {
    float a = 10;
    float b = 5;
    
    calcular(a, b);
}