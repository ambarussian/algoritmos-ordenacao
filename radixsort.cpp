#include "radixsort.h"

//percorre v[] em busca do maior numero
int obtemMaior(int v[], int tam)
{
    int maior = v[0];
    for (int i = 1; i < tam; i++)
        if (v[i] > maior)
            maior = v[i];
    return maior;
}

//contagem de quantas vezes cada digito aparece em determinado elemento de v[]
void countSort(int v[], int tam, int ult)
{
    //criação de output v[] com os ultimos digitos (ult) analisados
    int output[tam];
    int i, count[10] = { 0 };

    //armaznamento de contagem
    for (i = 0; i < tam; i++)
        count[(v[i] / ult) % 10]++;

    //mudança de count para que ele passe a obter
    //a ult posição analisada do elemento em output
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    //construção do vetor temporário
    for (i = tam - 1; i >= 0; i--) {
        output[count[(v[i] / ult) % 10] - 1] = v[i];
        count[(v[i] / ult) % 10]--;
    }

    //copia de output pra v[] para que este
    //tenha numeros ordenados de acordo com ult
    for (i = 0; i < tam; i++)
        v[i] = output[i];
}

void radixSort(int v[], int tam)
{
    //armazena o maior de v[]
    int maiorEncontrado = obtemMaior(v, tam);
    //faz countSort para todos os dígitos de todos os elementos
    for (int ult = 1; maiorEncontrado / ult > 0; ult *= 10)
        countSort(v, tam, ult);
}
