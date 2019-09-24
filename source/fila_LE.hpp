#include <new>
using std::nothrow;

template <typename T>
struct Fila
{
    struct Noh {T elem; Noh *prox;};

    Noh *ini, *fim;

    void inicializar() {ini == nullptr;}

    bool vazia() {return ini == nullptr;}

    bool enfilar(T e){
        Noh *n = new(nothrow) Noh;
        if(n == nullptr) return true;
        
        n->elem = e; 
        n->prox = nullptr;

        if(vazia()) 
            ini = (fim = n);
        else {
            fim->prox = n; 
            fim = n;
        }
        return false;
    }
    T desenfilar(){ //Pre cond: !vazia()
        T e = n->elem;
        Noh *n = ini;
        ini = n->prox;
        delete n; return e;
    }
};
