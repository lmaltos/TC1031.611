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
    vector<Registro> v;
    Date fecha_ini, fecha_fin;
    leerArchivo("Path/a/bitacora.txt", v);
    fastBogoSort(v);
    
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

template <typename T>
void swap(vector<T> &myVector, int i, int j) {
    T aux = myVector[j];
    myVector[j] = myVector[i];
    myVector[i] = aux;
}

template <typename T>
void suffle(vector<T> &myVector) {
    int n = myVector.size();
    int k = rand() % 1000;
    int i,j;
    do {
        i = rand() % n;
        j = rand() % n;
        swap(myVector,i,j);
    } while (--k > 0);
}

template <typename T>
bool isSorted(vector<T> &myVector) {
    int n = myVector.size();
    for (int i = 0; i < n - 1; i++) {
        if (myVector[i] > myVector[i+1])
            return false;
    }
    return true;
}

template <typename T>
void fastBogoSort(vector<T> &myVector) {
    int n = myVector.size();
    for (int i = 1; i < log(n); i++) {
        suffle(myVector);
        if (isSorted(myVector))
            return;
    }
}