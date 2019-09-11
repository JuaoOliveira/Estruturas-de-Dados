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

template <typename T> bool redimensionar(Deque<T> &d, int novoTam){
    T *novoVetor = new(nothrow) T[novoTam];

    if(novoVetor == nullptr) return true;

    for(int i = d.esq; i <= d.dir; ++i)
        novoVetor[i + ((d.tamVetor/2)-(d.tamVetor/4))] = d.vetor[i];

    d.tamVetor = novoTam;

    delete[] d.vetor;
    d.vetor = novoVetor;
    
    d.esq = ((d.tamVetor/2)-(d.tamVetor/4));
    d.dir = ((d.tamVetor/2)+(d.tamVetor/4)) - 1;
    return false;
}

template <typename T> bool inserir_dir(Deque<T> &d, T elemento){  
    if(vazio(d))
        d.esq = 0;
    else if(d.dir == d.tamVetor-1)
        if(redimensionar(d, d.tamVetor*2)) return true;
    ++d.dir;
    d.vetor[d.dir] = elemento;   

    return false;
}

template <typename T> T desempilhar_dir(Deque<T> &d){
    T elemento = d.vetor[d.dir];
    --d.dir;

    if(!vazio(d) && 4*(d.dir - d.esq+1) <= d.tamVetor) 
        if(redimensionar(d, d.tamVetor/2))
            return 1;
            
    return elemento;
}


template <typename T> bool inserir_esq(Deque<T> &d, T elemento){
    if(d.esq == 0)
        if(redimensionar(d, d.tamVetor*2)) return true;

    --d.esq; 
    d.vetor[d.esq] = elemento;
    return false;
}

template <typename T> T desempilhar_esq(Deque<T> &d){
    T elemento = d.vetor[d.esq];
    ++d.esq;
    
    if(!vazio(d) && 4*(d.dir - d.esq+1) <= d.tamVetor) 
        if(redimensionar(d, d.tamVetor/2))
            return 2;
            
    return elemento;
}