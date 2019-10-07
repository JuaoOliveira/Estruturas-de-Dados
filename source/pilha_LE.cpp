#include <iostream>
#include <new>
#include "pilha_LE.hpp"
using namespace std;

int main(){
	Pilha<int> p;
	p.inicializar();

	int opc, valor;

	cout << "1: Empilhar (valor)"<< endl;
	cout << "2: Desempilhar"<< endl;
	cout << "3: Consultar topo"<< endl;
	cout << "4: Testar vazio"<< endl;
	while(opc >= 0){
		cout << "Digite uma opcao (negativo para sair): ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Digite o valor a ser empilhado: ";
			cin >> valor;
			p.empilhar(valor);
			break;
		case 2:
			cout << p.desempilhar() << endl;
			break;
		case 3:
			cout << p.consultar_topo() << endl;
			break;
		case 4:
			p.vazia();
			break;
		}	
	}
}
