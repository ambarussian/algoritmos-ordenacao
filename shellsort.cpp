#include "shellsort.h"

void shellSort(int v[], int n) {
    //a dist�ncia percorrida no in�cio � a m�xima poss�vel; ao passar do tempo ela diminui
    for (int distancia = n / 2; distancia > 0; distancia /= 2)//dist�ncia = dist�ncia / 2
    {
        for (int i = distancia; i < n; i++) {
            int aux = v[i];
            int j;

            for (j = i; j >= distancia && v[j - distancia] > aux; j -= distancia)//j = j - dist�ncia
            {
                v[j] = v[j - distancia];
            }
            v[j] = aux;
        }
    }
}
