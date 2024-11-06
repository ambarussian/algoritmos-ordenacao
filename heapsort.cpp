#include "heapsort.h"

//fun��o para reorganizar o heap (heapify)
void heapify(int* v, int tam, int i) {
    int maior = i;            // Inicializa maior como raiz
    int esquerda = 2 * i + 1; // �ndice do filho esquerdo
    int direita = 2 * i + 2;  // �ndice do filho direito

    //se o filho da esquerda for maior que a raiz
    if (esquerda < tam && v[esquerda] > v[maior])
        maior = esquerda;

    //se o filho da direita for maior que o maior at� agora
    if (direita < tam && v[direita] > v[maior])
        maior = direita;

    //se o maior n�o for a raiz
    if (maior != i) {
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;

        //recursivamente faz heapify na sub�rvore afetada
        heapify(v, tam, maior);
    }
}

void heapSort(int* v, int tam) {

    //rearranja o vetor
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(v, tam, i);

    //extrai um por um os elementos do heap
    for (int i = tam - 1; i > 0; i--) {
        //move a raiz atual para o final
        int aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        //chama heapify no heap reduzido
        heapify(v, i, 0);
    }
}
