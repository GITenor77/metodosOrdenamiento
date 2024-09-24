#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int v[], int n) {
    int aux;
    
    // Implementación del algoritmo de la burbuja
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (v[j - 1] > v[j]) {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main() {
    int n = 10; // Tamaño del vector
    int v[n];
    
    // Inicializamos el generador de números aleatorios
    srand(time(0));

    // Asignamos valores aleatorios al vector
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;  // Números aleatorios entre 0 y 99
    }

    // Mostrar el vector original
    printf("Vector original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    ordenar(v, n); // Llamada al algoritmo de ordenación

    // Mostrar el vector ordenado
    printf("Vector ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
