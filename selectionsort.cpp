#include <iostream>
#include <vector>
using namespace std;

int selectsort(vector<int>& aux){
  int temporario;
  for (int x=0;x<aux.size();x++){
    //vamos sempre atualizar a menor ou maior posicao 
    int min_position=x;
    for(int y=x+1;y<aux.size();y++){
      //fazemos a comp para trocar o min_position
      if(aux[y]<aux[min_position]){
        min_position=y;
          }
      if(x != min_position){
        //fazemos o swap da variavel 
        int temp = aux[x];
        aux[x]=aux[min_position];
        aux[min_position]=temp;
          }
        } 
      }
  //usamos um for reduzido para exibir a ordenacao 
    for(auto z : aux){
      cout<<z<< " ";
      }

    return 1;  
}






int main(){
  //nossa lista de vetores 
  vector<int> vetors {2,776,45,346,-765,54};
  
  cout<<selectsort(vetors);

  return 0;
}
