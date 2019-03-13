#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> pila;
    int a, b, resultado;
    cout << "Introduce valores de a:";
    cin >> a;
    cout << "\nIntroduce valores de b:";
    cin >> b;

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

    cout << "\nResultado: " << resultado << endl;
    return 0;
}
