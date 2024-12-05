#include <iostream>
#include <vector>
#include <set> // Para verificar valores únicos rapidamente
#define PRIME 4099 // Escolha inicial para n, deve ser um primo maior que o número de chaves esperadas

using namespace std;

// Estrutura para armazenar os dados
struct Dataitem {
    int chave;
};

// Função para calcular o índice do hash
int hashcode(int chave, int tamanho) {
    return chave % tamanho;
}

// Verifica se o número é primo
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Encontra o próximo primo maior ou igual a um dado número
int nextPrime(int num) {
    while (!isPrime(num)) ++num;
    return num;
}

// Inserir chave na tabela hash
bool insert(vector<Dataitem*>& hasharray, int chave, int tamanho, set<int>& usados) {
    int hashindex = hashcode(chave, tamanho);

    // Verificar se a posição está ocupada
    if (hasharray[hashindex] != nullptr) {
        cout << "Erro: Colisão detectada ao inserir a chave " << chave << endl;
        return false;
    }

    // Verificar se a chave já foi usada
    if (usados.count(chave)) {
        cout << "Erro: Chave duplicada detectada: " << chave << endl;
        return false;
    }

    // Inserir a chave
    Dataitem* newitem = new Dataitem;
    newitem->chave = chave;
    hasharray[hashindex] = newitem;

    // Marcar a chave como usada
    usados.insert(chave);
    return true;
}

// Função principal
int main() {
    int n = PRIME; // Tamanho inicial da tabela hash
    vector<Dataitem*> hasharray(n, nullptr); // Inicializa a tabela hash
    set<int> usados; // Conjunto para verificar valores únicos

    vector<int> valores; // Vetor para armazenar os valores de entrada
    cout << "Digite os valores a serem inseridos (-1 para terminar):\n";

    // Ler valores de entrada
    while (true) {
        int val;
        cin >> val;
        if (val == -1) break;
        valores.push_back(val);
    }

    // Verificar se precisamos aumentar o tamanho da tabela
    if (valores.size() > n) {
        cout << "Aumentando o tamanho da tabela para evitar colisões...\n";
        n = nextPrime(valores.size());
        hasharray.resize(n, nullptr); // Redimensionar a tabela hash
    }

    // Inserir os valores na tabela hash
    for (int val : valores) {
        if (!insert(hasharray, val, n, usados)) {
            cout << "Erro ao inserir o valor " << val << ", tente com outra tabela.\n";
        }
    }

    // Exibir o estado da tabela hash
    cout << "\nEstado da tabela hash:\n";
    for (int a = 0; a < n; a++) {
        if (hasharray[a] != nullptr) {
            cout << "Posição " << a << " -> Chave: " << hasharray[a]->chave << endl;
        }
    }

    // Limpar memória alocada
    for (int a = 0; a < n; a++) {
        if (hasharray[a] != nullptr) {
            delete hasharray[a];
            hasharray[a] = nullptr;
        }
    }

    return 0;
}
