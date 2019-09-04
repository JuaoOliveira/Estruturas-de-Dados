#include <iostream>
#include <new>
#include "deque.hpp"

using namespace std;

int main(){
    Deque<double> D;
    if(D.inicializar()) return 1; //Erro

    cout << D.vazio() << endl; //1 = True, 0 = False
}
