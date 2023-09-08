#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Definindo os vetores A, B, C e D
    int A[5], B[5], C[5], D[15];

    // Inicializando o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Inserção automática e aleatória de elementos nos vetores A, B e C
    for (int i = 0; i < 5; i++) {
        A[i] = rand() % 100 + 1;
        B[i] = rand() % 100 + 1;
        C[i] = rand() % 100 + 1;
    }

    // Inserção dos valores dos vetores A, B e C no vetor D de forma alternada
    for (int i = 0; i < 15; i++) {
        if (i % 3 == 0) {
            D[i] = A[i / 3];
        } else if (i % 3 == 1) {
            D[i] = B[i / 3];
        } else {
            D[i] = C[i / 3];
        }
    }

    // Impressão dos vetores A, B, C e D na tela
    printf("Vetor A: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    printf("Vetor C: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("Vetor D: ");
    for (int i = 0; i < 15; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");

    return 0;
}
