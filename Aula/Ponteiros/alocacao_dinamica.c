// Alocação de memória

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    int *v = malloc(n * sizeof(int));

    printf("Informe o valor de n: ");
    scanf("%d", &n);

    printf("Informe os valores: ");
    for(int i = 0; i < n; i++){
        scanf("%d", v);
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", *v);
    }

    int novoTam;

    int *v = realloc(v, novoTam * sizeof(int));
    
    printf("Informe o novo valor: ");
    scanf("%d", &novoTam);

    printf("Informe os valores: ");
    for(int i = 0; i < novoTam; i++){
        scanf("%d", v);
    }

    for(int i = 0; i < novoTam; i++){
        printf("%d\n", *v);
    }

    return 0;
}