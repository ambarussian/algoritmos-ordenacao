#include "shellsort.h"

void shellSort(int v[], int n) {
    //a distância percorrida no início é a máxima possível; ao passar do tempo ela diminui
    for (int distancia = n / 2; distancia > 0; distancia /= 2)//distância = distância / 2
    {
        for (int i = distancia; i < n; i++) {
            int aux = v[i];
            int j;

            for (j = i; j >= distancia && v[j - distancia] > aux; j -= distancia)//j = j - distância
            {
                v[j] = v[j - distancia];
            }
            v[j] = aux;
        }
    }
}
