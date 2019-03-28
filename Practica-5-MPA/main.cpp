#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void intercambiar(int *v,int i,int d){
    int aux=0;

    aux = v[i];
    v[i] = v[d];
    v[d] = aux;

}

int seleccionar_pivote(int *v,int izq, int der){

    return (izq + der) / 2;

 }

void *quicksort(int *v, int izq, int der){
    int i,d,p;
    int pivote;

    p = seleccionar_pivote(v, izq, der);

    if(p > 0){
        pivote = v[p];
    (L[i] + L[j]) / 2    i = izq;
        d = der;

        while(i <= d){
            while(v[i] < pivote){
                i = i + 1;
            }

            while(v[d] > pivote){
                d = d - 1;
            }

            if(i <= d){
                intercambiar(v,i,d);
                i = i + 1;
                d = d - 1;
            }
        }

        if(izq < d )
            quicksort(v,izq,d);
        if(i < der)
            quicksort(v,i,der);
    }

    return v;

}

int main()
{
    int *v;
    int n;
    int i = 1;
    int izq = 1;
    int der;

    cout << "Introduce num.total elementos del vector:";
    cin >> n;
    cout << endl;

    v = new int[n+1];
    der = n;

    for(i=1;i<=n;i++){
        cout << "Introduce elemento " << i <<":";
        cin >> v[i];
        cout << endl;

    }

    cout << "Vector original: ";
    for(i=1;i<=n;i++){
        cout << v[i];
        if(i != n){
            cout << " ";
        }
    }
    cout << endl;

    quicksort(v,izq,der);

    cout << "Vector ordenado: ";
    for(i=1;i<=n;i++){
        cout << v[i];
        if(i != n){
            cout << " ";
        }
    }
    cout << endl;

    delete []v;

    return 0;
}
