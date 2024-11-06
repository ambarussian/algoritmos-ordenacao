#include "mergesort.h"

/*#include <vector>
namespace std{*/
void mergify(int* v, int esquerda, int meio, int direita) {
        int metade1 = meio - esquerda + 1;
        int metade2 = direita - meio;
        // criação de vetores temporários
        int esq[metade1];
        int dir[metade2];
        /*
        std::vector<int> esq(metade1);
        std::vector<int> dir(metade2);
        */

        // transfere dados para vetores temporários
        for (int i = 0; i < metade1; i++){
            esq[i] = v[esquerda + i];
        }
        for (int j = 0; j < metade2; j++){
            dir[j] = v[meio + 1 + j];
        }

        //vetor temporário volta no vetor original
        int i = 0, j = 0, k = esquerda;
        // i é o valor q inicia a esq; j é o valor q inicia a dir; k é o valor q inicia TUDO JUNTO

        while (i < metade1 && j < metade2) {
            if (esq[i] <= dir[j]) {
                v[k] = esq[i];
                i++;

            } else {
                v[k] = dir[j];
                j++;
            }
            k++;
        }
        //copia o resto da esquerda
        while (i < metade1) {
            v[k] = esq[i];
            i++;
            k++;
        }
        //copia o resto da direita
        while (j < metade2) {
            v[k] = dir[j];
            j++;
            k++;
        }
    }
void mergeSort(int* v, int esquerda, int direita)
{
    if (esquerda >= direita)
        return;

    int meio = esquerda + (direita - esquerda) / 2;
    mergeSort(v, esquerda, meio);
    mergeSort(v, meio + 1, direita);
    mergify(v, esquerda, meio, direita);
}
