#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>

int* readArrayFromFile(const char* filename, int* array, int* size) {
    FILE* file;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro na abertura do arquivo.");
        return NULL;
    }

    while (fscanf(file, "%d", &array[i]) != EOF) {
        i++;
        if (i >= MAX_SIZE) {
            printf("Tamanho máximo do array atingido.");
            break;
        }
    }

    fclose(file);

    *size = i;
    return array;
}
