#include <iostream>

using std::cout; using std::cin;

int main(){
    double original[7], temp=0, num[7];

    for(int i=0;i<7;i++){
        cout << "Digite um numero: ";
        cin >> num[i];
    }
    cout << '\n';
 
    for(int i=0;i<7;i++){
	original[i] = num[i];
    }

    for(int i=0; i < 4; i++){
        temp = num[i];
	num[i] = num[7 - 1 - i];
        num[7 - 1 - i] = temp;
    }

    cout << "Matriz original: ";
    for(int i=0;i< 7;i++){
        //original[i] = num[i];
        cout << original[i] << ' ';
    }

    cout << '\n';
    cout << '\n';

    cout << "Matriz invertida: ";
    for(int i=0;i<7;i++){
        cout << num[i] << ' ';
    }

}
