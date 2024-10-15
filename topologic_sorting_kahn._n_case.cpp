#include <bits/stdc++.h>
using namespace std;

// Algoritmo de ordenação topológica usando o algoritmo de Kahn
vector<int> topologicalSort(vector<vector<int>> &adj, int n) {
    vector<int> grau(n + 1, 0); // Inicializa o grau de entrada dos nós
    vector<int> resultado;      // Vetor para armazenar a ordenação topológica

    // Passo 1: Calcular o grau de entrada de cada nó
    for (int i = 1; i <= n; i++) {
        for (auto z : adj[i]) {
            grau[z]++;
        }
    }

    // Passo 2: Colocar todos os nós com grau de entrada zero na fila
    queue<int> fila;
    for (int i = 1; i <= n; i++) {
        if (grau[i] == 0) {
            fila.push(i);
        }
    }

    // Passo 3: Processar nós
    while (!fila.empty()) {
        int node = fila.front();
        fila.pop();
        resultado.push_back(node);

        // Para cada nó adjacente a 'node', decrementa o grau de entrada
        for (auto interacao : adj[node]) {
            grau[interacao]--;
            // Se o grau de entrada se torna zero, coloca na fila
            if (grau[interacao] == 0) {
                fila.push(interacao);
            }
        }
    }

    // Se o número de nós no resultado for diferente de n, há um ciclo.
    if (resultado.size() != n) {
        return {}; // Grafo contém um ciclo
    }

    return resultado; // Retorna a ordenação topológica
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        // Caso de término da entrada
        if (n == 0 && m == 0) {
            break;
        }

        // Inicializar lista de adjacência para o grafo
        vector<vector<int>> adj(n + 1);

        // Ler as relações de precedência
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        // Realizar a ordenação topológica
        vector<int> resultado = topologicalSort(adj, n);

        // Exibir o resultado ou indicar se há um ciclo
        if (!resultado.empty()) {
            for (auto task : resultado) {
                cout << task << " ";
            }
            cout << endl;
        } else {
            cout << "o grafo contem um ciclo" << endl;
        }
    }

    return 0;
}
