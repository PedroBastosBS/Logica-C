#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 101 // Alterar aqui para 101, 1 001, 10 001, 1 000 001
#define QTDE 100 //precisa ser menor que MAX

void shuffle(int *array) {
    for (int i = MAX - MIN - 1; i > 0; i--) {
        //int j = rand() % (i + 1);
        int j = (i);
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}
int a;
int main(void) {
    FILE *geRar;
	geRar = fopen("100_Numeros.txt","w");

    srand(time(NULL));

    int * numeros = (int*) malloc((MAX - MIN) * sizeof(int));
    if (!numeros) exit(EXIT_FAILURE);
    for (int i = 0; i < MAX - MIN; i++) {
        numeros[i] = i + MIN;
        a++;
    }
    shuffle(numeros);
    for(int i = 0; i<QTDE; i++){
		fprintf(geRar,"%d ",numeros[i]);
		printf("%d ",numeros[i]);
        //a = i;
	}
    printf("\n\nTotal %d", a);
    return 0;
}
