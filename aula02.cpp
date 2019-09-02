#include <iostream>

 using std::cout;

void trocar2 (int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

 int main (){
    int a = 1,b = 2;
    int *pA = &a, *pB = &b;

    trocar2(pA,pB);
    cout << "a: " << a << ", b: " << b << '\n';
}

