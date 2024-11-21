#include<iostream>
# define n 16
using namespace std;

int labirinto[n][n] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};



//função para imprimir a solução

int soluction[n][n] = {0};

void mostracaminho(){
    cout<<"A solução do labirinto é:"<<endl;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<soluction[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool lugarvalido(int x, int y){
    if(x>=0 && x<n && y>= 0 && y<n && labirinto[x][y]==1){
        return true;
    }
    return false;
}

bool rato_soluction(int x, int y){
    if(x == n-1 && y == n-1){
        soluction[x][y] = 1;
        return true;
    }

    if(lugarvalido(x,y)== true){
        soluction[x][y] = 1;
        if(rato_soluction(x+1,y)== true){
            return true;
        }
        if(rato_soluction(x, y+1) == true){
            return true;
        }
        soluction[x][y] = 0;
        return false;

    }
    return false;
}


bool acharsolucao(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            soluction[i][j] = 0;
        }
    }

    if(rato_soluction(0,0)==false){
        cout<<"solução não existe";
        return false;
    }
      mostracaminho();
    return true;
}


int main(){

    acharsolucao();
    return 0;
}


