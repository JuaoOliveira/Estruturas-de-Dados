#include <iostream>

using namespace std;

void inverter(double *primeiro, double *ultimo){
    double *p, aux;

    for(p = ultimo; p >= primeiro; p--){
	    //cout << "v[" << ultimo-p << "]: " << *p << '\n';
        *(primeiro + (ultimo-primeiro)) = *p;
    }	
}

int main(){
    int n;

    cout << "Digite o numero de elementos do vetor: "; 
    cin >> n;

    double v[5];
    double *prim = v, *ult = v + (n - 1);
    

    
    for(int i = 0; i < n; i++){
        cout << "Digite um valor: ";
    	cin >> *(v + i); 
    }

     for(int i = 0;i < n; i++){
     	cout << "v[" << i << "] = " << *(v + i) << '\n';
     }

    cout << '\n';
    
    inverter(prim, ult);
}
