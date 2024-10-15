#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;



int geraaleatorio(int min, int max){
    return min +(rand() % (max - min +1));
}



void mergesort(vector<int>& vetor ){
  if(vetor.size() <= 1){
    return;
  }
  
  int meio = vetor.size()/2;
  vector<int> esquerda(vetor.begin(), vetor.begin()+ meio);
  vector<int> direita(vetor.begin() + meio, vetor.end());

  //quebras recursivas 
  mergesort(esquerda);
  mergesort(direita);

  int i=0;
  int j=0;
  int k=0;


  while(i < esquerda.size() && j < direita.size()){
    if(esquerda[i]<=direita[j]){
      vetor[k]= esquerda[i];
      i++;
    }else{
      vetor[k]=direita[j];
      j++;
    }
    k++;
  }

  while(i<esquerda.size()){
    vetor[k]=esquerda[i];
    i++;
    k++;
  }
  
  while(j<direita.size()){
    vetor[k]=direita[j];
    j++;
    k++;
  }

}

int main(int argc, char** argv){
  int tamanho =0;
  
 //verifica se o argumento -m foi colocado 
 
  for(int i=1;i<argc;i++){
    if(string(argv[i])=="-m"){
      tamanho = stoi(argv[i+1]);
      break;
    }
  }
  if(tamanho<0){
    cerr<<"tamanho invalido do vetor"<<endl;
    return 1;
  }

  //numeros aleatorios 
  
  srand(time(0));
  vector<int> vetor(tamanho);
  for(int i=0;i<tamanho;i++){
    vetor[i]=geraaleatorio(1,100);
  }

  mergesort(vetor);

  cout<<"vetor ordenado :";

  for(int i=0;i<tamanho;i++){
    cout<<vetor[i]<< " ";
  }
  //pula para a proxima linha a saida 
  cout<<endl;

  return 0;
}
