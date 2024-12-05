#include <iostream>
#include <vector>
using namespace std;

//estrutura de dados para armazenar os valores e se o campo esta vazio
struct DataItem {
    int key;
    int data;
    bool isEmpty;
};

//definicao da tabela hash 
class HashTable {
private:

    vector<DataItem> tabela;
    int tamanho;
    //variaveis para armazenar a ordem de imsercao 
    int contadordeordem;
    vector<int>ordeminsercao;

    int funcaoHash(int chave) {
        return chave % tamanho;
    }

public:
    HashTable(int tam) : tamanho(tam), contadordeordem(0) {
        tabela.resize(tam);
        for (auto& item : tabela) {
            item.isEmpty = true;
        }
    }

//insercao de valores na tabela hash
    void inserir(int valor) {
        int indice = funcaoHash(valor);
        
        while (!tabela[indice].isEmpty) {
            indice = (indice + 1) % tamanho;
        }
        
       
    

    //a contagem da ordem de quais valores foram inseridos 
    //nao e o melhor forma de se aboredar pois um vetor extra muito grande vai consumir um memoria e processamento 
    tabela[indice] = {valor, contadordeordem, false};
    ordeminsercao.push_back(indice);
    contadordeordem++;
    }


//remocao de valores na tabela hash
    void remover(int valor) {
        int indice = funcaoHash(valor);
        
        while (!tabela[indice].isEmpty) {
            if (tabela[indice].key == valor) {
                tabela[indice].isEmpty = true;
                return;
            }
            indice = (indice + 1) % tamanho;
        }
    }
//listagem de chaves na tabela hash -- saida
//listagem se baseia a ordem de chegada 
    void listarChaves() {
        for (const auto& item : ordeminsercao) {
            if (!tabela[item].isEmpty) {
                cout << tabela[item].key << " ";
            }
        }
        cout << endl;
        
    }
};

//entrada usando como parada eof e usando a flag l 
int main() {
    int tam;
    cin >> tam;
    HashTable hash(tam);
    
    char op;
    int valor;

    while (cin >> op) {
        if (op == 'i') {
            cin >> valor;
            hash.inserir(valor);
        } else if (op == 'r') {
            cin >> valor;
            hash.remover(valor);
        } else if (op == 'l') {
            hash.listarChaves();
        }
    }

    return 0;
}