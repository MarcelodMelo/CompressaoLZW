#ifndef DICIONARIO_HPP_INCLUDED
#define DICIONARIO_HPP_INCLUDED
#include <vector>
int tam=256; //Tamanho inicial do dicionario, antes eu fazia teste com apenas 5 elementos, por isso criei essa variavel global
using namespace std;

class Dicionario{
private:
    vector<string> _dicionario; //Vetor de Strings representando o Dicionario LZW
public:

    Dicionario(){ //Criador do Dicionario
        string c; 
        for (int i=0 ; i<tam ; i++){
            c = i;
            this->_dicionario.push_back(c);
        }
        return;
    }

    void limparDicionario(){ //Limpa o dicionario, retirando todas as entradas que estão depois do tamanho original do dicionario
        _dicionario.erase(_dicionario.begin()+tam , _dicionario.begin()+_dicionario.size());
        return;
    }

    void lerDicionario(){ //Faz a Leitura do dicionario, não é importante para o codigo mas serviu durante a criação do mesmo
        for(int i=0; i<this->_dicionario.size(); i++)
            cout << i << " " << this->_dicionario[i]<< endl;
        }

    bool jaVisto(string procurada){ //Procura se a string dada existe como uma inscrição dentro do Dicionario
        for (int i=0; i < this->_dicionario.size(); i++) {
            if (procurada == this->_dicionario[i])
                return true;
            }
        return false;
    }

    bool jaVisto(int indice){ // Procura se o indice dado existe dentro do Dicionario
        if(indice < _dicionario.size()){
            return true;
            }
        return false;
    }

    int indiceDicionario(vector<string> dicio, string procurada){ // Retorna o indice do Dicionario da string dada 
        for (int i=0; i < dicio.size(); i++) {
            if (procurada == dicio[i])
                return i;
        }
        return -1;
    }



    vector<int> codificando(string entrada){ // Função principal, tendo uma string como entrada e como saida o vetor de inteiros representando a string comprimida
        string currentString;
        currentString = entrada[0];
        char atual = (char) 0;
        vector<int> saida;
        int indexAtual=1;
        while(indexAtual < entrada.size()){
            atual = entrada[indexAtual];
            if(jaVisto(currentString+(char)atual)){
                currentString+=atual;
            }else{
                _dicionario.push_back(currentString+(char)atual);
                saida.push_back(indiceDicionario(_dicionario,currentString));
                currentString=atual;
            }
            indexAtual++;
        }
        saida.push_back(indiceDicionario(_dicionario,currentString));
        return saida;
    }

    string decodificando(vector<int> entrada){// Função para decodificar, não é importante para o codigo mas foi util durante a criação do mesmo
        limparDicionario();
        string antiga;
        antiga = (char) 0;
        string nova;
        nova = _dicionario[entrada[0]];
        string saida;
        saida = nova;
        //cout<< antiga+nova<<endl<<endl;
        int index=1;
        while(index<entrada.size()){
            antiga=nova;
            nova=_dicionario[entrada[index]];
            //cout<< antiga <<" "<<nova<<endl;
            if(!jaVisto(antiga+nova)){
                _dicionario.push_back(antiga+nova[0]);
            }
            saida=saida+nova;
            index++;
        }
        //cout << endl<<saida;
        return saida;
    }
};

#endif // DICIONARIO_HPP_INCLUDED
