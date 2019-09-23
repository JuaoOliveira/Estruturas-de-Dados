#include <iostream>
#include <new>
#include "pilha_LE.hpp"
using namespace std;

int main(){
	Pilha<int> p;
	p.inicializar();

	int opc, valor;
	p.empilhar(1);
	p.empilhar(6);
	p.empilhar(12);
	p.empilhar(122);

	cout << p.desempilhar() << endl;
	cout << p.desempilhar() << endl;
	cout << p.desempilhar() << endl;
	cout << p.desempilhar() << endl;

	// cout << "1: Empilhar (valor)"<< endl;
	// cout << "2: Desempilhar"<< endl;
	// cout << "3: Consultar topo"<< endl;
	// cout << "4: Testar vazio"<< endl;
	// while(opc >= 0){
	// 	cout << "Digite uma opcao (negativo para sair): ";
	// 	cin >> opc;
	// 	switch (opc)
	// 	{
	// 	case 1:
	// 		cout << "Digite o valor a ser empilhado: ";
	// 		cin >> valor;
	// 		p.empilhar(valor);
	// 		break;
	// 	case 2:
	// 		p.desempilhar();
	// 	case 3:
	// 		cout << p.consultar_topo() << endl;
	// 	case 4:
	// 		p.vazia();
	// 	}	
	//}
}
