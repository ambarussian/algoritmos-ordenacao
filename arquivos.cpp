#include <iostream> //entrada e sa�da -> cin cout
#include <fstream> //para trabalhar com arquivos
#include <cstdlib> //para fun��es rand() e aloca��o de mem�ria
#include <string>
#include <ctime> //para gerar n�meros aleat�rios de forma consistente
#include <sstream>  //para convers�es de string
#include "arquivos.h"

using namespace std;

//fun��o alternativa para substituir to_string se necess�rio
std::string intToString(int value)
{
    std::ostringstream os; //faz parte de <sstream>, p/ manipul�-las como fluxo de dados
    os << value;
    return os.str(); //transforma��o de tudo que os recebe p/ string
}
//-----------------------------------------------------------------------
void Ordenado(int tam) {
    string nomeArquivo = "Ordenado" + intToString(tam) + ".txt";
    ofstream ordenado(nomeArquivo.c_str());  //usa c_str() de <string>
    if (!ordenado) {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
        return;
    }
    for (int x = 1; x <= tam; x++) {
        ordenado << x << endl;
    }
    ordenado.close();
}

void Aleatorio(int tam) {
    string nomeArquivo = "Aleatorio" + intToString(tam) + ".txt";
    ofstream aleatorio(nomeArquivo.c_str());  //usa c_str() de <string>
    if (!aleatorio) {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
        return;
    }
    srand(0); //inicializa com o 0 n�meros aleat�rios consistentes (todos os algoritmos ler�o o mesmo arquivo)

    for (int i = 1; i < tam; i++) {
        int numeroAleatorio = rand() % tam;
        aleatorio << numeroAleatorio << endl;
    }
    aleatorio.close();
}

void Invertido(int tam) {
    string nomeArquivo = "Invertido" + intToString(tam) + ".txt";
    ofstream invertido(nomeArquivo.c_str());  //usa c_str() de <string>
    if (!invertido) {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
        return;
    }
    for (int x = tam; x >= 1; x--) {
        invertido << x << endl;
    }
    invertido.close();
}

//fun��o para criar arquivos com base na op��o escolhida
void criarArquivos(int tam, int opcao) {
    switch (opcao) {
        case 1:
            Ordenado(tam);
            break;
        case 2:
            Aleatorio(tam);
            break;
        case 3:
            Invertido(tam);
            break;
        default:
            cerr << "Op��o de arquivo inv�lida!" << endl;
            break;
    }
}


/*
cria um vetor com os nomes que vai percorrer
----------------------
char vetorNomes[3][20] = {"ord500.txt", "inv500.txt", "ale500.txt"};
*/
