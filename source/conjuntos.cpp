#include <iostream>
#include "conjuntos.hpp"

using namespace std;

int main(){
    Conjunto<int> c;

    c.inicializar();

    c.inserir(3);
    c.inserir(666);
    c.inserir(4);
    c.inserir(12);
    c.inserir(7);
    c.remover(3);

    for (int i = 0; i <= c.ult; i++)
        cout << "elemento " << i << ": " << c.v[i] << endl;
    
}
