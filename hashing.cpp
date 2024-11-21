#include<iostream>
//tamanho da tabela 
#include<unordered_map>

#define tamanho 34

using namespace std; 


//vamos fazer um algoritimo que faz a busca em um algoritimo de hash terminar a parte final do algoritimo 


struct Dataitem{
  int chave;
};
//defone nossa tabela hash usando mapa ou valor 
unordered_map<int, Dataitem*> hasharray; 


int hashcode(int chave){
  return chave % tamanho;
}

//algoritimo de busca 

struct Dataitem *busca(int chave){
  int hashindex = hashcode(chave);

  while(hasharray[hashindex]!= nullptr){
    if(hasharray[hashindex]-> chave == chave)
      return hasharray[hashindex];

    //ele passa para o proximo valor da tabela 
    ++hashindex;

    hashindex %= tamanho;

  }

  return NULL;
}

int main(){

  Dataitem item2 ={34};
  Dataitem item3 = {678};
  Dataitem item4 = {6784};
  
  int hashindex2 = hashcode(item2.chave);
  hasharray[hashindex2]= &item2;

  int hashindex3 = hashcode(item3.chave);
  hasharray[hashindex3]= &item3;

  int hashindex4 = hashcode(item4.chave);
  hasharray[hashindex4]= &item4;

  int chavebusca = 65466;
  Dataitem* resultado = busca(chavebusca);
  cout<<"o elemento pode ser achado : "<<chavebusca<<endl;
  if(resultado != nullptr){
    cout<<"elemento encontrado"<<endl;
  }else{
    cout<<"elemento nao encontrado"<<endl;
  }

  return 0;
  
}

