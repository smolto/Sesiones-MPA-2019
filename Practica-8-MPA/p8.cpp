#include <iostream>

using namespace std;

float CalcularSumaPeso(int *X, float *vPes, int k){
    float total = 0;
    for(int i = 1; i <= k ; i++){
        if(X[i] == 1){
            total = total + vPes[i];
        }
    }
    return total;
}

float CalcularSumaValor(int *X, float *vVal, int k){
    float total = 0;
    for(int i = 1; i <= k ; i++){
        if(X[i] == 1){
            total = total + vVal[i];
        }
    }

    return total;
}

void Mochila(float M, float *vPes, float *vVal, int n, int *X, int k, int *Xoptimo, float &voptimo){

    int i;
    float peso;
    float valor;

    if(k <= n){
        for(i=0; i <= 1; i++){
            X[k] = i;
            peso = CalcularSumaPeso(X,vPes,k);
            if(peso <= M){
                if(k == n){
                    valor = CalcularSumaValor(X,vVal,k);
                    if(valor > voptimo){
                        for(int j = 1; j <= k; j++){
                            Xoptimo[j] = X[j];
                        }
                        voptimo = valor;
                    }
                }else{
                    Mochila(M,vPes,vVal,n,X,k+1,Xoptimo,voptimo);
                }
            }
        }
    }

}

void MostrarDatos(float *vPes, float *vVal, int n, int *Xoptimo, float voptimo){
    float peso = 0;
    cout << endl;
    cout << "OBJETOS A INTRODUCIR EN LA MALETA" << endl;

    for(int i = 1; i <= n; i++){
        if(Xoptimo[i] == 1){
            cout << i << ": " << vPes[i] << "kg - Valor: " << vVal[i] << endl;
            peso = peso + vPes[i];
        }
    }

    cout << endl;

    cout << "Peso: " << peso << endl;
    cout << "Valor: " << voptimo << endl;

    cout << endl;

    cout << "OBJETOS QUE QUEDAN FUERA:";

     for(int i = 1; i <= n; i++){
        if(Xoptimo[i] == 0){
            cout << " " << i;
        }
     }

     cout << endl;
}

int main()
{
    int numTotalObj = 0;
    int *X;
    int *Xoptimo;
    float *vPes;
    float *vVal;
    float voptimo = -1;
    float M = 10;
    bool centinelaPesos = false;
    bool centinelaValores = false;

    cout << "Introduce el total de objetos (n):";
    cin >> numTotalObj;
    cout << endl;
    cout << "PESOS:\n";

    vPes = new float[numTotalObj+1];
    vVal = new float[numTotalObj+1];
    X = new int[numTotalObj+1];
    Xoptimo = new int[numTotalObj+1];

    for(int i = 1; i <= numTotalObj; i++){
        cout << "Objeto " << i << ":";
        cin >> vPes[i];
        cout << endl;
        X[i] = 0;
        Xoptimo[i] = 0;
        if(vPes[i] < 0){
            centinelaPesos = true;
        }
    }

    cout << "VALORES:";

    cout << endl;

    for(int i = 1; i <= numTotalObj; i++){
        cout << "Objeto " << i << ":";
        cin >> vVal[i];
        cout << endl;
        if(vVal[i] < 0){
            centinelaValores = true;
        }
    }

    if(centinelaPesos == false && centinelaValores == false){

        Mochila(M,vPes,vVal,numTotalObj,X,0,Xoptimo,voptimo);
        MostrarDatos(vPes,vVal,numTotalObj,Xoptimo,voptimo);

    }

    delete[]vPes;
    delete[]vVal;
    delete[]X;
    delete[]Xoptimo;

    return 0;
}
