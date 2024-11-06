#include "quicksort.h"

void quickSort(int v[], int menor, int maior) {
    if (menor < maior) {
        int meio = menor + (maior - menor) / 2; //c�lculo do meio
        int pivot = v[meio]; //piv� passa a ser o valor do meio
        int i = menor - 1;

        //move o piv� para o final temporariamente
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

        //coloca o piv� na posi��o correta
        aux = v[i + 1];
        v[i + 1] = v[maior];
        v[maior] = aux;
        int pi = i + 1;

        //chamada recursiva para subarrays � esquerda e � direita do piv�
        quickSort(v, menor, pi - 1);
        quickSort(v, pi + 1, maior);
    }
}
