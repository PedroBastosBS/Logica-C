#include <stdio.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() { // função cheio
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {// função vazio
    return front == -1;
}

void insertFront(int value) {// função inserir frente
    if (isFull()) {
        printf("Deque está cheio. Não é possível inserir.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Inserido %d no topo.\n", value);
    }
}

void insertRear(int value) {// função inserir atrás
    if (isFull()) {
        printf("Deque está cheio. Não é possível inserir.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Inserido %d no final.\n", value);
    }
}

void removeFront() {// funçaõ remover na frente
    if (isEmpty()) {
        printf("Deque está vazio. Não é possível remover.\n");
    } else {
        int removedValue = deque[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("Removido %d do topo.\n", removedValue);
    }
}

void removeRear() {// função remover atrás
    if (isEmpty()) {
        printf("Deque está vazio. Não é possível remover.\n");
    } else {
        int removedValue = deque[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
        printf("Removido %d do final.\n", removedValue);
    }
}

int getFrontValue() {// vslor da frente
    if (isEmpty()) {
        printf("Deque está vazio.\n");
        return -1;
    } else {
        return deque[front];
    }
}

int getRearValue() {// valor de tras
    if (isEmpty()) {
        printf("Deque está vazio.\n");
        return -1;
    } else {
        return deque[rear];
    }
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\nEscolha a operação:\n");
        printf("1. Inserir no topo\n");
        printf("2. Inserir no final\n");
        printf("3. Remover do topo\n");
        printf("4. Remover do final\n");
        printf("5. Verificar valor no topo\n");
        printf("6. Verificar valor no final\n");
        printf("7. Fim\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido no topo: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                removeFront();
                break;
            case 4:
                removeRear();
                break;
            case 5:
                printf("Valor no topo: %d\n", getFrontValue());
                break;
            case 6:
                printf("Valor no final: %d\n", getRearValue());
                break;
            case 7:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    }

    return 0;
}