#include <iostream>
#include "myClass.h"
#include "Registro.h"
#include <vector>
#include <fstream>

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
    vector<Registro> v;
    v.push_back(a);
    v.push_back(b);

    // swap de variables
    Registro aux;
    aux = v[1];
    v[1] = v[0];
    v[0] = aux;
    leerArchivo("Path/a/bitacora.txt", v);

    v[0].getDate();
    if (a.getDate() > b.getDate()) {
        if (a > b) {

        }
    }
}

void leerArchivo(string path, vector<Registro> &v) {
    ifstream myfile;
    string month;
    int day;
    string hour; // hh:mm:ss
    string ip;
    string message;

    myfile.open(path);
    while (!myfile.eof()) {
        myfile >> month >> day >> hour >> ip;
        getline(myfile,message);
        v.push_back(Registro(month,day,hour,ip,message));
    }
    myfile.close();
    
    for (Registro r : v) {
        r.process();
    }
}