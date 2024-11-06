#include <iostream> //entrada e saída -> cin cout
#include <fstream> //para trabalhar com arquivos
#include <cstdlib> //para funções rand() e alocação de memória
#include <string>
#include <ctime> //para gerar números aleatórios de forma consistente
#include <sstream>  //para conversões de string
#include "arquivos.h"

using namespace std;

//função alternativa para substituir to_string se necessário
std::string intToString(int value)
{
    std::ostringstream os; //faz parte de <sstream>, p/ manipulá-las como fluxo de dados
    os << value;
    return os.str(); //transformação de tudo que os recebe p/ string
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
    srand(0); //inicializa com o 0 números aleatórios consistentes (todos os algoritmos lerão o mesmo arquivo)

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

//função para criar arquivos com base na opção escolhida
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
            cerr << "Opção de arquivo inválida!" << endl;
            break;
    }
}


/*
cria um vetor com os nomes que vai percorrer
----------------------
char vetorNomes[3][20] = {"ord500.txt", "inv500.txt", "ale500.txt"};
*/
