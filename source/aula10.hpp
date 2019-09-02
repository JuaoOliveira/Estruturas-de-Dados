#include <iostream>
#include <new>

using std::nothrow;

template <typename T>
struct Pilha {
    T *v;
    int ult, tam_v;

    bool inicializar(){
        v = new(nothrow) T[1];
        
        if(v == nullptr)
            return true; //Return true se der ERRO!!!

        ult = -1;
        tam_v = 1;
        return false;    
    }

    void terminar(){
        delete[] v;
    }

    bool vazia(){
        return ult == -1;
    }

    bool redimensionar(int tam_w){
        T *w = new(nothrow) T[tam_w];
        
        if(w == nullptr)
            return true;
        
        for(int i=0; i <= ult; ++i)
            w[i] = v[i];

        delete[] v;

        v = w;
        tam_v = tam_w;

        return false;    
    }

    bool empilhar(T e){
        if(ult == tam_v - 1){
            if(redimensionar(tam_v*2))
                return true; //houve erro
        }
        ++ult;
        v[ult] = e;
        return false; //sucesso
    }

    bool desempilhar(){
        --ult;
        if(!vazia() && 4*(ult+1) <= tam_v)
            if(redimensionar(tam_v/2))
                return true;
        return false;
    }

    T topo(){
        return v[ult];
    }
};