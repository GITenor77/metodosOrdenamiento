#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  // Tamaño del array

// Función para intercambiar dos elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para particionar la lista
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Elegimos el último elemento como pivote
    int i = (low - 1);  // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementa el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función para aplicar el algoritmo quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenemos el índice de partición
        int pi = partition(arr, low, high);

        // Ordenamos los elementos por separado
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para mostrar el array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    
    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Asignamos valores aleatorios al array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // Números aleatorios entre 0 y 99
    }

    printf("Array original:\n");
    printArray(arr, SIZE);

    // Ordenamos el array usando quicksort
    quickSort(arr, 0, SIZE - 1);

    printf("\nArray ordenado:\n");
    printArray(arr, SIZE);

    return 0;
}
