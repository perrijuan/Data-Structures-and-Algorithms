#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

//estrutura de heap 
void heapconserta(vector<int>& arr, int n, int i){
    int maior = i;

   //define os filhos da arvore para o heapsorting  

    int esq = 2*i+1;
    int dir = 2*i+2;

    if(esq<n&&arr[esq]> arr[maior])
        maior = esq; 

    if(dir<n&& arr[dir]>arr[maior])
        maior = dir;

    if(maior!=i){
        swap(arr[i], arr[maior]);
        heapconserta(arr,n,maior);
    }

}


//função que vai chamar a função de consertar o heap gerando o sorting 
void heapsorting(vector<int> &arr){
    int tamanho = arr.size();

    for(int i = tamanho /2 - 1; i>=0;i--){
        heapconserta(arr,tamanho,i);
    }

    for(int i=tamanho-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapconserta(arr,i,0);

    }
}

void printarray(vector<int> &arr){
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
  //algoritmo de heapsorting com numeros grandes aleatorios 
   vector<int> armazena{};
   int n = 4789;

   //valor da semente 
   srand(static_cast<unsigned>(time(NULL)));
   
   //valor da semente do gerador de numeros aleatorios 
   for(int a=0; a<n; a++){
    int aleatorio = rand();
    armazena.push_back(aleatorio);
   }

   heapsorting(armazena);
   cout<<"array ordenado"<<endl;
   printarray(armazena);


   //faz a verificação se os valores foram ordenados 
   if(is_sorted(armazena.begin(), armazena.end())){
         cout<<"array ordenado"<<endl;
   }

    return 0;
}
