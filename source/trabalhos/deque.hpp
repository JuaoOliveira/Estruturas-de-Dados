#include <new>
#include <iostream>

using namespace std;

template <typename T> struct Deque{
    T *vetor;
    int dir, esq, tamVetor;
};

template <typename T> bool inicializar(Deque<T> &d){
    //cria um vetor com tamanho 1
    d.vetor = new(nothrow) T[1];
    //Testa alocação
    if(d.vetor == nullptr) return true; //true se houver erro
    //aponta os indices para vazio
    d.dir = d.esq = -1;
    d.tamVetor = 1;
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
    //Passa os elementos da esquerda pra direita para o vetor novo
    if(d.dir >= d.esq)
        for(int i =0; i < d.tamVetor;i++)
            novoVetor[i] = d.vetor[i];
    else if(d.dir < d.esq){
        int i;
        for(i = 0; d.esq + i < d.tamVetor;i++)
            novoVetor[i] = d.vetor[d.esq + i];
        
        for(int u = 0; u <= d.dir;u++)
            novoVetor[i+u] = d.vetor[u];
    }

    delete[] d.vetor;
    d.vetor = novoVetor;

    d.esq = 0; 
    d.dir = d.tamVetor-1;
    d.tamVetor = novoTam;
    return false;
}

template <typename T> T remover_dir(Deque<T> &d){
    T elemento = d.vetor[d.dir];
    // se tiver apenas um elemento
    if (d.dir == d.esq){
        d.dir = -1; d.esq = -1;
    }
    // d.dir depois do d.esq
    else if(d.dir > d.esq) 
        d.dir--;

    // d.dir antes do d.esq
    else if(d.dir < d.esq) {
        if(d.dir == 0) 
            d.dir = d.tamVetor-1;
        else 
            d.dir--;
        
    }
    return elemento;
}

template <typename T> T remover_esq(Deque<T> &d){
    T elemento = d.vetor[d.esq];
    // se tiver apenas um elemento
    if (d.dir == d.esq){
        d.dir = -1; 
        d.esq = -1;
    }

    else if(d.esq < d.dir) 
        d.esq++;
    
    // d.dir antes do d.esq
    else if(d.esq > d.dir) {
        if(d.esq == d.tamVetor-1)
            d.esq = 0;
        else
            d.esq++;
        
    }

    return elemento;
}

template <typename T> bool inserir_dir(Deque<T> &d, T elemento){
    if(vazio(d)){
        d.dir = d.esq = 0;
        d.vetor[d.dir] = elemento;
        return false;
    } else if(d.dir == d.tamVetor-1){
        if(d.esq == 0){
            if(redimensionar(d, d.tamVetor*2)) return true;
            ++d.dir;
        } else
            d.dir = 0;
        

    } else if(d.dir >= d.esq)
        ++d.dir;
      else if(d.dir < d.esq){
        if(d.dir + 1 == d.esq)
            if(redimensionar(d, d.tamVetor*2)) return true;
        
        ++d.dir;
    }

    d.vetor[d.dir] = elemento;
    return false;
}

template <typename T> bool inserir_esq(Deque<T> &d, T elemento){
    if(vazio(d))
        d.dir = d.esq = 0;
    else if(d.esq == 0){
        if(d.dir == d.tamVetor-1)
            if(redimensionar(d, d.tamVetor*2)) return true;
        
        d.esq = d.tamVetor-1;

    } else if(d.esq <= d.dir)
        --d.esq;
      else if(d.esq > d.dir){
        if(d.dir + 1 == d.esq){
            if(redimensionar(d, d.tamVetor*2)) return true;
            d.esq = d.tamVetor-1;
        } else
            d.esq--;
    }

    d.vetor[d.esq] = elemento;
    return false;
}