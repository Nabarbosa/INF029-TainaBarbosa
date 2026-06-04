// Percorrendo o vetor com ponteiros

#include <stdio.h>

int main(){
    int vetor[5] = {1 , 2 , 3, 4, 5};
    int *p = vetor;

    // printf("\n%d", *p);
    // printf("\n%d", *(p + 1));
    // printf("\n%d", *(p + 2));
    // printf("\n%d", *(p + 3));
    // printf("\n%d", *(p + 4));

    for(int i = 0; i < 5; i++){
        printf("\n%d", *p + i);
    }
    
    return 0;
}