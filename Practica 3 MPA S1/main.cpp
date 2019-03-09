#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int sumadigitos(int numero, int contador){
    if(numero < 0){
        cout << contador << ")sumadigitos(" << numero << ")" << endl;
        return -1;
    }else if(numero >= 0 && numero <= 9){
        cout << contador << ")sumadigitos(" << numero << ")" << endl;
        return numero;
    }else{
        cout << contador << ")sumadigitos(" << numero << ")" << endl;
        contador ++;
        return sumadigitos(numero/10,contador) + (numero%10);
    }
}

int main()
{
    int numero;

    cout << "1. SUMA DIGITOS\n";
    cout << "---------------";
    cout << "\nIntroduce numero:";

    cin >> numero;                              //Input por teclado del numero

    cout << "\nTraza\n";
    /*
    */
    cout << "\nEl resultado es: " << sumadigitos(numero,1) << endl;
    return 0;
}

