#include <iostream>
#include <new>
#include "deque.hpp"


using namespace std;

int main(){
    Deque<int> D;
    if(inicializar(D)) return 1; //Erro
        
        cout << "\n##Inserir 71##\n";
        inserir_dir(D, 71);
        cout << "D.dir: "<< D.dir<<endl;
        cout << "D.esq: " << D.esq<<endl;

        cout << "\n##Inserir 760##\n";
        inserir_dir(D, 760);
        cout << "D.dir: "<< D.dir<<endl;
        cout << "D.esq: " << D.esq<<endl;

        cout << "\n##R E##\n";
        cout << remover_esq(D) << endl;
        cout << "D.dir: "<< D.dir<<endl;
        cout << "D.esq: " << D.esq<<endl;

        
        cout << "\n##Inserir 532##\n";
        inserir_esq(D,532);
        cout << "D.dir: "<< D.dir<<endl;
        cout << "D.esq: " << D.esq<<endl;
        
        cout << "\n##R D##\n";
        cout <<remover_dir(D) << endl;
        cout << "D.dir: "<< D.dir<<endl;
        cout << "D.esq: " << D.esq<<endl;

        for (int i = 0; i < D.tamVetor; i++)
            cout << "\nv[" << i << "]: " << D.vetor[i] << endl;
        cout << endl;

        cout << "Vazio? "<< vazio(D) << endl;
}