#include <iostream>
#include <new>
#include "deque.hpp"

using namespace std;

int main(){
    Deque<int> D;
    if(inicializar(D)) return 1; //Erro

    //cout << D.vazio() << endl; //1 = True, 0 = False

    inserir_dir(D, 2);
    inserir_dir(D, 5);

    desempilhar_dir(D);

    for (int i = 0; i < D.tamVetor; i++) 
        cout << "Elemento " << i+1 << ": " << D.d[i] << ' ' << endl;
}
