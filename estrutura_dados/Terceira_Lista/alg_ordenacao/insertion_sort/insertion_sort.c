#include <math.h>
#include <stdio.h>

void insertionSort(int array[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++){
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

}

void showArray(int array[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(array) / sizeof(array[0]);
 
    insertionSort(array, N);
    showArray(array, N);
    return 0;

}