#include <iostream>
#include <new>
#include "deque.hpp"

using namespace std;

int main(){
    Deque<int> D;
    if(inicializar(D)) return 1; //Erro

    //cout << D.vazio() << endl; //1 = True, 0 = False

    inserir_dir(D, 2);
    inserir_dir(D, 6);
    inserir_dir(D, 3);
    inserir_dir(D, 8);

    inserir_esq(D,10);
    inserir_esq(D,1);
    inserir_esq(D,7);



    for (int i = 0; i < D.tamVetor; i++) 
        cout << "Elemento " << i+1 << ": " << D.vetor[i] << ' ' << endl;

    //cout << D.tamVetor;
}
