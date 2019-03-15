/*
Juan Francisco Torres Martínez - alu80
Alejandro Gallego López - alu37
Santiago Moltó Martínez - alu55
*/

#include <iostream>
#include <stack>

using namespace std;

int programa2(int x, int y){
    int z = 1;
    stack <int> pila;

    while(y != 0){
        pila.push(y);
        y = y / 2;
    }

    while(!pila.empty()){
        z = z * z;
        if(pila.top()%2 == 1){
            z = z * x;
        }
        pila.pop();
    }
    return z;
}

int main()
{

    int x = 0;
    int y = 0;
    int z = 1;

    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;

    if(y < 0){
        cout << "\nResultado: Error"<< endl;
    }else{
        cout << "\nResultado: "<< programa2(x,y) << endl;
    }
}

