#include <iostream>

using namespace std;

float funcionF(int x, float y){
    float result = 0;
    cout << "F(" << x << "," << y << ")\n";
    if(x == 0){
        result = 1;
    }else if(x == 1){
        result = 2*y;
    }else if(x >= 2){
        result = (2*y)*funcionF(x-1,y)-2*(x-1)*funcionF(x-2,y);
    }else if(x <= 0){
        result = -1;
    }

    return result;
}

int main()
{
    int x;
    float y, validador;
    cout << "2. FUNCION F\n";
    cout << "------------\n";
    cout << "Introduce valor x:";
    cin >> x;
    cout << "\nIntroduce valor y:";
    cin >> y;
    if(x < 0){
        cout << "\nError" << endl;
    }else{
        if(x >= 0){
            cout << "\nTraza\n";
        }
        validador = funcionF(x,y);
        if(validador == -1){
            cout << "\nError" << endl;
        }else{
            cout << "\nEl resultado es: " << validador <<endl;
        }
    }
    return 0;
}
