#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#define tamanho 4096 // Tamanho fixo da tabela hash sem colisoes e coalecencia da tabela hash com tamanho n 


//codigo gera colisoes e na tabela hash
using namespace std;

// Estrutura para armazenar os dados
struct Dataitem {
    int chave;
};

// Tabela hash inicializada com nullptr
vector<Dataitem*> hasharray(tamanho, nullptr);

// Função para calcular o índice do hash
int hashcode(int chave) {
    return chave % tamanho;
}

// Inserir chave na tabela hash
void insert(int chave) {
    Dataitem* newitem = new Dataitem;
    newitem->chave = chave;

    int hashindex = hashcode(chave);

    // Resolver colisões com sondagem linear
    while (hasharray[hashindex] != nullptr) {
        ++hashindex;
        hashindex %= tamanho; // Usar aritmética modular para circular o índice
    }

    hasharray[hashindex] = newitem; // Inserir na posição correta
}

// Função principal
int main() {
    vector<int> valores; // Vetor para armazenar os valores
    string entrada;

    cout << "Digite os valores (-hs seguido pelos números, termine com EOF):\n";

    // Ler linha por linha até EOF
    while (getline(cin, entrada)) {
        stringstream ss(entrada);
        string token;

        // Ignorar a flag "-hs" na primeira linha
        if (valores.empty()) {
            ss >> token;
            if (token != "-hs") {
                cerr << "Erro: flag '-hs' esperada no início da entrada!" << endl;
                return 1;
            }
        }

        // Ler valores numéricos da linha
        while (ss >> token) {
            try {
                int val = stoi(token); // Converte o token para inteiro
                valores.push_back(val);
            } catch (exception& e) {
                cerr << "Erro: valor inválido encontrado: " << token << endl;
                return 1;
            }
        }
    }

    // Inserir os valores na tabela hash
    for (int val : valores) {
        insert(val);
    }

    // Exibir o estado da tabela hash
    cout << "\nEstado da tabela hash:\n";
    for (int a = 0; a < tamanho; a++) {
        if (hasharray[a] != nullptr) {
            cout << "Posição " << a << " -> Chave: " << hasharray[a]->chave << endl;
        }
    }

    // Limpar memória alocada
    for (int a = 0; a < tamanho; a++) {
        if (hasharray[a] != nullptr) {
            delete hasharray[a];
            hasharray[a] = nullptr;
        }
    }

    return 0;
}