#include <iostream>
#include <new>

using namespace std;

void hanoi(int num, int *origem, int *trab, int *dest){
    if(num > 0){
        hanoi(num-1, origem, dest, trab);
        
    }

}

int main(){

}