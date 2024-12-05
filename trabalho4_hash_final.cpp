#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    int tam;
    list<int>* tabela;

public:
    HashTable(int tam) : tam(tam) {
        tabela = new list<int>[tam];
    }

    ~HashTable() {
        delete[] tabela;
    }

    int hash(int valor) {
        return valor % tam;
    }

    void inserir(int valor) {
        int indice = hash(valor);
        tabela[indice].push_back(valor);
    }

    void remover(int valor) {
        int indice = hash(valor);
        tabela[indice].remove(valor);
    }

    void listarChaves() {
        for (int i = 0; i < tam; ++i) {
            cout << "Índice " << i << ": ";
            for (int valor : tabela[i]) {
                cout << valor << " ";
            }
            cout << endl;
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