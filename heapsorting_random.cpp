#include<bits/stdc++.h>

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

    //pulando a parte de valor da semente 
    srand((unsigned) time (NULL));

    int aleatorio = rand();
    
    vector<int> armazena{};

    for(int a=0;a<n;a++){ // assuming you want to add 10 random elements
        aleatorio = rand();
        armazena.push_back(aleatorio);
    }

    heapsorting(armazena);
    cout<<"array ordenado"<<endl;
    printarray(armazena);

    return 0;
}

