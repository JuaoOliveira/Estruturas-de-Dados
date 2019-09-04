#include <iostream>
#include <new>
using namespace std;
template <typename T>
T*  soma_dos_vetores (T *vetor1,T *vetor2, int n)
{
    T *soma = new (nothrow) T [n];

    for (int i=0;i<n;++i) {
            soma [i] += vetor1[i] +  vetor2[i];
    }
    return soma;
}


int main (){
    int n=0;
    int m=0;
        cout << " Digite o tamanho do vetor 1 : " ; cin >> n;

            double *vetor1 = new double [n];

cout << "Digite os elementos do V1: " << "\n";

    for(int i=0;i<n;i++)    {
            cout << " Elemento " << i+1 << " : ";
        cin >> vetor1 [i];
    }

        cout << " Digite o tamanho do vetor 2 : " ; cin >> m;

            double *vetor2 = new double [m];

cout << "Digite os elementos do V2 :" << "\n ";

  for(int i=0;i<n;i++)      {
         cout << " Elemento " << i+1 << " : ";
        cin >> vetor2 [i];
}

double *vetor_soma = soma_dos_vetores <double> ( vetor1, vetor2 , n );

for(int i = 0; i < n; i++)
    cout << " soma do elemento " << i+1 << " : " << soma_dos_vetores <double> ( vetor1, vetor2 , n )[i] << '\n';

}