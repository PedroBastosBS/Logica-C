#include <stdio.h>

int fetuccine(int numeroInfo, int primeiroTermoInfo, int segundoTermoInfo) {
    int proximoTermoGerado;

    if(numeroInfo < 3) {
        printf("Numero precisa ser maior ou igual a 3.\n");
        return 0;
    }

    printf("%d, %d", primeiroTermoInfo, segundoTermoInfo);

    for (int i = 3; i <= numeroInfo; i++) {
        if(i % 2 == 0) {
            proximoTermoGerado = primeiroTermoInfo - segundoTermoInfo;
        } else {
            proximoTermoGerado = primeiroTermoInfo + segundoTermoInfo;
        }
        printf("%d", proximoTermoGerado);

        if(i < numeroInfo) {
            printf(", ");
        }

        primeiroTermoInfo = segundoTermoInfo;
        segundoTermoInfo = proximoTermoGerado;
    }
    printf("\n");
    return 0;
}

int main() {
    int numero;
    int atributoPrimario, atributoSegundario;

    printf("Digite um valor inteiro para Numero: ");
    scanf("%d", &numero);

    printf("Digite o primeiro termo: ");
    scanf("%d", &atributoPrimario);
    printf("Digite o segundo termo: ");
    scanf("%d", &atributoSegundario);

    fetuccine(numero, atributoPrimario, atributoSegundario);

    return 0;
}