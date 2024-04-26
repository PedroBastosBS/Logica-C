
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura de um nó da árvore
struct No {
    int info;
    struct No *esq;
    struct No *dir;
};

// Estrutura da árvore binária
typedef struct ArvoreBinaria {
    struct No *raiz;
} ArvoreBinaria;

// Função para criar uma nova árvore
ArvoreBinaria *criaArvore() {
    ArvoreBinaria *arvore = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
    if (arvore != NULL)
        arvore->raiz = NULL;
    return arvore;
}

// Função auxiliar para liberar os nós da árvore
void liberaNo(struct No *no) {
    if (no == NULL)
        return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
}

// Função para liberar a árvore
void liberaArvore(ArvoreBinaria *arvore) {
    if (arvore == NULL)
        return;
    liberaNo(arvore->raiz);
    free(arvore);
}

// Função auxiliar para inserção recursiva de um elemento na árvore
struct No *insereRecursivo(struct No *no, int valor) {
    if (no == NULL) {
        struct No *novo = (struct No *)malloc(sizeof(struct No));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (valor < no->info)
        no->esq = insereRecursivo(no->esq, valor);
    else if (valor > no->info)
        no->dir = insereRecursivo(no->dir, valor);

    return no;
}

// Função para inserir um elemento na árvore
void insere(ArvoreBinaria *arvore, int valor) {
    if (arvore == NULL)
        return;
    arvore->raiz = insereRecursivo(arvore->raiz, valor);
}

// Função auxiliar para balanceamento global utilizando o algoritmo DSW
struct No *balancearDSW(struct No *raiz) {
    // Transforma a árvore em uma lista encadeada direita
    struct No *aux = raiz;
    while (aux != NULL) {
        while (aux->esq != NULL) {
            struct No *filho = aux->esq;
            aux->esq = filho->dir;
            filho->dir = aux;
            aux = filho;
        }
        aux = aux->dir;
    }

    // Realiza a etapa de balanceamento do algoritmo DSW
    int n = 0;
    aux = raiz;
    while (aux != NULL) {
        aux = aux->dir;
        n++;
    }

    int m = pow(2, floor(log2(n + 1))) - 1;
    struct No *raizBalanc = raiz;
    for (int i = 0; i < n - m; i++) {
        struct No *filho = raizBalanc->dir;
        raizBalanc->dir = filho->esq;
        filho->esq = raizBalanc;
        raizBalanc = filho;
    }

    while (m > 1) {
        m /= 2;
        raizBalanc = raiz;
        for (int i = 0; i < m; i++) {
            struct No *filho = raizBalanc->dir->dir;
            raizBalanc->dir->dir = filho->esq;
            filho->esq = raizBalanc->dir;
            raizBalanc->dir = filho;
            raizBalanc = filho;
        }
    }

    return raizBalanc;
}

// Função auxiliar para percurso em in-ordem
void emOrdemRecursivo(struct No *no) {
    if (no != NULL) {
        emOrdemRecursivo(no->esq);
        printf("%d ", no->info);
        emOrdemRecursivo(no->dir);
    }
}

// Função para balanceamento global da árvore
void balanceamentoGlobal(ArvoreBinaria *arvore) {
    if (arvore == NULL || arvore->raiz == NULL)
        return;
    arvore->raiz = balancearDSW(arvore->raiz);
}

// Função para busca de um elemento na árvore
int busca(struct No *raiz, int valor) {
    while (raiz != NULL) {
        if (valor == raiz->info)
            return 1;
        else if (valor < raiz->info)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return 0;
}

// Função para exibir o menu
void menu(ArvoreBinaria *arvore) {
    int opcao, valor;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Balanceamento global\n");
        printf("3. Buscar elemento\n");
        printf("4. Percorrer em In-Ordem\n");
        printf("5. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere(arvore, valor);
                break;
            case 2:
                balanceamentoGlobal(arvore);
                printf("Balanceamento global realizado.\n");
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (busca(arvore->raiz, valor))
                    printf("O valor %d esta na arvore.\n", valor);
                else
                    printf("O valor %d nao esta na arvore.\n", valor);
                break;
            case 4:
                printf("Percurso em In-Ordem: ");
                emOrdemRecursivo(arvore->raiz);
                printf("\n");
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opçao invalida!\n");
        }
    } while (opcao != 5);
}

int main() {
    ArvoreBinaria *arvore = criaArvore();
    if (arvore == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }

    menu(arvore);

    liberaArvore(arvore);
    return 0;
}