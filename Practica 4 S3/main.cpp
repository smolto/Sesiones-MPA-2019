/*
Juan Francisco Torres Martínez - alu80
Alejandro Gallego López - alu37
Santiago Moltó Martínez - alu55
*/

#include <iostream>
#include <stack>

using namespace std;

int programa3(int a, int b){
    stack <int> pila;
    int resultado = 0;

    while (a >= 3){
        pila.push(a);
        a = a / 3;
        b = b - 2;
    }
    resultado = a + b;
    while(!pila.empty()){
        resultado = resultado + pila.top();
        pila.pop();
    }
    return resultado;
}

int main()
{

    int a, b;
    cout << "Introduce valores de a:";
    cin >> a;
    cout << "\nIntroduce valores de b:";
    cin >> b;

    cout << "\nResultado: " << programa3(a,b) << endl;
    return 0;
}
