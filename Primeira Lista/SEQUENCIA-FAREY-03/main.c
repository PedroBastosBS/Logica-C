#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n, i, j;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    printf("Sequência de Farey relativa a %d:\n", n);
    printf("0/1");

    for (i = 1; i <= n; i++) {
        for (j = i+1; j <= n; j++) {
            if (gcd(i, j) == 1) {
                printf(", %d/%d", i, j);
            }
        }
    }

    printf(", 1/1\n");

    return 0;
}
