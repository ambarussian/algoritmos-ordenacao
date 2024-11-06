#include "insertsort.h"

void insertSort(int v[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = aux;
    }
}
