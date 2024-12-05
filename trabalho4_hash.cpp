#include <iostream>
#include <vector>
#include <unordered_set>
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
    unordered_set<int> removidos; // Mantém o controle de valores removidos

    int funcaoHash(int chave) {
        return chave % tamanho;
    }

public:
    HashTable(int tam) : tamanho(tam) {
        tabela.resize(tam, {0, false, false});
    }

    void inserir(int valor) {
        int indice = funcaoHash(valor);
        int inicio = indice;

        // Procura por uma posição livre ou pela chave já existente
        while (tabela[indice].ocupado && tabela[indice].key != valor) {
            indice = (indice + 1) % tamanho;
            if (indice == inicio) return; // Tabela cheia
        }

        // Insere na tabela
        tabela[indice] = {valor, true, false};
        
        // Adiciona à ordem de chegada apenas se não foi previamente removido
        if (removidos.find(valor) == removidos.end()) {
            ordemChegada.push_back(valor);
        }

        // Caso tenha sido previamente removido, remove do conjunto de removidos
        removidos.erase(valor);
    }

    void remover(int valor) {
        int indice = funcaoHash(valor);
        int inicio = indice;

        while (tabela[indice].ocupado) {
            if (tabela[indice].key == valor) {
                tabela[indice].ocupado = false;
                tabela[indice].deletado = true;

                // Marca o valor como removido
                removidos.insert(valor);
                return;
            }
            indice = (indice + 1) % tamanho;
            if (indice == inicio) break;
        }
    }

    void listarChaves() {
        // Exibe apenas os valores que não foram removidos
        for (int valor : ordemChegada) {
            if (removidos.find(valor) == removidos.end()) {
                cout << valor << endl;
            }
        }
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
