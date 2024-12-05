
#include <iostream>

const int TAM_MAXIMO = 100;

class HashTable {
private:
    int tam;
    int* tabela;

public:
    HashTable(int tam) : tam(tam) {
        tabela = new int[tam];
        for (int i = 0; i < tam; ++i) {
            tabela[i] = -1;
        }
    }

    ~HashTable() {
        delete[] tabela;
    }

    int hash(int valor) {
        return valor % tam;
    }

    void inserir(int valor) {
        int indice = hash(valor);
        while (tabela[indice] != -1) {
            indice = (indice + 1) % tam;
        }
        tabela[indice] = valor;
    }

    void remover(int valor) {
        int indice = hash(valor);
        while (tabela[indice] != valor && tabela[indice] != -1) {
            indice = (indice + 1) % tam;
        }
        if (tabela[indice] == valor) {
            tabela[indice] = -1;
        }
    }

    void listarChaves() {
        for (int i = 0; i < tam; ++i) {
            if (tabela[i] != -1) {
                std::cout << tabela[i] << std::endl;
            }
        }
    }
};

int main() {
    int tam;
    std::cin >> tam;

    HashTable hash(tam);

    char op;
    int valor;

    while (std::cin >> op) {
        if (op == 'i') {
            std::cin >> valor;
            hash.inserir(valor);
        } else if (op == 'r') {
            std::cin >> valor;
            hash.remover(valor);
        } else if (op == 'l') {
            hash.listarChaves();
        }
    }

    return 0;
}

