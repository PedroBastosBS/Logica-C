#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 20

void inserir_elemento(int vetor[]);
void remover_elemento(int vetor[]);
void imprimir_vetor(int vetor[]);
void menu();

int main()
{
    int vetor[TAMANHO_VETOR] = {0}; // inicializa o vetor com 20 elementos zerados

    // Inicializando o gerador de n�meros aleat�rios com o tempo atual
    srand(time(NULL));

    int opcao;
    do {
        menu();
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_elemento(vetor);
                break;
            case 2:
                remover_elemento(vetor);
                break;
            case 3:
                imprimir_vetor(vetor);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

void inserir_elemento(int vetor[])
{
    int valor;
    do {
        printf("Digite um valor inteiro a ser inserido no vetor (0 para cancelar): ");
        scanf("%d", &valor);
        if (valor == 0) {
            printf("Operacao cancelada.\n");
            return;
        }
    } while (valor < 1 || valor > 100); // limita o valor inserido entre 1 e 100

    int posicao;
    do {
        posicao = rand() % TAMANHO_VETOR;
    } while (vetor[posicao] != 0); // busca uma posi��o vazia no vetor

    vetor[posicao] = valor;
    printf("Valor %d inserido na posicao %d.\n", valor, posicao);
}

void remover_elemento(int vetor[])
{
    int value;


    printf("Digite a posicao do elemento a ser removido (0 para cancelar): ");
    scanf("%d", &value);

    for(int i=0; i < TAMANHO_VETOR; i++){
        if(vetor[i] == value){
            vetor[value] = 0;
            printf("Valor removido da posicao %d.\n", value);
        }
    }
}

void imprimir_vetor(int vetor[])
{
    printf("Vetor: ");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor[i] == 0) {
            printf("_ ");
        } else {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

void menu()
{
    printf("============== MENU ==============\n");
    printf("1. Inserir elemento no vetor\n");
    printf("2. Remover elemento do vetor\n");
    printf("3. Imprimir vetor\n");
    printf("4. Sair\n");
}

