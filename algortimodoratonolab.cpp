#include <iostream>
#define n 8
using namespace std;

int labirinto[n][n] = {
    {1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int soluction[n][n] = {0}; // Inicializa a matriz solução com zeros

void mostracaminho() {
    cout << "A solução do labirinto é:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << soluction[i][j] << " ";
        }
        cout << endl;
    }
}

bool lugarvalido(int x, int y) {  // Removido os asteriscos
    if(x >= 0 && x < n && y >= 0 && y < n && labirinto[x][y] == 1) {
        return true;
    }
    return false;
}

bool rato_soluction(int x, int y) {  // Removido os asteriscos
    // Se chegamos ao destino
    if(x == n-1 && y == n-1) {
        soluction[x][y] = 1;
        return true;
    }
    
    // Verifica se podemos usar esta célula
    if(lugarvalido(x, y)) {
        soluction[x][y] = 1;  // Marca o caminho
        
        // Move para a direita
        if(rato_soluction(x, y+1)) {
            return true;
        }
        
        // Move para baixo
        if(rato_soluction(x+1, y)) {
            return true;
        }
        
        // Se nenhum movimento funcionar, backtrack
        soluction[x][y] = 0;
        return false;
    }
    
    return false;  // Corrigido para retornar false
}

bool acharsolucao() {
    // Inicializa a matriz solução com zeros
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            soluction[i][j] = 0;
        }
    }
    
    if(rato_soluction(0, 0) == false) {
        cout << "Solução não existe" << endl;
        return false;
    }
    
    mostracaminho();
    return true;
}

int main() {
    acharsolucao();
    return 0;
}