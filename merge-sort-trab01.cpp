#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Função para gerar números aleatórios
int gerarAleatorio(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Função para realizar a ordenação Merge Sort
void mergeSort(std::vector<int>& vetor) {
    if (vetor.size() <= 1) return;

    int meio = vetor.size() / 2;
    std::vector<int> esquerda(vetor.begin(), vetor.begin() + meio);
    std::vector<int> direita(vetor.begin() + meio, vetor.end());

    mergeSort(esquerda);
    mergeSort(direita);

    int i = 0, j = 0, k = 0;

    while (i < esquerda.size() && j < direita.size()) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < esquerda.size()) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < direita.size()) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

int main(int argc, char** argv) {
    int tamanho = 0;

    // Verifica se o argumento -m foi fornecido
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-m") {
            tamanho = std::stoi(argv[i + 1]);
            break;
        }
    }

    if (tamanho <= 0) {
        std::cerr << "Tamanho do vetor inválido." << std::endl;
        return 1;
    }

    // Gera números aleatórios para preencher o vetor
    std::srand(std::time(0));
    std::vector<int> vetor(tamanho);
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = gerarAleatorio(1, 100);
    }

    // Realiza a ordenação Merge Sort
    mergeSort(vetor);

    // Imprime o vetor ordenado
    std::cout << "Vetor ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
