#include<iostream>
#include<cstdlib>

using namespace std;


int main(){


    //valor da nossa semente 

    srand((unsigned) time (NULL));
    

    //atribui o valor da semente a gerador rand
    cout<<"gerando n numeros aleatorios"<<endl; 
    for(int a=0;a<4556;a++){
    int aleatorio = rand();

    cout<<aleatorio<<endl;
}
    return 1;
}