#include <stdio.h>


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
    int arr[] = { 64, 25, 12, 22, 11 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    showArray(arr, n); 
    return 0;  
}