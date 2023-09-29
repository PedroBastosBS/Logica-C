#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um item
struct Item {
    int id;
    double valor;
    double peso;
};

// Função para realizar o MergeSort
void merge(struct Item *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cria arrays temporários
    struct Item L[n1], R[n2];

    // Copia os dados para os arrays L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mescla os arrays temporários de volta em arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i].valor / L[i].peso >= R[j].valor / R[j].peso) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função para realizar o MergeSort
void mergeSort(struct Item *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combina as metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função para resolver o problema da Mochila
double mochila(struct Item *itens, int n, double totalMochila) {
    // Ordena os itens pelo valor por peso em ordem decrescente
    mergeSort(itens, 0, n - 1);

    double carga = 0.0;
    double valorTotal = 0.0;

    for (int i = 0; i < n; i++) {
        if (carga + itens[i].peso <= totalMochila) {
            // Se o item cabe completamente na mochila
            carga += itens[i].peso;
            valorTotal += itens[i].valor;
            printf("Pegue todo o item %d\n", itens[i].id);
        }
    }

    return valorTotal;
}

int main() {
    int n;
    double totalMochila;

    printf("Informe o número de itens: ");
    scanf("%d", &n);

    struct Item *itens = (struct Item *)malloc(n * sizeof(struct Item));

    printf("Informe o total da mochila: ");
    scanf("%lf", &totalMochila);

    // Seed para gerar números aleatórios
    srand(time(NULL));

    // Preenche os itens com valores e pesos aleatórios
    for (int i = 0; i < n; i++) {
        itens[i].id = i + 1;
        itens[i].valor = rand() % 31; // Valor aleatório entre 0 e 30
        itens[i].peso = rand() % 31;  // Peso aleatório entre 0 e 30
        printf("Item %d: Valor = %.2lf, Peso = %.2lf\n", itens[i].id, itens[i].valor, itens[i].peso);
    }

    double valorTotal = mochila(itens, n, totalMochila);

    printf("Valor total na mochila: %.2lf\n", valorTotal);

    free(itens);

    return 0;
}