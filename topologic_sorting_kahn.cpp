#include <bits/stdc++.h>
using namespace std;
//algoritimo de grafo usando a tecnina de kahn
vector<int> topologicalSort(vector<vector<int>> &adj, int v) {
    vector<int> grau(v, 0); // Inicializa o grau de entrada dos nós
    vector<int> resultado;  // Vetor para armazenar a ordenação topológica

    // Passo 1: Calcular o grau de entrada de cada nó
    for (int i = 0; i < v; i++) {
        for (auto z : adj[i]) {
            grau[z]++;
        }
    }

    // Passo 2: Colocar todos os nós com grau de entrada zero na fila
    queue<int> fila;
    for (int i = 0; i < v; i++) {
        if (grau[i] == 0) {
            fila.push(i);
        }
    }

    // Passo 3: Processar nós
    while (!fila.empty()) {
        int node = fila.front();
        fila.pop();
        resultado.push_back(node);

        // Para cada nó adjacente a node decrementa o grau de entrada
        for (auto interacao : adj[node]) {
            grau[interacao]--;
            // Se o grau de entrada se torna zero, coloca na fila
            if (grau[interacao] == 0) {
                fila.push(interacao);
            }
        }
    }

    // Passo 4: Verificar se todos os nós foram processados
    if (resultado.size() != v) {
        cout << "O grafo contém um ciclo." << endl;
        return {}; // Retorna vazio se houver ciclo
    }

    return resultado; // Retorna a ordenação topológica
}

int main() {
    int n = 6; // Número de vértices

    vector<vector<int>> edges = {
        {5, 4}, {1, 2}, {2, 3},
        {1, 3}, {1, 5}, 
    };

    // Representação do grafo como lista de adjacência
    vector<vector<int>> adj(n);

    // Construindo a lista de adjacência
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    // Realizando a ordenação topológica
    cout << "Ordenação topológica do grafo: ";
    vector<int> resultado = topologicalSort(adj, n);

    // Mostrando o resultado
    if (!resultado.empty()) {
        for (auto i : resultado) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
