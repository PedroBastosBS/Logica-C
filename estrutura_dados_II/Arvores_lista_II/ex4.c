
#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore AVL
struct No {
    int info;
    struct No *esq;
    struct No *dir;
    int altura;
};

// Função para obter a altura de um nó
int altura(struct No *no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

// Função para calcular o fator de balanceamento de um nó
int fatorBalanceamento(struct No *no) {
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

// Função para criar um novo nó
struct No *novoNo(int valor) {
    struct No *no = (struct No *)malloc(sizeof(struct No));
    if (no != NULL) {
        no->info = valor;
        no->esq = NULL;
        no->dir = NULL;
        no->altura = 1;
    }
    return no;
}

// Função para rotacionar à direita
struct No *rotacaoDireita(struct No *y) {
    struct No *x = y->esq;
    struct No *T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas
    y->altura = (altura(y->esq) > altura(y->dir) ? altura(y->esq) : altura(y->dir)) + 1;
    x->altura = (altura(x->esq) > altura(x->dir) ? altura(x->esq) : altura(x->dir)) + 1;

    return x;
}

// Função para rotacionar à esquerda
struct No *rotacaoEsquerda(struct No *x) {
    struct No *y = x->dir;
    struct No *T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = (altura(x->esq) > altura(x->dir) ? altura(x->esq) : altura(x->dir)) + 1;
    y->altura = (altura(y->esq) > altura(y->dir) ? altura(y->esq) : altura(y->dir)) + 1;

    return y;
}

// Função para inserir um elemento na árvore AVL
struct No *insereAVL(struct No *raiz, int valor) {
    // Passo 1: Inserção normal de um nó BST
    if (raiz == NULL)
        return novoNo(valor);

    if (valor < raiz->info)
        raiz->esq = insereAVL(raiz->esq, valor);
    else if (valor > raiz->info)
        raiz->dir = insereAVL(raiz->dir, valor);
    else // Valores iguais não são permitidos em árvores AVL
        return raiz;

    // Passo 2: Atualizar a altura do nó atual
    raiz->altura = 1 + ((altura(raiz->esq) > altura(raiz->dir)) ? altura(raiz->esq) : altura(raiz->dir));

    // Passo 3: Obter o fator de balanceamento do nó pai para verificar se é necessário reequilibrar a árvore
    int balanceamento = fatorBalanceamento(raiz);

    // Se o nó se tornar desequilibrado, existem 4 casos de rotação

    // Caso Esquerda-Esquerda (LL)
    if (balanceamento > 1 && valor < raiz->esq->info)
        return rotacaoDireita(raiz);

    // Caso Direita-Direita (RR)
    if (balanceamento < -1 && valor > raiz->dir->info)
        return rotacaoEsquerda(raiz);

    // Caso Esquerda-Direita (LR)
    if (balanceamento > 1 && valor > raiz->esq->info) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Caso Direita-Esquerda (RL)
    if (balanceamento < -1 && valor < raiz->dir->info) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função auxiliar para encontrar o nó com o valor mínimo em uma árvore
struct No *minValorNo(struct No *no) {
    struct No *atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

// Função para remover um nó na árvore AVL
struct No *removeAVL(struct No *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->info)
        raiz->esq = removeAVL(raiz->esq, valor);
    else if (valor > raiz->info)
        raiz->dir = removeAVL(raiz->dir, valor);
    else {
        // Nó com apenas um filho ou sem filho
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            struct No *temp = raiz->esq ? raiz->esq : raiz->dir;

            // Caso sem filho
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else // Caso com um filho
                *raiz = *temp;
            free(temp);
        } else {
            // Nó com dois filhos: obtem o sucessor in-order (menor na subárvore direita)
            struct No *temp = minValorNo(raiz->dir);
            raiz->info = temp->info;
            raiz->dir = removeAVL(raiz->dir, temp->info);
        }
    }

    // Se a árvore tinha apenas um nó, então retornar
    if (raiz == NULL)
        return raiz;

    // Passo 2: Atualizar a altura do nó atual
    raiz->altura = 1 + ((altura(raiz->esq) > altura(raiz->dir)) ? altura(raiz->esq) : altura(raiz->dir));

    // Passo 3: Obter o fator de balanceamento do nó pai para verificar se é necessário reequilibrar a árvore
    int balanceamento = fatorBalanceamento(raiz);

    // Se o nó se tornar desequilibrado, existem 4 casos de rotação

    // Caso Esquerda-Esquerda (LL)
    if (balanceamento > 1 && fatorBalanceamento(raiz->esq) >= 0)
        return rotacaoDireita(raiz);

    // Caso Direita-Direita (RR)
    if (balanceamento < -1 && fatorBalanceamento(raiz->dir) <= 0)
        return rotacaoEsquerda(raiz);

    // Caso Esquerda-Direita (LR)
    if (balanceamento > 1 && fatorBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Caso Direita-Esquerda (RL)
    if (balanceamento < -1 && fatorBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Função para buscar um elemento na árvore AVL
int busca(struct No *raiz, int valor) {
    if (raiz == NULL)
        return 0;

    if (valor == raiz->info)
        return 1;
    else if (valor < raiz->info)
        return busca(raiz->esq, valor);
    else
        return busca(raiz->dir, valor);
}

// Função auxiliar para percorrer a árvore em ordem
void percorrerInOrdem(struct No *raiz) {
    if (raiz != NULL) {
        percorrerInOrdem(raiz->esq);
        printf("%d ", raiz->info);
        percorrerInOrdem(raiz->dir);
    }
}

// Função para exibir o menu
void menu(struct No **raiz) {
    int opcao, valor;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir elemento em AVL\n");
        printf("2. Remover elemento em AVL\n");
        printf("3. Buscar elemento\n");
        printf("4. Percorrer em In-Ordem\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                *raiz = insereAVL(*raiz, valor);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                *raiz = removeAVL(*raiz, valor);
                break;
            case 3:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (busca(*raiz, valor))
                    printf("O valor %d esta na arvore AVL.\n", valor);
                else
                    printf("O valor %d nao esta na arvore AVL.\n", valor);
                break;
            case 4:
                printf("Percurso em In-Ordem: ");
                percorrerInOrdem(*raiz);
                printf("\n");
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
}

int main() {
    struct No *raiz = NULL;
    menu(&raiz);
    return 0;
}