#include <stdio.h>

int main() {
    int n, i;
    double phi = 1.0;

    printf("Digite o numero de termos a serem usados no calculo de phi: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {     // quantidade de vezes da iteração
        phi = 1.0 + (1.0 / phi); // acrescenta 1 a divisao de 1 por phi
    }
    printf("O valor aproximado de phi com %d termos e: %f\n", n, phi);

    return 0;
}
