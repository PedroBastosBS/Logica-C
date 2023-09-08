#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 15

void insertOrdered(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("O vetor está cheio. Não é possível inserir mais elementos.\n");
        return;
    }

    int i;
    for (i = *size - 1; (i >= 0 && arr[i] > value); i--) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = value;
    (*size)++;
}

void removeElement(int arr[], int *size, int value) {
    if (*size == 0) {
        printf("O vetor está vazio. Não é possível remover elementos.\n");
        return;
    }

    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        (*size)--;
    } else {
        printf("O elemento %d não foi encontrado no vetor.\n", value);
    }
}


bool trinarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int oneThird = left + (right - left) / 3;
        int twoThird = right - (right - left) / 3;

        if (arr[oneThird] == value || arr[twoThird] == value) {
            return true;
        }

        if (value < arr[oneThird]) {
            right = oneThird - 1;
        } else if (value > arr[twoThird]) {
            left = twoThird + 1;
        } else {
            left = oneThird + 1;
            right = twoThird - 1;
        }
    }

    return false;
}

bool binarySearch(int arr[], int left, int right, int value) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return true;
        }

        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

bool exponentialSearch(int arr[], int size, int value) {
    if (arr[0] == value) {
        return true;
    }

    int i = 1;
    while (i < size && arr[i] <= value) {
        i *= 2;
    }

    return binarySearch(arr, i / 2, (i < size) ? i : size - 1, value);
}


int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value;

    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Busca Trinária\n");
        printf("4. Busca Exponencial\n");
        printf("5. Sair\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &value);
                insertOrdered(arr, &size, value);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &value);
                removeElement(arr, &size, value);
                break;
            case 3:
                printf("Digite o valor a ser buscado (Busca Trinária): ");
                scanf("%d", &value);
                if (trinarySearch(arr, size, value)) {
                    printf("Elemento encontrado!\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 4:
                printf("Digite o valor a ser buscado (Busca Exponencial): ");
                scanf("%d", &value);
                if (exponentialSearch(arr, size, value)) {
                    printf("Elemento encontrado!\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
