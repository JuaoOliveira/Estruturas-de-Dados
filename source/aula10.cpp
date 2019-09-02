#include <iostream>
#include <new>
#include "aula10.hpp"

using namespace std;

int main(){
    Pilha<int> p;
    int num;

    if(p.inicializar())
        return 1;

    for(;;){
        cout << "Digite um numero para empilhar (digite negativo para terminar): ";
        cin >> num; 
        
        if(num < 0) 
            break;
        
        if(p.empilhar(num))
            return 2;
    }

    cout << "Os numeros digitados, do ultimo para o primeiro foram: ";
    while(!p.vazia()){
        cout << p.topo() << ' ';
        if(p.desempilhar()) return 3;
    
    }

    p.terminar();
}