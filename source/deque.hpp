#include <new>

using namespace std;

template <typename T>
struct Deque {
    T *d;
    int dir, esq, tamVetor;

    bool inicializar(){

        d = new(nothrow) T[1];

        if(d == NULL) return true;

        dir = -1; esq = -1; tamVetor = 1;

        return false;
    }

    void terminar(){
        delete[] d;
    }

    bool vazio(){
        return (dir == -1 && esq == -1);
    }

    bool redimensionar(int novoTam)

    bool inserir_dir(T elemento){
        if(dir == tamVetor -1)
            if(redimensionar(tamVetor*2)) return true;
        
        v[++dir] = elemento;
        esq = 0; // se eu chamar v[esq] ele retorna o 1º elemento do deque
        return false;
    }

    bool inserir_dir(T elemento){
        if(dir == tamVetor -1)
            if(redimensionar(tamVetor*2)) return true;
        
        return false;
    }

};
