#include <stdio.h>

int contaDigitos(int n, int d) {
    int freq = 0;
    while (n > 0) {
        if (n % 10 == d) {
            freq++;
        }
        n /= 10;
    }
    return freq;
}

void contarFrequencia(int n, int freq[]) {
    while (n > 0) {
        freq[n % 10]++;
        n /= 10;
    }
}

int verificarPermutacao(int freqA[], int freqB[]) {
    for (int i = 0; i < 10; i++) {
        if (freqA[i] != freqB[i]) {
            return 0; // não são permutações
        }
    }
    return 1; // são permutações
}

int main() {
    int a, b;
    int freqA[10] = {0}; // vetor para armazenar a frequência dos dígitos em a
    int freqB[10] = {0}; // vetor para armazenar a frequência dos dígitos em b

    printf("Digite dois numeros positivos: ");
    scanf("%d %d", &a, &b);

    contarFrequencia(a, freqA);
    contarFrequencia(b, freqB);

    if (verificarPermutacao(freqA, freqB)) {
        printf("Sao permutacoes\n");
    } else {
        printf("Nao sao permutacoes\n");
    }

    return 0;
}
