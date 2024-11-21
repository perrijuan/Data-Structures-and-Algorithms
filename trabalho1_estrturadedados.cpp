#include <bits/stdc++.h>

using namespace std;

// Função para gerar números aleatórios
int gerarAleatorio(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void bongoSort(vector<int>& vetor) {
    while (!is_sorted(vetor.begin(), vetor.end())) {
        random_shuffle(vetor.begin(), vetor.end());
    }
}

void bubleSort(vector<int>& vetor) {
    bool flag;
    for (int a = 0; a < vetor.size() - 1; a++) {
        flag = false;
        for (int b = 0; b < vetor.size() - 1; b++) {  // Ajuste para `size() - 1`
            if (vetor[b] > vetor[b + 1]) {
                swap(vetor[b], vetor[b + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

// Função para realizar a ordenação Merge Sort
void mergeSort(vector<int>& vetor) {
    if (vetor.size() <= 1) return;

    int meio = vetor.size() / 2;
    vector<int> esquerda(vetor.begin(), vetor.begin() + meio);
    vector<int> direita(vetor.begin() + meio, vetor.end());

    mergeSort(esquerda);
    mergeSort(direita);

    int i = 0, j = 0, k = 0;
    while (i < esquerda.size() && j < direita.size()) {
        if (esquerda[i] <= direita[j]) {
            vetor[k++] = esquerda[i++];
        } else {
            vetor[k++] = direita[j++];
        }
    }
    while (i < esquerda.size()) vetor[k++] = esquerda[i++];
    while (j < direita.size()) vetor[k++] = direita[j++];
}

int main(int argc, char** argv) {
    int tamanho = 0;
    string algoritmo;

    // Verifica se o argumento -m ou -b foi fornecido
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-m") {
            tamanho = stoi(argv[i + 1]);
            algoritmo = "merge";
            break;
        }
        if (string(argv[i]) == "-b") {
            tamanho = stoi(argv[i + 1]);
            algoritmo = "bubble";
            break;
        }
        if (string(argv[i]) == "-bo") {
            tamanho = stoi(argv[i + 1]);
            algoritmo = "bongo";
            break;
        }
    }

    if (tamanho <= 0) {
        cerr << "Tamanho do vetor inválido." << endl;
        return 1;
    }

    // Gera números aleatórios para preencher o vetor
    srand(time(0));
    vector<int> vetor(tamanho);
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = gerarAleatorio(1, 100);
    }

    // Escolhe o algoritmo de ordenação
    if (algoritmo == "merge") {
        mergeSort(vetor);
    } else if (algoritmo == "bubble") {
        bubleSort(vetor);
    } else if (algoritmo == "bongo") {
        bongoSort(vetor);
    } else {
        cerr << "Algoritmo de ordenação não especificado ou inválido." << endl;
        return 1;
    }

    // Imprime o vetor ordenado
    cout << "Vetor ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
