#ifndef EXECUTAR_ORDENACAO_H
#define EXECUTAR_ORDENACAO_H

#include <string>

using namespace std;
int* lerArquivo(string nomeArquivo, int tam);
void executarOrdenacao(int algoritmo, int tam, const string& nomeArquivo);

#endif // EXECUTAR_ORDENACAO_H
