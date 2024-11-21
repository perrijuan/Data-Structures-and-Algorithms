#include<iostream>

using namespace std;

const int inf = 999999;


int k,a,b,u,v,n, ne=1;

int mincost = 0;

int cost[3][3] = 
{{0,10,20},
 {12,0,15}, 
 {16,18,0}};

int parente[9]={0};

//caso base em que o caminho tem peso 0 
int acharcaminho(int i){
    while(parente[i]!=0){
        i = parente[i];
    }
     return i;
}

//função que vai unir os vertices

int unir(int i, int j){
    if(i != j){
        parente[j] = i;
        return 1;
    }
    return 0;
}

int main(){
    
    n=3;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cost[i][j]==0){
                cost[i][j] = inf;
            }
        }
    }
    cout<<"Arestas da arvore minima"<<endl;
    while(ne<n){
        int min_val = inf;
        for(int i=0;i<n;i++){
            for(int j = 0; j<n;j++){
                if(cost[i][j]<min_val){
                    min_val = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = acharcaminho(u);
        v = acharcaminho(v);
        if(unir(u,v)!= 0){
            cout<<a<<"-->"<<b<<"\n";
            mincost+=min_val;
        }
        cost[a][b] = cost[b][a] = 999;
        ne++;
    }
    cout<<"O custo minimo da arvore é"<<mincost<<endl;
    return 0;
}

