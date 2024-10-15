#include<bits/stdc++.h>

using namespace std;
//usando ajacencia para o pecorrimento do grafo 
//comentar o passo a passso do algoritimo 

void topologic_sort(vector<int> adj[], int n){
  vector<int> grau(n,0)

    for(int i = 0; i<n; i++){
      for(auto z :adj[i]){
          grau[z]++;
      }
    }

  vector<int> resposta;
  queue<int> fila;

  //adiciona na fila para a ordenacao 
  for(int i=0; i< n;i++){
    if(grau[i]==0){
      fila.push(i);
    }
  }

  while(!fila.empty()){
    int node = fila.front();
    ans.push_back(node);

    for(auto a : adj[node]){
    grau--;
    if(grau[a]==0){
      fila.push(a);
    }

    }
  }

for(int q =0;q<n;i++){
  cout<< resposta[q]<< " ";

}
if(resultado.size()!=)

};


void addvertices(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
}


int main(){
  int n = 5;
  addvertices(adj, 5,0);
  addvertices(adj, 5,2);
  addvertices(adj, 2,3);
  addvertices(adj, 1,3);
  addvertices(adj, 1,5);
  addvertices(adj, 0,0);
  //continuar 
  
  //adicionar a entrada pelo agrv 
 
 return 0;
}


