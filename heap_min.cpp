

#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
    int* array;
    int capacidade;
    int tamanho;
};

Heap* criarheap(int capacidade) {
    Heap* heap = new Heap;
    heap->array = new int[capacidade];
    heap->capacidade = capacidade;
    heap->tamanho = 0;
    return heap;
}

void trocar(int& a, int& b) {
    std::swap(a, b);
}

  /*
    

   lembrando que caso queira mudar para o heap min basta inverter o operador < tanto do heapfiltymax
   tanto da inserção 

  */  
 void heapifyMin(Heap* heap, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < heap->tamanho && heap->array[esquerda] < heap->array[menor])
        menor = esquerda;

    if (direita < heap->tamanho && heap->array[direita] < heap->array[menor])
        menor = direita;

    if (menor != i) {
        trocar(heap->array[i], heap->array[menor]);
        heapifyMin(heap, menor);
    }
}

void inserir(Heap* heap, int valor) {
    if (heap->tamanho == heap->capacidade) {
        std::cout << "heap está cheia, não pode adicionar mais" << std::endl;
        return;
    }

    int i = heap->tamanho++;
    heap->array[i] = valor;

    // Subir o elemento até que a propriedade de min-heap seja restaurada
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        trocar(heap->array[i], heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remover e retornar o mínimo da min-heap
int heapminimo(Heap* heap) {
    if (heap->tamanho == 0) {
        std::cout << "heap vazia, não pode achar o valor mínimo" << std::endl;
        return -1;
    }

    int minimo = heap->array[0];
    heap->array[0] = heap->array[heap->tamanho - 1];
    heap->tamanho--;

    heapifyMin(heap, 0);
    return minimo;
}

void printheap(Heap* heap) {
    std::cout << "elementos da heap:" << std::endl;
    for (int i = 0; i < heap->tamanho; i++) {
        std::cout << heap->array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Heap* heap = criarheap(10);
    inserir(heap, 22);
    inserir(heap, 42);
    inserir(heap, -12);
    inserir(heap, 34);
    inserir(heap, 35);
    inserir(heap, 44);
    inserir(heap, -9);
    inserir(heap, 89);
    inserir(heap, -90);
    inserir(heap, 88);

    printheap(heap);
    int minimo = heapminimo(heap);
    std::cout << "O valor mínimo da heap foi: " << minimo << std::endl;
    return 0;
}

