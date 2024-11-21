#include<iostream>
#include<algorithm>

using namespace std;
struct Heap{
  int* array;
  int capacidade;
  int tamanho;
};


//criar o heap e usa o vetor estatico para definir o tamanho da heap 
Heap* criarheap(int capacidade){

   Heap* heap = new Heap;
   heap -> array = new int[capacidade];
   heap-> capacidade = capacidade;
   heap-> tamanho = 0;
   return heap; 
}


//faz a troca das variaveis usando a função pronta swap 
void trocar(int& a, int& b) {
  std::swap(a, b);
}

//verificando se o filho esquerdo e maior que o pai 

/*

a base que se segue a definiçãa da heap sendo uma arvore completa e binaria onde o pai sempre e maior que seus filhos
a função heaprotacionar faz a verificação se o filho esquerdo e maior que o pai e se o filho direito e maior que o pai

o coração do algoritimo e a heap responsavel por fazer trocas 
*/

void heapifymax(Heap* heap, int i){
  //propriedadae da arvore heap  
  int maior = i;
  int esquerda = 2*i+1;
  int direita = 2* i+2;

 //faz a checagem dos nos da esquerda e da diereita para ver se o filho e maior que o pai 
  if (esquerda < heap->tamanho && heap->array[esquerda] > heap->array[maior])
    maior = esquerda;

  if(direita<heap->tamanho&& heap->array[direita]> heap->array[maior])
    maior=direita; 

  if(maior !=i){
    trocar(heap->array[i], heap->array[maior]);
    heapifymax(heap, maior);
  }

}


//inserir os valores para a heap e fazer o swap sempre que a condição entre pai e filho tiver alteração 

void inserir(Heap* heap, int valor){
  if(heap->tamanho==heap->capacidade){
    std::cout<<"heap esta cheio nao pode adicionar mais";
    return;
  }

int i = heap-> tamanho++;
heap -> array[i]= valor;

while(i != 0 && heap-> array[(i-1)/2]<heap-> array[i]){
  trocar(heap-> array[i], heap-> array[(i-1)/2]);
  i=(i-1)/2;

   }

}


// usando a heap para os valores de maximo 

int heapmaiximo(Heap* heap){
  if(heap->tamanho==0){
    std::cout<<"heap vazia, nao pode achar o valor maximo"<<std::endl;
    return -1;

  }

  //armazena o elemento na raiz 

  int maximo = heap->array[0];
  //troca a raiz pelo ultimo elemento 
  heap->array[0]= heap->array[heap->tamanho-1];
  heap->tamanho--;

  heapifymax(heap,0);
  return maximo;

}




void printheap(Heap* heap){
  std::cout<<"elementos da heap"<<std::endl;

  for(int i=0;i<heap->tamanho;i++){
    std::cout<<heap->array[i]<<" ";

  }
  std::cout<< std::endl; 
}

int main (int argc, char *argv[]) {
  Heap* heap = criarheap(10);
  inserir(heap, 22);
  inserir(heap, 42);
  inserir(heap, -12);
  inserir(heap, 34);
  inserir(heap, -6677);
  inserir(heap, 44);
  inserir(heap, -9);
  inserir(heap, 89);
  inserir(heap, -90);
  inserir(heap, 92);

  printheap(heap);
  int maximo = heapmaiximo(heap);
  
  std::cout<<"o valor maximo da heap foi: "<<maximo<<std::endl;
 
  return 0;
}

