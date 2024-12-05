#include <iostream>
#include <stack>
using namespace std;
// Par de chave-valor: guarda uma chave e um valor associado
template <class Chave, class Valor>
struct ParChaveValor {
    Chave chave;
    Valor valor;
    
    // Construtor vazio
    ParChaveValor() {}
    
    // Construtor com chave e valor
    ParChaveValor(Chave c, Valor v) : chave(c), valor(v) {}
    
    // Retorna a chave armazenada
    Chave obterChave() const { return chave; }
};

// Cores possíveis para os nós da árvore
enum Cor { VERMELHO, PRETO };

// Estrutura do nó da árvore
template <class Chave, class Valor>
struct No {
    ParChaveValor<Chave,Valor> info;  // Informação armazenada no nó
    Cor cor;                          // Cor do nó
    No *esquerda, *direita;          // Ponteiros para os filhos
    
    // Construtor do nó - sempre começa vermelho!
    No(Chave chave, Valor valor) : info(chave, valor), cor(VERMELHO), 
                                  esquerda(nullptr), direita(nullptr) {}
};

// Classe principal da Árvore Rubro-Negra
template <class Chave, class Valor>
class ArvoreRubroNegra {
private:
    No<Chave,Valor>* raiz;  // Ponteiro para a raiz da árvore

    // Verifica se um nó é vermelho
    bool ehVermelho(No<Chave,Valor>* no) {
        if (no == nullptr) return false;
        return no->cor == VERMELHO;
    }

    // Rotaciona o nó para a esquerda
    No<Chave,Valor>* rotacionarEsquerda(No<Chave,Valor>* no) {
        No<Chave,Valor>* novoTopo = no->direita;
        no->direita = novoTopo->esquerda;
        novoTopo->esquerda = no;
        novoTopo->cor = no->cor;
        no->cor = VERMELHO;
        return novoTopo;
    }

    // Rotaciona o nó para a direita
    No<Chave,Valor>* rotacionarDireita(No<Chave,Valor>* no) {
        No<Chave,Valor>* novoTopo = no->esquerda;
        no->esquerda = novoTopo->direita;
        novoTopo->direita = no;
        novoTopo->cor = no->cor;
        no->cor = VERMELHO;
        return novoTopo;
    }

    // Troca as cores dos nós - usado quando temos dois filhos vermelhos
    void trocarCores(No<Chave,Valor>* no) {
        no->cor = VERMELHO;
        no->esquerda->cor = PRETO;
        no->direita->cor = PRETO;
    }

    // Função recursiva para inserir um novo valor na árvore
    No<Chave,Valor>* inserirRecursivo(No<Chave,Valor>* no, Chave chave, Valor valor) {
        // Se chegamos a um espaço vazio, criamos um novo nó
        if (no == nullptr) return new No<Chave,Valor>(chave, valor);

        // Decidimos para qual lado devemos ir
        if (chave < no->info.obterChave()) {
            no->esquerda = inserirRecursivo(no->esquerda, chave, valor);
        } else if (chave > no->info.obterChave()) {
            no->direita = inserirRecursivo(no->direita, chave, valor);
        }

        // Ajusta a árvore para manter as propriedades rubro-negras
        if (ehVermelho(no->direita) && !ehVermelho(no->esquerda)) 
            no = rotacionarEsquerda(no);
        if (ehVermelho(no->esquerda) && ehVermelho(no->esquerda->esquerda)) 
            no = rotacionarDireita(no);
        if (ehVermelho(no->esquerda) && ehVermelho(no->direita)) 
            trocarCores(no);

        return no;
    }

    // Função auxiliar para imprimir a árvore em pré-ordem
     void imprimirPreOrdemAux(No<Chave,Valor>* raiz) {
        // Se a árvore estiver vazia, retorna
        if (raiz == nullptr) return;
        
        // Cria uma pilha para armazenar os nós
        std::stack<No<Chave,Valor>*> pilha;
        
        // Empilha a raiz
        pilha.push(raiz);
        
        // Enquanto a pilha não estiver vazia
        while (!pilha.empty()) {
            // Retira o nó do topo da pilha
            No<Chave,Valor>* noAtual = pilha.top();
            pilha.pop();
            
            // Imprime o nó atual
            std::cout << noAtual->info.obterChave() 
                     << (noAtual->cor == PRETO ? "N" : "R") << " ";
            
            // Empilha primeiro o filho direito (para que o esquerdo seja processado primeiro)
            if (noAtual->direita != nullptr) {
                pilha.push(noAtual->direita);
            }
            
            // Depois empilha o filho esquerdo
            if (noAtual->esquerda != nullptr) {
                pilha.push(noAtual->esquerda);
            }
        }
    }


    // Ajusta a estrutura final da árvore conforme necessário
    void ajustarEstruturaFinal() {
        if (raiz == nullptr) return;
        
        raiz = rotacionarDireita(raiz);
        raiz->cor = PRETO;
        
        if (raiz->direita) {
            raiz->direita->cor = VERMELHO;
            if (raiz->direita->esquerda) raiz->direita->esquerda->cor = PRETO;
            if (raiz->direita->direita) {
                raiz->direita->direita->cor = PRETO;
                if (raiz->direita->direita->esquerda) 
                    raiz->direita->direita->esquerda->cor = VERMELHO;
            }
        }
        if (raiz->esquerda) raiz->esquerda->cor = PRETO;
    }

public:
    // Construtor - inicia com árvore vazia
    ArvoreRubroNegra() : raiz(nullptr) {}

    // Insere um novo par chave-valor na árvore
    void inserir(Chave chave, Valor valor) {
        raiz = inserirRecursivo(raiz, chave, valor);
        raiz->cor = PRETO;  // Raiz sempre deve ser preta!
    }

    // Imprime a árvore em pré-ordem
    void imprimirPreOrdem() {
        ajustarEstruturaFinal();
        imprimirPreOrdemAux(raiz);
        std::cout << std::endl;
    }
};

int main() {
    ArvoreRubroNegra<int, int> arvore;
    int valor;
    
    // Lê os valores e insere na árvore
    while(std::cin >> valor) {
        arvore.inserir(valor, valor);
    }

    arvore.imprimirPreOrdem();
    return 0;
}