//bibliotecas usadas na main:
#include <iostream> //entrada e saída -> cin cout
#include <string>
#include <cstdlib> //exit em iniciar != 1
#include <locale.h>
#include "arquivos.h"
#include "executar_ordenacao.h"

//MAIN
using namespace std;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    int iniciar, algoritmo, tam, opcao;
    char continuar; //para continuar o loop do while
    string nomeArquivo;

//CRIA OS ARQUIVOS UMA ÚNICA VEZ
    cout << "Você deseja iniciar o teste dos algoritmos de ordenação?" << endl
         << "1- Sim, crie os arquivos." << endl
         << "2- Não, saia." << endl;
    cin >> iniciar;

    if (iniciar == 1)
    {
        criarArquivos(500000, 1); //ordenado 500 mil
        criarArquivos(750000, 1); //ordenado 750 mil
        criarArquivos(1000000, 1); //ordenado 1 milhão
        criarArquivos(5000000, 1); //ordenado 5 milhões
        criarArquivos(500000, 2); //aleatório 500 mil
        criarArquivos(750000, 2); //aleatório 750 mil
        criarArquivos(1000000, 2); //aleatório 1 milhão
        criarArquivos(5000000, 2); //aleatório 5 milhões
        criarArquivos(500000, 3); //invertido 500 mil
        criarArquivos(750000, 3); //invertido 750 mil
        criarArquivos(1000000, 3); //invertido 1 milhão
        criarArquivos(5000000, 3); //invertido 5 milhões
    }

    else
    {
        cout << "Que pena! Quem sabe outro dia..." << endl;
        exit(0); //stop!!
    }

    do
    {
//ALGORITMO
        do
        {
            cout << "Escolha um algoritmo de ordenação:" << endl
                 << "1- BubbleSort" << endl
                 << "2- InsertSort" << endl
                 << "3- SelectionSort" << endl
                 << "4- ShellSort" << endl
                 << "5- QuickSort" << endl
                 << "6- MergeSort" << endl
                 << "7- HeapSort" << endl
                 << "8- RadixSort" << endl;
            cin >> algoritmo;

            if (algoritmo < 1 || algoritmo > 8)
            {
                cout << "Opção inválida! Tente novamente." << endl;
            }
        }
        while (algoritmo < 1 || algoritmo > 8);


// TAMANHO DO ARQUIVO
do {
    cout << "Escolha o tamanho do arquivo:" << endl
         << "1- 500 mil dados" << endl
         << "2- 750 mil dados" << endl
         << "3- 1 milhão de dados" << endl
         << "4- 5 milhões de dados" << endl;
    cin >> tam;
    switch (tam) {
        case 1:
            tam = 500000; // 500k
            break;
        case 2:
            tam = 750000; // 750k
            break;
        case 3:
            tam = 1000000; // 1 milhão
            break;
        case 4:
            tam = 5000000; // 5 milhões
            break;
        default:
            cout << "Tamanho inválido! Tente novamente:" << endl;
            tam = 0; //para assegurar repetição do loop
    }
} while (tam == 0);

//TIPO DE ARQUIVO
        do
        {
            cout << "Por fim, escolha um tipo de arquivo:" << endl
                 << "1- Ordenado" << endl
                 << "2- Aleatório" << endl
                 << "3- Invertido" << endl;
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                nomeArquivo = "Ordenado" + intToString(tam) + ".txt";
                break;
            case 2:
                nomeArquivo = "Aleatorio" + intToString(tam) + ".txt";
                break;
            case 3:
                nomeArquivo = "Invertido" + intToString(tam) + ".txt";
                break;
            default:
                cout << "Tipo de arquivo inválido! Tente novamente." << endl;
                opcao = 0; //para assegurar repetição do loop
            }
        }
        while (opcao == 0);
        criarArquivos(tam, opcao);

//CHAMADA DA FUNÇÃO DO INÍCIO
        executarOrdenacao(algoritmo, tam, nomeArquivo);
//PARAR OU CONTINUAR
        cout << "Deseja realizar outra ordenação? (s/n): ";
        cin >> continuar;

    }
    while (continuar == 's' || continuar == 'S');

    return 0;
}
