#include "quicksort.h"

void quickSort(int v[], int menor, int maior) {
    if (menor < maior) {
        int meio = menor + (maior - menor) / 2; //cálculo do meio
        int pivot = v[meio]; //pivô passa a ser o valor do meio
        int i = menor - 1;

        //move o pivô para o final temporariamente
        int aux = v[meio];
        v[meio] = v[maior];
        v[maior] = aux;

        for (int j = menor; j <= maior - 1; j++) {
            if (v[j] < pivot) {
                i++;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }

        //coloca o pivô na posição correta
        aux = v[i + 1];
        v[i + 1] = v[maior];
        v[maior] = aux;
        int pi = i + 1;

        //chamada recursiva para subarrays à esquerda e à direita do pivô
        quickSort(v, menor, pi - 1);
        quickSort(v, pi + 1, maior);
    }
}
