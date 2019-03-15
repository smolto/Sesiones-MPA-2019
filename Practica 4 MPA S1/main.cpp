/*
Juan Francisco Torres Martínez - alu80
Alejandro Gallego López - alu37
Santiago Moltó Martínez - alu55
*/

#include <iostream>
#include <stack>

using namespace std;

int programa1(int x, int y){

    int x0 = x;
    int y0 = y;
    int s = 0;

    while(x0 > 1){
        //pila.push(-x+y);
        x0 = x0 - 1;
        y0 = y0 + 2;
    }
    s = y0;
    while(y0 != y){
        y0 = y0 - 2;
        x0 = x0 + 1;
        s = s - x0 + y0;
    }
    return s;
}

int main()
{
    int x;
    int y;
    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;

    cout << "\nResultado: " << programa1(x,y) << endl;
}

