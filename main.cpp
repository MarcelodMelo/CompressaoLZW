#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dicionario.hpp"

using namespace std;

int main()
{
    cout <<"-Algoritmo de Compressao LZW-\nDigite o nome do arquivo txt com a string a ser codificada"<<endl;
    string nomeArquivo;
    cin >> nomeArquivo;
    std::ifstream entrada(nomeArquivo+".txt"); //Pede pelo nome do arquivo de entrada para ler sua string

    string palavra;
    getline(entrada, palavra);
    cout << endl<<"String dentro do arquivo: "<< palavra<<endl; //Imprime a string dentro do txt

    Dicionario d1;// Dicionario criado
    vector<int> codigo;
    codigo = d1.codificando(palavra); // resultado da compressão da string

    cout<<"Deseja\n1)Imprimir a string comprimida na tela\n2)Imprimir a string comprimida em um arquivo de saida?"<<endl;
    int opcao;
    cin >> opcao;
    if(opcao == 1){
        cout << "String comprimida igual a: ";
        for (int i=0; i<codigo.size(); i++){
            cout << "(" << codigo[i] <<"),";
        }
        cout <<endl<<endl;
    }
    if(opcao == 2){
        std::ofstream saida;
        saida.open ("Codificado.txt");
        for (int i=0; i<codigo.size(); i++){
            saida <<codigo[i] <<",";
        }
        saida.close();
        cout << "String comprimida salva no arquivo Codificado.txt"<<endl<<endl;
    }

    cout<< "Deseja decodificar a string comprimida para verificar a veracidade do algoritmo?\n1)Sim\n2)Nao" <<endl;
    int deco;
    cin >> deco;
    if(deco == 1){
        string saidaDecodificada;
        saidaDecodificada = d1.decodificando(codigo);
        if(opcao == 1){
            cout << "Decodificacao da string comprimida resultou na seguinte string: " << saidaDecodificada << endl;
        }
        if(opcao == 2){
            std::ofstream saida;
            saida.open ("Decodificado.txt");
            saida << saidaDecodificada;
            saida.close();
            cout << "Decodificacao da string comprimida salva no arquivo Decodificado.txt"<<endl;
        }
    }
    return 0;
}
