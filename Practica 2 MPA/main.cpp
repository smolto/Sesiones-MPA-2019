#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int pedirSemilla(){
    int s;
    cout<<"Semilla para generar aleatorios:"<<endl;
    cin>>s;

    return s;
}
int pedirTamanyoVector(){
    int n;
    cout<<"Introduce tamanyo del vector:"<<endl;
    cin>>n;

    return n;
}

/*
int pedirPosiciones(){
    int ini, fin;
    cout<<"Posiciones INICIAL y FINAL del vector para mostrar"<<endl;
    cout<<"INICIAL: "<<endl;
    cin>>ini;
    cout<<"FINAL: "<<endl;
    cin>>fin;

    return ini, fin;
}*/

//función muestrara vector
void mostrarVector(int *vec, int n , string vnombre){
    cout<<"\n\nVector "<<vnombre<<":"<<endl;
    for(int i=1;i<=n;i++){
        cout<<vec[i];
        cout<<" ";
    }
 }

//Muestra las posiciones del vector
void mostrarVecPosition(int *vec, int inicio, int fin){
//    cout<<"Vector"<<endl;
    for(int i = inicio; i<=fin; i++){
        cout<<vec[i];
        if(i!=fin){
            cout<<" ";
        }
    }
}

//algoritmo de ordenación ascendente
int *insercionCualquiera(int *vec, int n){
    int i, j, x;
    for(i = 2; i<=n; i++){
        x = vec[i];
        j = i-1;
        while(j>0 && vec[j] > x){
            vec[j+1]= vec[j];
            j = j-1;
        }
        vec[j+1] = x;
    }
    return vec;
}

// Invertimos el orden para el CASO PEOR
void *desordenarVector(int *vec, int n){
    int i, j, x;
    for(i = 2; i<=n; i++){
        x = vec[i];
        j = i-1;
        while(j>0 && vec[j] < x){
            vec[j+1]= vec[j];
            j = j-1;
        }
        vec[j+1] = x;
    }
    return vec;
}

int main()
{

    int *V;
    int n,ini,fin, semilla, showtime;
    clock_t tinicio, tfin;
    double tiempo;

    string vec = "Vector prueba";

    semilla = pedirSemilla();
    n = pedirTamanyoVector();

    //Reservamos memória dinámica
    V = new int [n+1];
    if (V == NULL)
    {
        cout << "Fallo al reservar memoria" << endl;
        system("pause");
        return (-1);
    }

    srand(semilla);// Inicializar los número aleatorios

    //Introducimos valores aleatorios dentro del vector
    for(int i=1;i<=n;i++){
        V[i]= rand();
    }


    cout<<"Posiciones INICIAL y FINAL del vector para mostrar"<<endl;
    cout<<"INICIAL:"<<endl;
    cin>>ini;
    cout<<"FINAL:"<<endl;
    cin>>fin;
    cout<<"Mostrar tiempo de ejecucion (1:Si, 0:No):"<<endl;
    cin>>showtime;

    cout<<"\nALGORITMO DE INSERCION"<<endl;

    if(showtime==1){
        cout<<"\nCASO CUALQUIERA"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
        cout <<endl<< "Tiempo <ms>:" << tiempo;

        cout<<"\nCASO MEJOR"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
        cout <<endl<< "Tiempo <ms>:" << tiempo;

        //DESORDENAMOS EL VECTOR/////
        desordenarVector(V,n);

       // cout<<"\n\nDesordenado: ";
      //  mostrarVecPosition(V,ini,fin);

        cout<<"\nCASO PEOR"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
        cout <<endl<< "Tiempo <ms>:" << tiempo;
        cout<<"\nFIN DEL PROGRAMA";
    }else{
        cout<<"\nCASO CUALQUIERA"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
      //  cout <<endl<< "Tiempo <ms>:" << tiempo;

        cout<<"\nCASO MEJOR"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
     //   cout <<endl<< "Tiempo <ms>:" << tiempo;

        //DESORDENAMOS EL VECTOR/////
        desordenarVector(V,n);

       // cout<<"\n\nDesordenado: ";
      //  mostrarVecPosition(V,ini,fin);

        cout<<"\nCASO PEOR"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Vector a ordenar: ";
        mostrarVecPosition(V,ini,fin);
        tinicio = clock();//almacenamos el instante actual
        insercionCualquiera(V,n);
        tfin = clock();//almacenamos el instate actual
        tiempo = (double)(tfin-tinicio)/ CLOCKS_PER_SEC * 1000;
        cout<<"\nVector ordenado: ";
        mostrarVecPosition(V,ini,fin);
        cout<<"\nFIN DEL PROGRAMA"<<endl;
     //   cout <<endl<< "Tiempo <ms>:" << tiempo;
    }



  //  mostrarVector(V,n,vec);

    delete[] V;
    return 0;
}
