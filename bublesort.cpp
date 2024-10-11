#include<bits/stdc++.h>

using namespace std;

int bublesort(vector<int>&aux){
  int temp=0;
  //percore ate o fim do vetor 
  for(int x=0;x<aux.size();x++){
    //percore fazendo as trocas 
    for(int a =0;a<aux.size()-1;a++){
    if(aux[a]>aux[a+1]){
      temp=aux[a];
      aux[a]=aux[a+1];
      aux[a+1]=temp;
      }
    }
  }
  for(int z=0;z<aux.size();z++){
    cout<<aux[z]<<" ";
  }
  return 1;
}

int main(){
  vector<int> vetor{32,12,31,76,78,66,43,24};

  cout<<bublesort(vetor);
  return 0;
}
