#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;


class HashTable {
private:
    vector<int> table;
    int size;

    // Função hash usando dispersão quadrática

    //amanha
    int hash(int key, int attempt) {
        //return (key % size + attempt * attempt) % size;
        //fazendo usando a listagem linear 
        return key %= size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        // Tamanho da tabela deve ser primo
        size = encontrarProximoPrimo(tableSize * 2);
        table.resize(size, -1);
    }

    // Função para encontrar o próximo número primo
    int encontrarProximoPrimo(int n) {
        while (!ehPrimo(n)) {
            n++;
        }
        return n;
    }

    // Verificar se um número é primo
    bool ehPrimo(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        // Verificar divisibilidade até a raiz quadrada
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void insert(int key) {
        for (int attempt = 0; attempt < size; attempt++) {
            int index = hash(key, attempt);
            
            // Se slot estiver vazio, insere
            if (table[index] == -1) {
                table[index] = key;
                return;
            }
        }
        
       
    }

    void print() {
        //tamanho da tabela
        cout << size << endl;
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
               cout << "i " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {

  
   
        vector<int> valores;
        int value;
        while (cin >> value) {
            valores.push_back(value);
        }
        
        // Definir tamanho da tabela baseado na quantidade de valores
        int tableSize = valores.size() * 2;  // Dobro da quantidade para reduzir colisões
        
        // Criar tabela hash
        HashTable ht(tableSize);
        
        // Inserir todos os valores
        for (int val : valores) {
            ht.insert(val);
        }
        
        // Imprimir tabela
        ht.print();
        cout<<endl;
    

    return 0;
}