#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

void insercao_ordenada(int vetor[], int tamanho, int valor) {
    if (tamanho >= MAX_SIZE) {
        printf("O vetor está cheio.\n");
        return;
    }

    int i;
    for (i = tamanho - 1; i >= 0 && vetor[i] > valor; i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;

    printf("Valor inserido ordenadamente.\n");
}

void insercao_automatica(int vetor[], int *tamanho) {
    while (*tamanho < MAX_SIZE) {
        int valor = rand() % 1000 + 1;
        insercao_ordenada(vetor, *tamanho, valor);
        (*tamanho)++;
    }
}

void remocao(int vetor[], int *tamanho, int valor) {
    int i;
    bool encontrado = false;
    for (i = 0; i < *tamanho; i++) {
        if (vetor[i] == valor) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < *tamanho - 1; j++) {
            vetor[j] = vetor[j + 1];
        }
        (*tamanho)--;
        printf("Valor removido com sucesso.\n");
    } else {
        printf("Valor não encontrado no vetor.\n");
    }
}

void zerar_vetor(int vetor[], int *tamanho) {
    *tamanho = 0;
    printf("Vetor zerado com sucesso.\n");
}

void busca_sequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        printf("Posição visitada: %d\n", i);
        if (vetor[i] == valor) {
            printf("Valor encontrado na posição %d\n", i);
            return;
        }
    }
    printf("Valor não encontrado no vetor.\n");
}

void busca_sequencial_dupla(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        printf("Posição visitada: %d\n", inicio);
        if (vetor[inicio] == valor) {
            printf("Valor encontrado na posição %d\n", inicio);
            return;
        }
        printf("Posição visitada: %d\n", fim);
        if (vetor[fim] == valor) {
            printf("Valor encontrado na posição %d\n", fim);
            return;
        }
        inicio++;
        fim--;
    }

    printf("Valor não encontrado no vetor.\n");
}

void busca_sequencial_sentinela(int vetor[], int tamanho, int valor) {
    vetor[tamanho] = valor;
    int i = 0;

    while (vetor[i] != valor) {
        printf("Posição visitada: %d\n", i);
        i++;
    }

    if (i < tamanho) {
        printf("Valor encontrado na posição %d\n", i);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }
}

void busca_ordenada(int vetor[], int tamanho, int valor) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        printf("Posição visitada: %d\n", meio);
        if (vetor[meio] == valor) {
            printf("Valor encontrado na posição %d\n", meio);
            return;
        } else if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    printf("Valor não encontrado no vetor.\n");
}

void busca_binaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        printf("Posição visitada: %d\n", meio);
        if (vetor[meio] == valor) {
            printf("Valor encontrado na posição %d\n", meio);
            return;
        } else if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    printf("Valor não encontrado no vetor.\n");
}

void imprimir_valor_posicao(int vetor[], int tamanho, int posicao) {
    if (posicao >= 0 && posicao < tamanho) {
        printf("Valor na posição %d: %d\n", posicao, vetor[posicao]);
    } else {
        printf("Posição inválida.\n");
    }
}

void listar_valores(int vetor[], int tamanho) {
    printf("Situação atual do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[MAX_SIZE];
    int tamanho = 0;
    srand(time(NULL));

    int opcao;
    int valor;
    int posicao;

    do {
        printf("\nMenu:\n");
        printf("1 - Inserção Ordenada\n");
        printf("2 - Inserção Automática\n");
        printf("3 - Remoção\n");
        printf("4 - Zerar Vetor\n");
        printf("5 - Busca Sequencial\n");
        printf("6 - Busca Sequencial Dupla\n");
        printf("7 - Busca Sequencial com Sentinela\n");
        printf("8 - Busca Ordenada\n");
        printf("9 - Busca Binária\n");
        printf("10 - Imprimir Valor de Posição\n");
        printf("11 - Listar Valores\n");
        printf("12 - Sair do Programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insercao_ordenada(vetor, tamanho, valor);
                tamanho++;
                break;
            case 2:
                insercao_automatica(vetor, &tamanho);
                break;
            case 3:
            printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remocao(vetor, &tamanho, valor);
                break;
            case 4:
                zerar_vetor(vetor, &tamanho);
                break;
            case 5:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca_sequencial(vetor, tamanho, valor);
                break;
            case 6:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca_sequencial_dupla(vetor, tamanho, valor);
                break;
            case 7:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca_sequencial_sentinela(vetor, tamanho, valor);
                break;
            case 8:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca_ordenada(vetor, tamanho, valor);
                break;
            case 9:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                busca_binaria(vetor, tamanho, valor);
                break;
            case 10:
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                imprimir_valor_posicao(vetor, tamanho, posicao);
                break;
            case 11:
                listar_valores(vetor, tamanho);
                break;
            case 12:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 12);

    return 0;
}