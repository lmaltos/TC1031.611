#ifndef EJEMPLO_H
#define EJEMPLO_H
#include <iostream>

class Ejemplo {
    int a;
    int b;
    int n;
    int *p;
  public:
    Ejemplo(int _n) {
        n = _n;
        p = new int[n];
        std::cout << "constructor 1" << std::endl;
    }
    Ejemplo(int _n, int _a, int _b) {
        n = _n;
        p = new int[n];
        a = _a;
        b = _b;
        std::cout << "constructor 2" << std::endl;
    }
    ~Ejemplo() {
        std::cout << "Se llama destructor con n = " << n << std::endl;
        delete[] p;
    }
    int getA() {return a;}
    int getB() {return b;}
    int getN() {return n;}
    void setN(int _n) {
        n = _n;
        delete[] p;
        p = new int[n];
    }
};

#endif