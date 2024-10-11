//algoritimo para arvores binarias 

#include<iostream>

using namespace std;
//estrutura da arvore 
struct No{
  int valor;
  No* esquerda;
  No* direita;
};

//criação do node para esqerda ou direita dependendo do valor 
No* criarNo(int valor){
  No* novoNo = new No;
  novoNo-> valor = valor;
  novoNo-> esquerda = nullptr;
  novoNo-> direita = nullptr;
  return novoNo;
}
//insere um valor na arvore 
void inserir(No*& raiz, int valor){
  if(raiz == nullptr){
    raiz = criarNo(valor);
    return;
}
if(valor<raiz->valor){
  inserir(raiz->esquerda, valor);
}else{
  inserir(raiz->direita, valor);
  }
}
//imprime o valor 
void imprimiremordem(No* raiz){
  if(raiz != nullptr){
    imprimiremordem(raiz->esquerda);
    cout<<raiz->valor<<" ";
    imprimiremordem(raiz->direita);
  }
}

int main(){
  No* raiz = nullptr;

  inserir(raiz, 5);
  inserir(raiz, 3);
  inserir(raiz, 7);
  inserir(raiz, 1);
  inserir(raiz, 9);
  
    cout << "Árvore em ordem: ";
    imprimiremordem(raiz);
    cout <<endl;

  return 0;
}



