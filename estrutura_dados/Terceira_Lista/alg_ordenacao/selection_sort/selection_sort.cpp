#include <stdio.h>
#include "temporizador.h"
#include "arquivo.h"

void swap(int * xp, int * yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int array[], int n)
{
    int i, j, min_idx;

    for(i = 0; i < n - 1; i++){
        min_idx = i;
        for (j = i + 1; j < n; j ++){
            if(array[j] < array[min_idx])
                min_idx = j;
        }

    swap(&array[min_idx], &array[i]); 
    }
}

void showArray(int array[], int size)
{
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("\n"); 
}


int main()
{
    const char* filename = "10_Numeros.txt";
    int array[MAX_SIZE];
    int size = 0;

    int* result = readArrayFromFile(filename, array, &size);

    if (result == NULL) {
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }
    int n = sizeof(array) / sizeof(array[0]); 
    clock_t init = initTime();
    selectionSort(array, n); 
    clock_t final = finalTime();
    clock_t total = totalTime(final, init);
    printf("Sorted array: \n"); 
    showArray(array, n); 
    return 0;  
}