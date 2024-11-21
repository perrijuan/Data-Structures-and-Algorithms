#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Estrutura de um nó da árvore

/*
esse algoritimo e uma arvore red-black que e uma arvore binaria de busca balanceada usando a preordem para a impressão dos valores 
usamos a pilha tanto para evitar a recursão quanto para a impressão dos valores em casos de arvores grandes
*/
struct Node {
    Node *parente;
    Node *esquerda;
    Node *direita;
    int cor;
    int data;
};
typedef Node *Nodeptr;

class arvore_redblack {
private:
    Nodeptr raiz;
    Nodeptr Tnull;

    void preordemBSTredblack(Nodeptr node) {
        if (node == Tnull) return;
        
        stack<Nodeptr> pilha;
        pilha.push(node);
        
        while (!pilha.empty()) {
            Nodeptr atual = pilha.top();
            pilha.pop();
            
            cout << atual->data << " ";
            
            if (atual->direita != Tnull) {
                pilha.push(atual->direita);
            }
            if (atual->esquerda != Tnull) {
                pilha.push(atual->esquerda);
            }
        }
    }

    void fixInsertion(Nodeptr k) {
        // Verifica se o nó e seu pai existem
        while (k != raiz && k->parente != nullptr && k->parente->cor == 1) {
            // Se o pai é filho direito do avô
            if (k->parente == k->parente->parente->direita) {
                Nodeptr tio = k->parente->parente->esquerda;
                
                // Caso 1: tio é vermelho
                if (tio != Tnull && tio->cor == 1) {
                    tio->cor = 0;
                    k->parente->cor = 0;
                    k->parente->parente->cor = 1;
                    k = k->parente->parente;
                } else {
                    // Caso 2: k é filho esquerdo
                    if (k == k->parente->esquerda) {
                        k = k->parente;
                        rotacaoDireita(k);
                    }
                    // Caso 3
                    k->parente->cor = 0;
                    k->parente->parente->cor = 1;
                    rotacaoEsquerda(k->parente->parente);
                }
            } else { // Se o pai é filho esquerdo do avô
                Nodeptr tio = k->parente->parente->direita;

                // Caso 1: tio é vermelho
                if (tio != Tnull && tio->cor == 1) {
                    tio->cor = 0;
                    k->parente->cor = 0;
                    k->parente->parente->cor = 1;
                    k = k->parente->parente;
                } else {
                    // Caso 2: k é filho direito
                    if (k == k->parente->direita) {
                        k = k->parente;
                        rotacaoEsquerda(k);
                    }
                    // Caso 3
                    k->parente->cor = 0;
                    k->parente->parente->cor = 1;
                    rotacaoDireita(k->parente->parente);
                }
            }
            if (k == raiz) break;
        }
        raiz->cor = 0;
    }

    void rotacaoEsquerda(Nodeptr x) {
        if (x == nullptr || x->direita == Tnull) return;
        
        Nodeptr y = x->direita;
        x->direita = y->esquerda;
        
        if (y->esquerda != Tnull) {
            y->esquerda->parente = x;
        }
        
        y->parente = x->parente;
        
        if (x->parente == nullptr) {
            this->raiz = y;
        } else if (x == x->parente->esquerda) {
            x->parente->esquerda = y;
        } else {
            x->parente->direita = y;
        }
        
        y->esquerda = x;
        x->parente = y;
    }

    void rotacaoDireita(Nodeptr x) {
        if (x == nullptr || x->esquerda == Tnull) return;
        
        Nodeptr y = x->esquerda;
        x->esquerda = y->direita;
        
        if (y->direita != Tnull) {
            y->direita->parente = x;
        }
        
        y->parente = x->parente;
        
        if (x->parente == nullptr) {
            this->raiz = y;
        } else if (x == x->parente->direita) {
            x->parente->direita = y;
        } else {
            x->parente->esquerda = y;
        }
        
        y->direita = x;
        x->parente = y;
    }

    void printtree(Nodeptr node) {
        if (node == Tnull) return;
        
        stack<pair<Nodeptr, int>> pilha;
        pilha.push({node, 0});
        
        while (!pilha.empty()) {
            auto [atual, nivel] = pilha.top();
            pilha.pop();
            
            cout << string(nivel * 4, ' ');
            string scolor = atual->cor ? "RED" : "BLACK";
            cout << atual->data << "(" << scolor << ")" << endl;
            
            if (atual->direita != Tnull) {
                pilha.push({atual->direita, nivel + 1});
            }
            if (atual->esquerda != Tnull) {
                pilha.push({atual->esquerda, nivel + 1});
            }
        }
    }

public:
    arvore_redblack() {
        Tnull = new Node;
        Tnull->cor = 0;
        Tnull->esquerda = nullptr;
        Tnull->direita = nullptr;
        Tnull->parente = nullptr;
        raiz = Tnull;
    }

    void insert(int key) {
        Nodeptr node = new Node;
        node->parente = nullptr;
        node->data = key;
        node->esquerda = Tnull;
        node->direita = Tnull;
        node->cor = 1;
        
        Nodeptr y = nullptr;
        Nodeptr x = this->raiz;
        
        while (x != Tnull) {
            y = x;
            x = (node->data < x->data) ? x->esquerda : x->direita;
        }
        
        node->parente = y;
        
        if (y == nullptr) {
            raiz = node;
        } else if (node->data < y->data) {
            y->esquerda = node;
        } else {
            y->direita = node;
        }
        
        if (node->parente == nullptr) {
            node->cor = 0;
            return;
        }
        
        if (node->parente->parente == nullptr) {
            return;
        }
        
        fixInsertion(node);
    }

    void preordem() {
        preordemBSTredblack(this->raiz);
    }

    void print() {
        printtree(raiz);
    }
};

//fazer entrada de valores usando rand para gerar os valores aleatorios da arvore 

int main() {
    arvore_redblack arvore;
    
    cout << "Inserindo elementos...\n";
    int a;
    //quantidade de valores aleatorios
    cin>>a; 

    srand((unsigned) time (NULL));

    vector<int> armazena{};

    //gerando valores aleatorios
    int limite = 100;
    for(int quantidade=0;quantidade<a;quantidade++){
        int aleatorio = rand()% limite;
        armazena.push_back(aleatorio);
    }
    //inserindo valores na arvore
    for(int i =0; i<armazena.size();i++){
        arvore.insert(armazena[i]);
    }

    
    cout << "Pré-ordem: ";
    arvore.preordem();
    cout << "\n\nEstrutura da árvore:\n";
    arvore.print();
    
    return 0;
}