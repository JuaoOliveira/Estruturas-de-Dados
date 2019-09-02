#include <iostream>
using namespace std;

// x = numero que desejamos encontrar     n = numero de elementos    v = aponta p/ o primeiro elemento

int contar_ocorrencias(double *v, int n, double x){
    //ponteiro que vai percorrer o vetor
    double *p; 
    
    //ponteiro que aponta para o primeiro elemento do vetor (nesse caso isso não é necessário, pois o vetor v que é passado pelo parametro já aponta para o primeiro espaço do vetor)
    double *prim = &v[0]; 
    
    // ponteiro para o ultimo elemento do vetor
    double *ult = &v[n-1]; 
    
    //vai contar o numero de vezes que achou o numero procurado
    int contador=0; 

    for (p = prim; p <= ult; p++){ 
	// Essa é a parte chave do que ele pede. Na primeira parte do for, o ponteiro vai receber o endereço do primeiro elemento do vetor que foi recebido, e vai passando por todos os elementos até chegar no ultimo. 
	//Se tu quer entender um pouco mais, olha esse video
	//https://www.youtube.com/watch?v=pFMjDq4bk-w
	
        if (*p == x) // Aqui tem uma logica simples, se o valor do elemento atual for igual ao valor procurado, o contador vai aumentar em 1, e vai fazer isso até o ultimo ter sido percorrido
            contador++;
    }
    //Nesse if eu só faço ele dizer se o numero que a pessoa digitou foi achado ou não.
    if (contador > 0){
        cout << "O numero foi encontrado " << contador << " vez(es).";
        return contador;
    } else{
        cout << "Não foi encontrado o numero procurado.";
        return 0;
    }
    

}

int main(){
    int n = 0, x = 0;

    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    double v[n];
    double *p = &v[0]; 

    for(int i = 0; i < n; i++){
        cout << "Digite um numero: ";
        cin >> v[i]; 
    }
    cout << '\n';

    cout << "Digite o numero a ser pesquisado: ";
    cin >> x;

    cout << '\n';

    contar_ocorrencias(p,n,x);
}
