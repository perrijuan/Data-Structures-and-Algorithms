#include<iostream>
#define tamanho 5
using namespace std;

struct data * busca(int chave){
  int hash_valor = hashcode(chave);

  while(hasharray[hash_valor] != null){
    if(hasharray[hash_valor]-> chave == chave){
      return hasharray[hash_valor];
    }
    //passa para o proximo posicao
    ++hash_valor;

    hash_valor % tamanho;

  }

  return null;
}
