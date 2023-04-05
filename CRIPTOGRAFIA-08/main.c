#include <stdio.h>

int criptografar(int numero) {
    int digito, criptografado = 0;
    int multiplos = 1;

    while (numero > 0) {
        digito = (numero % 10 + 7) % 10;
        criptografado += multiplos * digito; 
        multiplos *= 10;
        numero /= 10;
    }

    criptografado = (criptografado % 1000) * 1000 + (criptografado / 1000);
    return criptografado;
}


int descriptografar(int numero) {
    int digito, descriptografado = 0;
    int mult = 1;

    numero = (numero % 1000) * 1000 + (numero / 1000);

    while (numero > 0) {
        digito = (numero % 10 + 3) % 10;
        descriptografado += mult * digito;
        mult *= 10;
        numero /= 10; 
    }

    return descriptografado;
}


int main() {
    int opcao, numero;
    printf("Menu:\n1. Criptografar\n2. Descriptografar\n3. Sair\n");

    do {
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero a ser criptografado: ");
                scanf("%d", &numero);
                printf("Numero criptografado: %d\n", criptografar(numero));
                break;
            case 2:
                printf("Digite o numero criptografado: ");
                scanf("%d", &numero);
                printf("Numero descriptografado: %d\n", descriptografar(numero));
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}