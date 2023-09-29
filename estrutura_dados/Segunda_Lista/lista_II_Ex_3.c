#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura de nó para a pilha
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a fatoração prima de um número
void primeFactors(int n) {
    struct Node* stack = NULL;

    // Encontre todos os divisores 2
    while (n % 2 == 0) {
        stack = createNode(2);
        n /= 2;
    }

    // Encontre os outros fatores primos
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            stack = createNode(i);
            n /= i;
        }
    }

    // Se o número restante for maior que 2, é primo
    if (n > 2) {
        stack = createNode(n);
    }

    // Imprimir os fatores primos em ordem crescente
    printf("Fatoração prima: ");
    while (stack != NULL) {
        printf("%d", stack->data);
        if (stack->next != NULL) {
            printf(" * ");
        }
        stack = stack->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite um número inteiro maior que 1: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Por favor, insira um número maior que 1.\n");
        return EXIT_FAILURE;
    }

    primeFactors(n);

    return 0;
}
