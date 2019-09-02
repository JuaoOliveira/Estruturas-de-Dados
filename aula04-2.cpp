#include <iostream>
#include <new>

using namespace std;

void trocar(char *ptrAntigo, char *ptrNovo, int n){
    for (int i = 0; i < n; i++)
        ptrNovo[i] = ptrAntigo[i];   
}

int main(){
    int n = 10;
    char *v = new(nothrow) char[n];
    char *v_aum;
    
	if(v == nullptr){
	 	cout << "A memoria nao foi alocada.";
	    return 1;
	}

    cout << "Digite uma frase de uma linha: ";
    for (int i = 0; i < n; ++i){
        cin.get(v[i]);
        if(v[i] == '\n')
            break;
		if(i == n-1) {
			v_aum = new char[n+=10];
			trocar(v, v_aum,n-10);
            delete[] v;
            v = v_aum;
		}
    }
	cout << v << endl;       
}
