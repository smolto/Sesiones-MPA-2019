#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int calculoTiempoEjecucion(int *v, int *pr, int n){

    int suma = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
             suma += v[j];
        }
    }

    return suma;
}

void intercambiar(int *vec,int *pr,int i,int d){
    int aux=0;

    aux = vec[i];
    vec[i] = vec[d];
    vec[d] = aux;
    aux = pr[i];
    pr[i] = pr[d];
    pr[d] = aux;
 }

int seleccionar_pivote(int *vec,int first, int last){
    int central;

    central=(first + last)/2;

    if((vec[first] >= vec[central] &&  vec[first] < vec[last]) || (vec[first] <= vec[central] && vec[first] > vec[last])){
        return first;
    }else if((vec[central] > vec[first] && vec[central] < vec[last]) || (vec[central] < vec[first] && vec[central] > vec[last])){
        return central;
    }else if((vec[last] > vec[first] && vec[last] < vec[central]) || (vec[last] < vec[first] && vec[last] >= vec[central])){
        return last;
    }

    return 0;
 }

void quicksort(int *v, int *pr, int izq, int der){
    int pivote;
    int i,d,p,j=1;

    p = seleccionar_pivote(v,izq,der);// posición central del array
    j++;

    if(p >0){
        pivote = v[p];
        i = izq;
        d = der;
        while(i<=d){
            while(v[i] < pivote){
                i = i + 1;
            }
            while(v[d] > pivote){
                d = d - 1;
            }
            if(i <= d){
                intercambiar(v,pr,i,d);
                i = i + 1;
                d = d - 1;
            }
        }//fin mientras
        if(izq < d ){
            quicksort(v,pr,izq,d);
        }
        if(i < der ){
            quicksort(v,pr,i,der);
        }
    }
}

int main()
{
    int *v;
    int *pr;
    int n;

    cout<<"Introduce num.total de procesos:";
    cin>>n;

    if(n<0){
        return 0;
    }

    v = new int[n+1];
    pr = new int[n+1];
    v[0] = 0;
    for(int i=1;i<=n;i++){
        cout<<"\nIntroduce tiempo del proceso "<<i<<":";
        cin>>v[i];
        pr[i] = i;

    }

    quicksort(v,pr,1,n);

    cout << "\nTiempo minimo: " << calculoTiempoEjecucion(v,pr,n);

    cout << "\nOrden:";
    for(int t = 1; t <= n; t++){
        cout << pr[t];
        if(t < n){
            cout << " ";
        }
    }
    cout << endl;
    delete[]v;
    delete[]pr;
    return 0;
}
