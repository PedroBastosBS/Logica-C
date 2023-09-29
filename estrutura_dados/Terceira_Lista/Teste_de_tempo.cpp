#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h> //biblioteca para utilizar termos a fim e avaliar tempos
#include<windows.h> //utilizado para o comando Sleep

main(){

    clock_t T_inicio, T_fim; //tipo de variável que capta o tempo de clock do computador
    double T_total;
    int i;

    	//Início do cálculo de tempo total da proposta
	T_inicio = clock(); //a variável T_inicio capta o clock atual do computador

	for(i=0;i<=100;i++){
        printf("\n%d ",i);
        //Sleep(500); //funcionalidade da biblioteca windows.h que faz com que o sistema hiberne por 500 ms
	}

	T_fim = clock(); //a variável T_fim capta o clock atual do computador
	T_total = ((T_fim - T_inicio) * 1000.0) / CLOCKS_PER_SEC;
	//T_total adquire a diferença entre os clocks e calcula em ms
    printf("\nTempo de execucao: %g ms",T_total);

    system("pause");


}
