#include <new>

using namespace std;

template <typename T> struct Deque{
    T *d;
    int dir, esq, tamVetor;
};

template <typename T> bool inicializar(Deque<T> &d){
    d.d = new(nothrow) T[1];

    if(d.d == nullptr) return true;

    d.dir = -1; d.esq = -1; d.tamVetor = 1;
    return false;
    }

template <typename T> void terminar(Deque<T> &d){
    delete[] d;
}

template <typename T> bool vazio(Deque<T> &d){
    return (d.dir == -1 && d.esq == -1);
}

template <typename T> bool redimensionar_dir(Deque<T> &d, int novoTam){
    T *w = new(nothrow) T[novoTam];

    if(w == nullptr) return true;

    for(int i = 0; i <= d.dir; ++i) w[i] = d.d[i];

    delete[] d.d;
    d.tamVetor = novoTam;
    d.d = w;
    return false;
}

template <typename T> bool inserir_dir(Deque<T> &d, T elemento){
    if(d.dir == d.tamVetor -1)
        if(redimensionar_dir(d, d.tamVetor*2)) return true;
    
    ++d.dir; d.d[d.dir] = elemento;
    //esq = 0; // se eu chamar v[esq] ele retorna o 1º elemento do deque
    return false;
}

template <typename T> bool desempilhar_dir(Deque<T> &d){
    --d.dir;

    if(!vazio(d) && 4*(d.dir -1) <= d.tamVetor) 
        if(redimensionar_dir(d, d.tamVetor/2))
            return true;
            
    return false;
}

template <typename T> bool inserir_esq(Deque<T> &d, T elemento){
        if(d.esq == d.tamVetor -1)
            if(redimensionar_dir(d, d.tamVetor*2)) return true;
        
        ++d.esq; d.d[d.esq] = elemento;
        return false;
    }