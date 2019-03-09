#include <iostream>

using namespace std;

bool esPar(int numero){
    if(numero % 2 == 0){
        return true;
    }else{
        return false;
    }
}

int multiplicacion(int x, int y, int total, int contador){
    cout << contador ++ << ")multiplicacion(" << x << "," << y << ")\n";
    if(x <= 1){
        total = total + (x*y);
        return total;
    }else{
        if(!esPar(x)){
            total = total + (y);
            return multiplicacion(x/2, y*2, total, contador);
        }else{
            return multiplicacion(x/2, y*2, total, contador);
        }
    }
}

int main()
{
    int x, y;
    cout << "3. MULTIPLICACION\n";
    cout << "-----------------\n";
    cout << "Introduce primer numero:";
    cin >> x;
    cout << "\nIntroduce segundo numero:";
    cin >> y;
    cout << "\nTraza\n";
    cout << "\nEl resultado es: " << multiplicacion(x,y,0,1) << endl;
    return 0;
}
