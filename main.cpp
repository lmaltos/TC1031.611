#include <iostream>
#include "myClass.h"
#include "Registro.h"

using namespace std;

template <typename T>
T Max(T a, T b) {
    if (a > b)
        return a;
    return b;
}

int main_old() {
    int x = 4, y = 10;
    float r = 3.14, g = 9.18;
    char a = 'e', b = 'G';
    cout << "El maximo es: " << Max<char>(a,b) << endl;
    cout << "El maximo es: " << Max<int>(x,y) << endl;
    cout << "El maximo es: " << Max<float>(r,g) << endl;
    return 0;
}

int main() {
    myClass<int> a(3,4);
    myClass<char> a('d','R');
    myClass<float> a(3.14,4.59);
}

void PruebaOrdenamiento() {
    Registro a, b;
    if (a.getDate() > b.getDate()) {
        if (a > b) {
            
        }
    }
}