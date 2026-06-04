// Troca de valores

#include <stdio.h>

void troca(int *a, int *b){
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}

int main(){
    int a = 10;
    int b = 20;

    printf("\n%d , %d", a, b);
    
    troca(&a, &b);

    printf("\n%d , %d", a, b);

    return 0;
}