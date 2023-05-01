#include <stdio.h>

double euler(int n) {
    if (n == 0) {
        return 1.0; // valor inicial da série
    } else {
        return 1.0/fatorial(n) + euler(n-1); // cálculo recursivo da série
    }
}

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n*fatorial(n-1); // cálculo recursivo do fatorial
    }
}

int main() {
    int n;
    printf("Digite a quantidade de termos da série: ");
    scanf("%d", &n);
    double e = euler(n);
    printf("Valor aproximado da constante de Euler: %lf\n", e);
    return 0;
}
