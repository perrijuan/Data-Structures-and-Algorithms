#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

//usando o algoritimo de huffman para codificar uma string 



//criamos a estrutura do no da nossa arvore 

struct Node{
 Node * esquerda;
 Node * direita;
 Node * sufixo;
 //percorrer a fila 
 Node * prox;  
 char letra;

 //inicializamos nossa estrutura e definimos os valores iniciais como nulos 

 node(char c = '\0', int freq = 0):
    letra(c), 
    frequencia(freq),
    esquerda(nullptr), 
    direita(nullptr), 
    sufixo(nullptr),
    prox(nullptr){};

 }

void arquivo(){
 unsigned char c  [] = "entrada para testar a arvore que vamos ter que fazer usando um arquivo e por isso vou e estou escrevendo coisas aleatorias";
 int tam = sizeof(c)/sizeof(c[0]);

}


//armazena as frequencias no map 





//fazendo a entrada do arquivo para a contagem de frequencia e o tamanho do texto 




//leitura da string e contagem de frequencia

void frequencia(String s){
    int freq[256]={0};
    //str sao vistas como vet logo podemos acessar os elementos como vetores 
    for(int i=0;i<s.size();i++){
        freq[s[i]]++;
    }
    for(int i=0;i<256;i++){
        if(freq[i]>0){
            cout<<char(i)<<" "<<freq[i]<<endl;
        }
    }
}

//criamos a arvore de huffman
//temos que usar a travessia que vamos usar o dfs 



void huffman()




//armazenamento dos valores na fila de prioridade sera feito usando mapas