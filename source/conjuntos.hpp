#include <new>

using std::nothrow;

template <typename T>
struct Conjunto{

    struct Iterador {
        T *p;

        bool operator!= (const Iterador &I){
            return p != I.p;
        }
        T& operator*(){
            return *p;
        }

        Iterador& operator++(){
            ++p;
            return *this;
        }
    };

    T *v;
    int tamVetor, ult;

    bool inicializar(){
        v = new(nothrow) T[1];

        if(v == nullptr) return true;

        tamVetor = 1;
        ult = -1;

        return false;
    }

    bool redimensionar(int novo_tam){
        T *novo_v = new(nothrow) T[novo_tam];

        if(novo_v == nullptr) return true;

        for (int i = 0; i <= ult; ++i) novo_v[i] = v[i];

        tamVetor = novo_tam;
        delete[] v;
        v = novo_v;

        return false;
    }

    bool vazio(){
        return ult == -1;
    }

    bool inserir(T e){
        if(ult == tamVetor - 1) 
            if(redimensionar(tamVetor*2)) return true;

        v[++ult] = e;
        return false;
    }

    bool pertence(T e){
        for(int i = 0; i <= ult; ++i)
            if(v[i] == e) return true;

        return false;
    }

    bool remover(T e){
        int i = 0;

        while(v[i] != e) ++i;
        
        v[i] = v[ult];
        --ult;
        
        if(!vazio() && 4*(ult+1) <= tamVetor)  
            if(redimensionar(tamVetor/2)) return true;
        
        return false;
    }
};