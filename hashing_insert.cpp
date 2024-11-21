#include<iostream>
#include<vector>
#define tamanho 4 

using namespace std;

struct Dataitem{
    int chave;
};

vector<Dataitem*> hasharray(tamanho, nullptr);

int hashcode(int chave){
    return chave % tamanho;
}

void insert(int chave){
    Dataitem *newitem = new Dataitem;

    newitem-> chave = chave;

    int hashindex = hashcode(chave);

    while(hasharray[hashindex] != nullptr){
        ++hashindex;

     //formula para o hash usando aritimetica modular 
        hashindex %= tamanho;

    }

}

    int main(){

        //consertar a entrada para mais valores 
        insert(64);
        insert(563);
        insert(56);
        insert(99);


        for(int a=0;a<tamanho;a++){
            if(hasharray[a]!= nullptr){
                cout<<"posição"<<a<<"chave:"<<hasharray[a]->chave<<endl;
            }else{
                cout<<"posição"<<a<<"chave: NULL"<<endl;
                }
            }
        
    
    return 0;
}