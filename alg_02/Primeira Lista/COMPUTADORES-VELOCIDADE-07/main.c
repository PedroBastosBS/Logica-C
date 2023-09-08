#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void getTempoDeExecucao(clock_t incio, clock_t fim) {
    double TEMPO_DE_USO_DA_CPU = ((double) (fim - incio));
    printf("TEMPO DECORRIDO DE EXECUCAO: %lf SEGUNDOS\n", TEMPO_DE_USO_DA_CPU);
}

void getTempoDecorrido(int limiteTempo) {
    clock_t inicio, fim;
    int contador = 0;

    inicio = clock();

    while(contador < limiteTempo) {
        contador++;
        if(contador % 1000000 == 0){
            printf("%d\n", contador);
            fim = clock();
            getTempoDeExecucao(inicio,fim);
        }
    }
    fim = clock();
    getTempoDeExecucao(inicio,fim);
}

int main() {
    int limiteTempo = 5000000;
    getTempoDecorrido(limiteTempo);
    return 0;
}