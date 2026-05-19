#include <stdio.h>

int ehTriangulo(int x, int y, int z);
int verificarVaretas(int varetas[4]);
int validaEntrada(int intVaretas[4]);
void menu();

int main(){
    int intVaretas[4];
    int opcao;

    menu();
    scanf("%d", &opcao);
    while(getchar() != '\n');

    switch (opcao){
        case 1:
            printf("Informe os tamanhos das varetas separadas por '-': ");
            
            int resultado = validaEntrada(intVaretas);
            
            if(resultado == 0){
                printf("Entrada invalida! Valores devem estar entre 1 e 100.\n");
            } else if(resultado == -1){
                printf("Nao forma triangulo com nenhuma combinacao.\n");
            } else {
                printf("Forma triangulo com a combinacao %d.\n", resultado);
            }
            break;
        
        case 2:
            printf("\n=== Sair ===\n");
            break;
        
        default:
            printf("Opcao invalida.\n");
            break;
    }
    
    return 0;
}

int ehTriangulo(int x, int y, int z){
    if(x < (y + z) && y < (x + z) && z < (x + y)){
        return 1;
    }
    return 0;
}

int verificarVaretas(int varetas[4]){
    if(ehTriangulo(varetas[0], varetas[1], varetas[2])) return 1;
    if(ehTriangulo(varetas[0], varetas[1], varetas[3])) return 2;
    if(ehTriangulo(varetas[0], varetas[2], varetas[3])) return 3;
    if(ehTriangulo(varetas[1], varetas[2], varetas[3])) return 4;

    return -1; 
}

int validaEntrada(int intVaretas[4]){
    char buffer[50];
    int i = 0;
    int hifen = 0;

    intVaretas[0] = intVaretas[1] = intVaretas[2] = intVaretas[3] = 0;

    fgets(buffer, 50, stdin);

    while(buffer[i] != '\0' && buffer[i] != '\n'){
        if(buffer[i] == '-'){
            hifen++;
        } else if(buffer[i] >= '0' && buffer[i] <= '9') {
            intVaretas[hifen] = intVaretas[hifen] * 10 + (buffer[i] - '0');
        }
        i++;
    }

    if(intVaretas[0] < 1 || intVaretas[0] > 100 ||
       intVaretas[1] < 1 || intVaretas[1] > 100 ||
       intVaretas[2] < 1 || intVaretas[2] > 100 ||
       intVaretas[3] < 1 || intVaretas[3] > 100){
        return 0; 
    }

    return verificarVaretas(intVaretas);
}

void menu(){
    printf("\nMenu\n");
    printf("1. Verificar varetas\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
}




