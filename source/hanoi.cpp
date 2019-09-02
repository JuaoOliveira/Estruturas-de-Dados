#include <iostream>
#include <new>

using namespace std;

void hanoi(int num, char origem, char destino, char trabalho){
    if(num > 0){
        hanoi(num-1, origem, trabalho, destino);
        cout << origem << " -> " << destino << endl;
        hanoi(num-1, trabalho, destino, origem);
    }

}

int main(){
    int numDiscos;

    cout << "Digite o numero de discos: ";
    cin >> numDiscos;

    hanoi(numDiscos, 'A', 'B', 'C');
}