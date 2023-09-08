#include <stdio.h>

int main() {
    int trajetorias[9] = {5, 7, 6, 9, 2, 8, 4, 0, 3}; // vetor de trajet�rias
    int indice_atual = 0; // �ndice atual para leitura do vetor
    int valor_atual; // valor atual do elemento sendo lido

    // Loop para imprimir os valores na sequ�ncia especificada
    for (int i = 0; i < 9; i++) {
        valor_atual = trajetorias[indice_atual];
        printf("%d ", valor_atual);
        indice_atual = valor_atual - 1; // atualiza o �ndice para o pr�ximo elemento
    }

    return 0;
}
