#include "validacoes.h"
#include "aluno.h"

// ANO ATUAL //

int anoAtual(){
    time_t set_time = time(NULL);
    struct tm t = *localtime(&set_time);

    return t.tm_year + 1900;
}

// VALIDAR DATA //

int validarData(int dia, int mes, int ano){
    if(dia < 1 || dia > 31) return 0;

    if(mes < 1 || mes > 12) return 0;

    if(ano < 1900 || ano > anoAtual()) return 0;

    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > 30) return 0;
    }

    if(mes == 2){
        int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

        if(bissexto){
            if(dia > 29) return 0;
        } else {
            if(dia > 28) return 0;
        }
    }

    return 1;
}

// DATA DE NASCIMENTO //

void dataNascimento(Aluno lista_aluno[], int indice){
    int dia, mes, ano;

    while(1){
        scanf("%d/%d/%d", &dia, &mes, &ano);

        if(!validarData(dia, mes, ano)){
            printf("Data digitada inválida. Tente novamente!\n");
            continue;
        }

        lista_aluno[indice].dtNascimento.dia = dia;
        lista_aluno[indice].dtNascimento.mes = mes;
        lista_aluno[indice].dtNascimento.ano = ano;

        break;
    }
}

// VALIDAR CPF //

int validarCpf(char cpf[]){
    if(strlen(cpf) != 11) return 0;

    int cpf_igual = 1;

    for(int i = 0; i < 11; i++){
        if(cpf[i] != cpf[0]){
            cpf_igual = 0;
            break;
        }
    }

    if(cpf_igual) return 0;

    int soma = 0;
    int resto;

    // Verificação do primeiro digito
    for(int i = 0; i < 9; i++){
        soma += (cpf[i] - '0') * (10 - i);
    }

    resto = soma % 11;

    int primeiroDig = (resto < 2) ? 0 : 11 - resto;

    if(primeiroDig != (cpf[9] - '0')) return 0;

    // Verificação segundo digito //

    for(int i = 0; i < 10; i++){
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = soma % 11;

    int segundoDig = (resto < 2) ? 0 : 11 - resto;

    if(segundoDig != (cpf[10] - '0')) return 0;

    return 1;
}