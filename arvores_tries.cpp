#include<iostream>

using namespace std;


//fazendo a inserção de uma arvore trie

public valor get(String chave){
    Node x = get(raiz, chave, 0);
    if(x == nullptr){
        return nullptr;
    }
    return x.valor;
}

private node get(Node x, String chave, int d){
    if(x == nullptr){
        return nullptr;
    }
    if(d == chave.length()){
        return x;
    }
    char c = chave.charAt(d);
    return get(x.proximo[c], chave, d+1);
}