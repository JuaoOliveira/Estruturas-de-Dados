#include <new>

using namespace std;

template <typename T> struct Deque{
    T *vetor;
    int dir, esq, tamVetor;
};

template <typename T> bool inicializar(Deque<T> &d){
    d.vetor = new(nothrow) T[1];

    if(d.vetor == nullptr) return true;

    d.dir = -1; d.esq = -1; d.tamVetor = 1;
    return false;
    }

template <typename T> void terminar(Deque<T> &d){
    delete[] d.vetor;
}

template <typename T> bool vazio(Deque<T> &d){
    return (d.dir == -1 && d.esq == -1);
}

template <typename T> bool redimensionar_dir(Deque<T> &d, int novoTam){
    T *novoVetor = new(nothrow) T[novoTam];

    if(novoVetor == nullptr) return true;

    for(int i = 0; i <= d.dir; ++i) novoVetor[i] = d.vetor[i];

    delete[] d.vetor;
    d.tamVetor = novoTam;
    d.vetor = novoVetor;
    return false;
}

template <typename T> bool inserir_dir(Deque<T> &d, T elemento){
    if(d.dir == d.tamVetor -1)
        if(redimensionar_dir(d, d.tamVetor*2)) return true;
    
    d.vetor[++d.dir] = elemento;
    return false;
}

template <typename T> bool desempilhar_dir(Deque<T> &d){
    --d.dir;

    if(!vazio(d) && 4*(d.dir -1) <= d.tamVetor) 
        if(redimensionar_dir(d, d.tamVetor/2))
            return true;
            
    return false;
}

template <typename T> bool redimensionar_esq(Deque<T> &d, int novoTam){
    T *novoVetor = new(nothrow) T[novoTam];

    if(novoVetor == nullptr) return true;

    for(int i = 0; i <= d.dir; ++i) novoVetor[i+1] = d.vetor[i]; // copia os valores para o novo vetor

    delete[] d.vetor;
    d.tamVetor = novoTam;
    d.vetor = novoVetor;
    return false;
}

template <typename T> bool inserir_esq(Deque<T> &d, T elemento){
    if(d.esq == -1)
        if(redimensionar_esq(d, d.tamVetor+1)) return true;
      
    d.vetor[0] = elemento;
    return false;
}

template <typename T> bool desempilhar_esq(Deque<T> &d, T elemento){
    return false;
}