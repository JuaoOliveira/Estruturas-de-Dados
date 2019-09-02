#include <iostream>

using std::cout;

int fatorial (int x){
  if (x <= 1)
    return 1;
  else
    return x * fatorial(x-1);
}

int main ()
  {
   cout << fatorial(3) << '\n';
  }