
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz); // libera cada nó
    free(raiz); // libera a raiz
}

int insere_ArvBin_Rec(struct NO** raiz, int valor){
    if(*raiz == NULL) {
        struct NO* novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;
        novo->info = valor;
        novo->dir = NULL;
        novo->esq = NULL;
        *raiz = novo;
        return 1;
    }

    if(valor == (*raiz)->info)
        return 0; // elemento já existe
    else if(valor < (*raiz)->info)
        return insere_ArvBin_Rec(&((*raiz)->esq), valor);
    else
        return insere_ArvBin_Rec(&((*raiz)->dir), valor);
}

int insere_ArvBin_NaoRec(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin_Rec(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int remove_ArvBin_NaoRec(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL|| *raiz == NULL)
        return;
    posOrdem_ArvBin(&((*raiz)->esq));
    posOrdem_ArvBin(&((*raiz)->dir));
    printf("%d ",(*raiz)->info);

}

void menu(ArvBin* raiz) {
    int opcao, valor;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir elemento (Recursivo)\n");
        printf("2. Inserir elemento (Nao Recursivo)\n");
        printf("3. Remover elemento (Recursivo)\n");
        printf("4. Remover elemento (Nao Recursivo)\n");
        printf("5. Buscar elemento\n");
        printf("6. Contar elementos internos\n");
        printf("7. Contar elementos folha\n");
        printf("8. Percorrer em Pre-Ordem\n");
        printf("9. Percorrer em In-Ordem\n");
        printf("10. Percorrer em Pos-Ordem\n");
        printf("11. Sair\n");
        printf("Escolha uma opçao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere_ArvBin_Rec(raiz, valor);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere_ArvBin_NaoRec(raiz, valor);
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remove_ArvBin_Rec(raiz, valor);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remove_ArvBin_NaoRec(raiz, valor);
                break;
            case 5:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                if (consulta_ArvBin(raiz, valor))
                    printf("O valor %d está na arvore.\n", valor);
                else
                    printf("O valor %d não está na arvore.\n", valor);
                break;
            case 6:
                printf("A arvore possui %d elementos internos.\n", totalNO_ArvBin(raiz) );
                break;
            case 7:
                printf("A arvore possui %d elementos folha.\n", totalNO_ArvBin(raiz));
                break;
            case 8:
                printf("Percorrendo em Pre-Ordem: ");
                preOrdem_ArvBin(raiz);
                printf("\n");
                break;
            case 9:
                printf("Percorrendo em In-Ordem: ");
                emOrdem_ArvBin(raiz);
                printf("\n");
                break;
            case 10:
                printf("Percorrendo em Pos-Ordem: ");
                posOrdem_ArvBin(raiz);
                printf("\n");
                break;
            case 11:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opçao invalida!\n");
        }
    } while(opcao != 11);
}

int main() {

    ArvBin* raiz = cria_ArvBin();
    menu(raiz);
    libera_ArvBin(raiz);
    return 0;
}