#include <new>
using std::nothrow;

struct DuasPilhas {
	double *vetor;
	int tam_v, topo1, topo2;
}

void inicializar(DuasPilhas &P, double *v, int n){
	P.vetor = v;
	P.topo1 = -1;
	P.topo2 = n; P.tam_v = n;
}

double *terminar(DuasPilhas &P){
	return P.vetor;
}

bool vazia1(DuasPilhas &P){
	return P.topo1 == -1;
}

bool vazia2(DuasPilhas &P){
	return P.topo2 == P.tam_v;
}

bool cheia(DuasPilhas &P){
	return (P.topo1 - P.topo2 == -1);
}

void empilhar1(DuasPilhas &P, double d){
	P.vetor[++P.topo] = d;
}

void empilhar2(DuasPilhas &P, double d){
	P.vetor[--P.topo2] = d;
}

double consultarTopo1(DuasPilhas &P){
	return P.vetor[P.topo1];
}

double consultarTopo2(DuasPilhas &P){
	return P.vetor[P.topo2];
}

void desempilhar1(DuasPilhas &P){
	--P.topo1;
}

void desempilhar2(DuasPilhas &P){
	++P.topo2;
}