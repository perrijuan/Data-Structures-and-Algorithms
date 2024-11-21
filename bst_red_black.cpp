#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespce std; 


//criação da arvore red-black 


 
//estrutura da arvore binaria balanceada usando a preordem 

  struct Node{
    Node *parente;
    Node *esquerda;
    Node *direita;
    int cor;
  };typedef Node *Nodeptr;

  //estrutura da arvore red-black

class arvore_redblack{
  private :
    Nodeptr raiz;
    Nodeptr Tnull;
    void inicializa(Nodeptr node, Nodeptr parente){
      node->data = 0;
      node-> parente = parente;
      node-> direita = nullptr;
      node->esquerda = nullptr;
      node-> cor=0;

    }

    //pre ordem

    void preordemBSTredblack(Nodeptr node){
      if(node != tnull){
        cout<<node->data<<" ";
        preordemBSTredblack(node->esquerda)
        preordemBSTredblack(node->direita)

      }
    }

    //rotação 

    void esquerdarotation(Nodeptr node){
      Node *y = x->direita;
      x-> direita = y-> esquerda;

      if(y->esquerda !=TNULL){
        y->esquerda->parente=x;
      }
      y->parente = x->parente;
      
      if(x-> parente ==nullptr){
        this->raiz = y;
      }else if(x==x->parente->esquerda){
        x->parente->esquerda = y;
      }else{
        x->parente->direita=y;
      }

      y->esquerda=x;
      x->parente=y;

      }
    

    void direitaratation(Nodeptr node){
      Node* y = x -> esquerda;
      x-> esquerda = y -> direita;
      if(y-> esquerda !=TNULL){
        this-> raiz = y; 
        }else if(x == x -> parente -> esquerda){

        }else{
          x-> parente -> esquerda = y; 
        }
        y-> esquerda = x;
        x-> parente = y; 

    }


    


    //conserta arvore 
    
    void insert_conserta(Nodeptr z){
      Nodeptr u; 
      while(k-> parente-> cor == 1){
        //propriedade de balanceamento da arvore red black 
        if(k-> parente -> k-> parente -> parente -> esquerda){
            u = k-> parente -> parente -> esquerda; 
            u - > cor = 0;
            k - > parente -> cor = 0; 
            k = k -> parnete;
            //remover a recursao....
         }else{
          if(k = k-> parente-> direita){ 
          k = k-> parente; 
          esquerdarotation(k);
          }
        k -> parente-> cor =0;
        k-> parente -> parente-> cor = 1;
          direitaratation(k-> parente-> parente);
        }
      }
      if(k == raiz){
        break;
      }
      raiz-> cor = 0;
    }

      

    


    //inserção

    void insert(int chave){
      nodeptr node = new node; 
      node -> parente = nullptr;
      node -> data = chave ; 
      node -> esquerda = chave; 
      node -> direita = tnull;
      node -> cor = 1;
      nodeptr y = nullptr;
      nodeptr x = this->raiz;
      while(x!= tnull){
        y = x;
        if(node-> data < x->data){
          x = x -> esquerda;
        }else{
          x = x -> direita; 
        }
      }
      node-> parente = y;
      if(y == nullptr){
        raiz = node ; 
      }else if( node -> valor < y-> valor){
        y-> direita= node;
      }else{
         y-> diereita = node;
      }
      if(node -> parente == nullptr){
        return;
      }
      insert_conserta(node);
      return this-> raiz; 

    }


    void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }

    


//printa a arvore 

void printtree(Nodeptr raiz, string travessia, bool ultimo){
  if(root != tnull){
    cout<< travessia;
  }
  if(ultimo){
    cout<<"R-----";
    travessia+=" ";
  }else{
    cout<<"L-----";
    travessia+="|   ";
  }
  string scolor = raiz -> raiz-> cor ? "red " : "black";
  cout<<raiz-> valor<<" ("<<scolor<<") "<<endl;
  printtree(raiz->esquerda, travessia, false);
  printtree(raiz->direita, travessia, true); 
}
public:
arvore_redblack(){
  tnull = new node;
  tnull = cor = 0;
  tnull = esquerda = nullptr;
  tnull = direita = nullptr;
  raiz = tnull;
}

void preordem(){
  preordemBSTredblack(this-> raiz);
}



//main 

int main(){
  arvore_redblack arvore; 
  arvore.insert_conserta(57);
  arvore.insert_conserta(58);
  arvore.insert_conserta(59);
  arvore.insert_conserta(62);
  arvore.insert_conserta(63);
  arvore.insert_conserta(64);
  arvore.insert_conserta(65);
  arvore.insert_conserta(66);
  arvore.printtree();
  cout<<endl;
  
}


