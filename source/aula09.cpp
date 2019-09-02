#include <iostream>
#include <new>

using namespace std;


//Polimorfismo paramétrico
template <typename T>
T soma_vet(T *v, int n){
    T soma = 0;

    for(int i=0; i < n; ++i)
        soma += v[i];

    return soma;
}


int main(){
    
    double v_double[3] = {1.25,2.25,3.5};
    int v_int[3] = {1,2,3};

    double soma_double = soma_vet<double>(v_double, 3);
    int soma_int = soma_vet<int>(v_int, 3);

    cout << "Soma do vetor de double: " << soma_double << endl;
    cout << "Soma do vetor de int: " << soma_int << endl;
}