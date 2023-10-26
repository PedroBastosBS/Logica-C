#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h> //biblioteca para utilizar termos a fim e avaliar tempos
#include<windows.h> //utilizado para o comando Sleep

clock_t initTime()
{
    clock_t T_inicio;

    return T_inicio = clock(); //a vari�vel T_inicio capta o clock atual do computador


}

clock_t finalTime()
{
    clock_t T_fim;

	return T_fim = clock(); //a vari�vel T_fim capta o clock atual do computador

}


double totalTime(clock_t finalTime, clock_t initTime)
{
    double T_total;
    T_total = ((finalTime - initTime) * 1000.0) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %g ms",T_total);
	return T_total;
}
