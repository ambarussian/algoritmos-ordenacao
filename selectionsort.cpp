#include "selectionsort.h"

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) //encontra o menor elemento entre v[i] e v[n-1]
    {
        int menorValor = i;
        for (int j = i + 1; j < n; j++) //encontra o menor elemento entre v[i+1] e v[n-1]
        {
            if (v[j] < v[menorValor])
            {
                menorValor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menorValor];
        v[menorValor] = aux; //existe uma função std::swap que faz essa troca
    }
}
