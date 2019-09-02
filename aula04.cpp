#include <iostream>
#include <cmath>

using namespace std;

double *ler_vetor(int n){
    double *notas = new double[n];

    for(int i = 0; i < n; i++){
        cout << "Digite a nota do aluno " << i + 1 << ": ";
        cin >> notas[i];
    }
    return notas;
}

double soma(double *v, int n){
    double s = 0;

    for(int i = 0;i < n; i++)
        s += v[i];
    return s;
}

double media(double soma, int n){
    return soma/n;
}

int main (){
    int n;

    cout << "Digite o numero de alunos: ";
    cin >> n;

    cout << '\n';

    double *notas = ler_vetor(n);

    cout << '\n';

    double sum = soma(notas,n);

    cout.precision(3);
    cout << "A media da turma eh: " << media(sum,n) << '\n';

    double med = media(sum,n);

    for(int i = 0; i < n; i++){
        if((notas[i] - med) > 0)
            cout << "A media do aluno " << i+1 << " esta " << abs(notas[i] - media(sum,n)) << " acima da media.\n";
        else if((notas[i] - med == 0))
            cout << "A media do aluno " << i+1 << " esta " << " na media.\n";
        else
            cout << "A media do aluno " << i+1 << " esta " << abs(notas[i] - media(sum,n)) << " abaixo da media.\n";
    }
    delete[] notas;
}