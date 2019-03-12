#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack <int> pila;
    int x = 5;
    int y = 4;

    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;

    while(x > 1){
        pila.push(-x+y);
        x = x - 1;
        y = y + 2;
    }

    while(! pila.empty()){
        y = y + pila.top();
        pila.pop();
    }

    cout << "\nResultado: " << y << endl;
}
