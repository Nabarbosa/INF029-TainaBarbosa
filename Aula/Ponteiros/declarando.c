// Declarando ponteiros

#include <stdio.h>

int main(){
    int x = 10;
    printf("\nValor de x: %d", x);

    int *p = &x;
    *p = 8;

    printf("\nEndereço de x: %p", &x);
    printf("\nValor de p: %p", p);
    printf("\nValor apontado por p: %d", *p);

    return 0;
}