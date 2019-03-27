#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int pedirDimensionVector();
int *inElementos(int n);
void printVector(int*, int,string);
int *quicksort(int*,int,int);
int seleccionar_pivote(int*,int,int);
void intercambiar(int*,int,int);


int n;

int main()
{
    int izq=1;
    int der;
    int *vec;
    string vecOriginal="original";
    string vecOrde="ordenado";

    n = pedirDimensionVector();
    der = n;
    vec = inElementos(n);

/*
    vec = new int[n+1];
    srand(time(NULL));
    for(int i=0;i<=n;i++){
        vec[i] = 1+rand()%(101-1);
      //  vec[i] = i;
    }
*/
    printVector(vec,n,vecOriginal);
    vec = quicksort(vec,izq,der);
    printVector(vec,n,vecOrde);


    //Liberamso memoria
    delete[]vec;
    return 0;
}

//Pide el tamaño del vector
int pedirDimensionVector(){
    int n;
    cout<<"Introduce num.total elementos del vector:";
    cin>>n;
    if(n<0){
        return 0;
    }

    return n;
}

//Rellenamos el vector con datos introducidos por el usuario
int *inElementos(int tamanyo){
    int *vec;
    vec = new int[tamanyo+1];

    for(int i=1;i<=tamanyo;i++){
        cout<<"\nIntroduce elemento "<<i<<":";
        cin>>vec[i];
    }
    cout<<endl;
    return vec;
 }

 //Imprimimos el vector
void printVector(int *vec, int tamanyo, string nombre){
    cout<<"Vector "<<nombre<<": ";
    for(int i=1;i<=tamanyo;i++){
        cout<<vec[i];
        if(i!= n){
            cout<<" ";
        }
    }
    cout<<endl;
 }


 //FUNCION DIVIDE Y VENCERAS(QUICKSORT)
int *quicksort(int *vec, int izq, int der){
    int pivote;
    int i,d,p;

    p = seleccionar_pivote(vec,izq,der);// posición central del array
    if(p >0){
        pivote = vec[p];
        i = izq;
        d = der;
        while(i<=d){
            while(vec[i] < pivote){
                i = i + 1;
            }
            while(vec[d] > pivote){
                d = d - 1;
            }
            if(i <= d){
                intercambiar(vec,i,d);
                i = i + 1;
                d = d - 1;
            }
        }//fin mientras
        if(izq < d ){
            quicksort(vec,izq,d);
        }
        if(i < der ){
            quicksort(vec,i,der);
        }
    }//fin if
    return vec;
 }

//Función seleccionar pivote
int seleccionar_pivote(int *vec,int first, int last){
    int central;
    if((first+last)%2 == 0){
        central = ((first + last) /2)+1;
    //    cout<<"\npivote par: "<<central<<endl;
        return central;
    }else{
        central = (first + last)/2;
    //    cout<<"\npivote impar: "<<central<<endl;
        return central;
    }
 }

//Funcion intercambiar valores del vector
void intercambiar(int *vec,int i,int d){
    int aux=0;

    aux = vec[i];
    vec[i] = vec[d];
    vec[d] = aux;
 }
