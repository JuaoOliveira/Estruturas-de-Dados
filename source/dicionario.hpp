#include <new>
using std::nothrow;

template <typename X, typename Y>
struct Par {
    X x; Y y;
};

template <typename TC, typename TD> // TC = tipo de chave, TD = tipo de dado
struct Dicionario {
    Par<TC, TD> *v;
    int ult, tam_v;

    bool inicializar() {
        v = new(nothrow) Par<TC, TD>[1];
        if (v == nullptr) return true;

        ult = -1; tam_v = 1;
        return false;
    }

    void terminar() {
        delete[] v;
    }   

    bool vazio() {
        return ult == -1;
    }

    bool redimensionar(int tam_w) {
        Par<TC, TD> *w = new(nothrow) Par<TC, TD>[tam_w];
        if (w == nullptr) return true;

        for (int i = 0; i <= ult; i++)
            tam_w[i] = v[i];

        delete[] v;
        v = w;
        tam_v = tam_w;
        return false;
    }

    Par<TC, TD> procurar(TC c) {
        for (int i = 0; i <= ult; i++) {
            if (v[i].x == c) {
                Par<bool, TD> p;
                p.x = true;
                p.y = v[i].y;
                return p;
            }
        } 
        Par<bool, TD> p;
        p.x = false;
        return p;
    }

    Par<bool, bool> inserir(Tc c, Td, d) {
        Par<bool, bool> p = procurar(c);

        if (p.x) {
            Par<bool, bool> r;
            r.x = true;
            return r;
        }
        if (ult == tam_v - 1) {
            if (redimensionar(2 * tam_v)) {
                Par<bool, bool> r;
                r.x = false;
                r.y = true;
                return r;
            }
        }
        ++ult;
        v[ult].x = c;
        v[ult].y = d;
        Par<bool, bool> r = {false, false};
        return r;
    }

    Par<bool,bool> remover(TC c){
        int i = 0;
        while(v[i].c != c) i++;
        
        v[i].x = v[ult].x; --ult;
        if(!vazio() && 4*(ult+1) <= tam_v)
            if(redimensionar(tam_v/2)){
                Par<bool,bool> r;
                r.x = false;
                r.y = true;
                return r;
            }
        Par<bool,bool> r = {true, false};
        return r;
    }
};


