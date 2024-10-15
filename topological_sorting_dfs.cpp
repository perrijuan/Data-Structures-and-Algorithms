#include<iostream>
#include<vector>
#include<algorithm>


//algoritimo de busca topologica 
//o metodo usa dfs logo nao vale para o trabalho

//por profundidade de torna mais facil....
int a;
//ajdacencia da lista do grafo pois grafos sao matrizes 
vector<vector<int>adj;
vector<bool> visitado;
vector<int> resposta;

void dfs(int v){
    visitado[v]=true;
    for(int u : adj[v]){
        if(!visitado[u])
        dfs(u);
    }
    resposta.push_back(v);
}

//comentario pode ser interensante usar o push back na pilha 

//esse codigo usa comando que nao sei buscar entender como funcia
void topological_sort(){
    visitado.assingn(n, false);
    resposta.clear();
    for(int i =0; i<n;i++){
        se(!visitado[i]){
            dfs(i);
        }
    }

    reverse(resposta.begin(), resposta.end());

}