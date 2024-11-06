#include <iostream> //entrada e sa�da -> cin cout
#include <string>
#include <ctime> //para utilizar o clock
#include <fstream>
#include "arquivos.h"
#include "executar_ordenacao.h"
#include "bubblesort.h"
#include "insertsort.h"
#include "selectionsort.h"
#include "shellsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heapsort.h"
#include "radixsort.h"

using namespace std;
int* lerArquivo(string nomeArquivo, int tam)
{
    ifstream arquivo(nomeArquivo.c_str());
    if (!arquivo)
    {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return NULL;  //retorna ponteiro nulo em caso de erro
    }

    int* vetor = new int[tam];  //aloca dinamicamente um vetor
    for (int i = 0; i < tam; i++)
    {
        arquivo >> vetor[i];
    }
    arquivo.close();
    return vetor;  //retorna o vetor lido
}
//----------------------------------------------------------------------
//CLOCK E EXECU��O DO ALGORITMO
void executarOrdenacao(int algoritmo, int tam, const string& nomeArquivo)
{
    int* vetor = lerArquivo(nomeArquivo, tam); //ler o arquivo e armazenar os dados em um vetor
    if (vetor == NULL)
    {
        return;
    }

    clock_t inicioOrdenacao = clock(); //inicia o tempo de ordena��o
    switch (algoritmo)
    {
    case 1:
        bubbleSort(vetor, tam);
        cout << "Tempo de ordena��o com BubbleSort: "
             << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
             << " segundos" << endl;
        break;
    case 2:
        insertSort(vetor, tam);
        cout << "Tempo de ordena��o com InsertSort: "
             << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
             << " segundos" << endl;
        break;
    case 3:
        selectionSort(vetor, tam);
        cout << "Tempo de ordena��o com SelectionSort: "
             << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
             << " segundos" << endl;
        break;
    case 4:
        shellSort(vetor, tam);
        cout << "Tempo de ordena��o com ShellSort: "
             << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
             << " segundos" << endl;
        break;
case 5:
            quickSort(vetor, 0, tam - 1);
            cout << "Tempo de ordena��o com QuickSort: "
                 << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
                 << " segundos" << endl;
            break;
case 6:
            mergeSort(vetor, 0, tam - 1);
            cout << "Tempo de ordena��o com MergeSort: "
                 << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
                 << " segundos" << endl;
            break;
case 7:
            heapSort(vetor, tam);
            cout << "Tempo de ordena��o com HeapSort: "
                 << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
                 << " segundos" << endl;
            break;
case 8:
            radixSort(vetor, tam);
            cout << "Tempo de ordena��o com RadixSort: "
                 << (double)(clock() - inicioOrdenacao) / CLOCKS_PER_SEC
                 << " segundos" << endl;
            break;
    default:
        cout << "Algoritmo n�o suportado!" << endl;
        break;
    }
    delete[] vetor; //libera a mem�ria alocada
}
