#include <stdio.h>
#include <string.h>

#define MAX_FILA 20

// Definição da estrutura Cliente
struct Cliente {
    char nome[50];
    int idade;
};

// Função para enfileirar um cliente na fila
void enfileirar(struct Cliente fila[], struct Cliente cliente, int *tamanho) {
    if (*tamanho < MAX_FILA) {
        for (int i = *tamanho; i > 0; i--) {
            fila[i] = fila[i - 1];
        }

        fila[0] = cliente;
        (*tamanho)++;
    } else {
        printf("Fila de atendimento está cheia!\n");
    }
}

// Função para desenfileirar um cliente da fila
void desenfileirar(struct Cliente fila[], int *tamanho) {
    if (*tamanho > 0) {
        printf("Atendendo cliente: %s (idade %d)\n", fila[*tamanho - 1].nome, fila[*tamanho - 1].idade);
        for (int i = *tamanho - 1; i > 0; i--) {
            fila[i] = fila[i - 1];
        }
        (*tamanho)--;
    } else {
        printf("Fila de atendimento está vazia!\n");
    }
}

// Função para listar os clientes na fila
void listarClientes(struct Cliente fila[], int tamanho) {
    printf("Lista de indivíduos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Idade: %d\n", fila[i].nome, fila[i].idade);
    }
}

// Função principal
int main() {
    struct Cliente fila[MAX_FILA];
    int tamanhoFila = 0;
    int opcao;

    do {
        printf("\nMENU DE OPÇÕES:\n");
        printf("1 - Novo atendimento\n");
        printf("2 - Atendimento realizado\n");
        printf("3 - Listar indivíduos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct Cliente novoCliente;
                printf("Nome do cliente: ");
                scanf("%s", novoCliente.nome);
                printf("Idade do cliente: ");
                scanf("%d", &novoCliente.idade);

                if (novoCliente.idade >= 60) {
                    enfileirar(fila, novoCliente, &tamanhoFila);
                } else {
                    enfileirar(fila, novoCliente, &tamanhoFila);
                }
                break;
            }
            case 2:
                desenfileirar(fila, &tamanhoFila);
                break;
            case 3:
                listarClientes(fila, tamanhoFila);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
