
#include <iostream>
#include <vector>
using namespace std;

struct DataItem {
    int key;
    bool ocupado;
    bool deletado;
};

class HashTable {
private:
    vector<DataItem> tabela;
    int tamanho;
    vector<int> ordemChegada;

    int funcaoHash(int chave) {
        return chave % tamanho;
    }

public:
    HashTable(int tam) : tamanho(tam) {
        tabela.resize(tam, {, false, false});
    }

    void inserir(int valor) {
        int indice = funcaoHash(valor);
        
        while (tabela[indice].ocupado && !tabela[indice].deletado) {
            indice = (indice + 1) % tamanho;
        }
        
        tabela[indice] = {valor, true, false};
        ordemChegada.push_back(indice);
    }

    void remover(int valor) {
        int indice = funcaoHash(valor);
        
        while (tabela[indice].ocupado) {
            if (tabela[indice].key == valor) {
                tabela[indice].ocupado = false;
                tabela[indice].deletado = true;
                return;
            }
            indice = (indice + 1) % tamanho;
        }
    }

    void listarChaves() {
        for (int idx : ordemChegada) {
            if (tabela[idx].ocupado) {
                cout << tabela[idx].key << " ";
            }
        }
        cout << endl;
    }
};

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