
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSOS 5
int k = 0;
struct Processo {
    int tempo;
};

void novoProcesso(struct Processo processos[], int *numProcessos) {
    if (*numProcessos < MAX_PROCESSOS) {
        printf("Digite o tempo de processamento para o novo processo: ");
        scanf("%d", &processos[*numProcessos].tempo);
        (*numProcessos)++;
    } else {
        printf("Limite de processos atingido!\n");
    }
}

void novaIteracao(struct Processo processos[], int *numProcessos, int tempoProcessador) {
    for(int i=0; i < *numProcessos; i++){
        
        //processos[i].tempo -= tempoProcessador;
        processos[i].tempo = (processos[i].tempo-tempoProcessador);
        if (processos[i].tempo <= 0) {
            //printf("Processo %d concluído na posição %d!\n", processos[i].id, i);
            
            printf("Processo %d concluido\n", i+1);
            //printf("Processos %d\n", processos[i].tempo);

        }
    }
     // Remove o processo concluído
    int k = *numProcessos;
    for(int i = 0; i <= k; i++){
        if( processos[i].tempo <= 0){
            (*numProcessos)--;
            //printf("processos%d\n",*numProcessos);
        }
    }
 
}

void imprimir(struct Processo processos[], int *numProcessos) {
    if (*numProcessos > 0){
        //printf("0 processos\n");
        printf("Processos na lista:\n");
        for (int i = 0; i < *numProcessos; i++) {
            if(processos[i].tempo > 0){
                printf("Processo %d:\n", i + 1);
                printf("Tempo de processamento: %d\n", processos[i].tempo);   
        }
        }
    }
    else{
        printf("0 processos\n");
        /*
        printf("Processos na lista:\n");
        for (int i = 0; i < *numProcessos; i++) {
            printf("Processo %d:\n", i + 1);
            printf("Tempo de processamento: %d\n", processos[i].tempo);
    }*/
    }
}

int main() {
    struct Processo processos[MAX_PROCESSOS];
    int numProcessos = 0;
    int temp, opcao;

    printf("Digite o tempo dispon�vel do processador: ");
    scanf("%d", &temp);

    do {
        printf("\nMENU DE OP��ES:\n");
        printf("1 - Novo processo\n");
        printf("2 - Nova itera��o\n");
        printf("3 - Imprimir processos\n");
        printf("4 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao) {
            case 1:
                novoProcesso(processos, &numProcessos);
                break;
            case 2:
                novaIteracao(processos, &numProcessos, temp);
                break;
            case 3:
                imprimir(processos, &numProcessos);

                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida! Escolha novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}