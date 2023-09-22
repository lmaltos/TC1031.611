#include <iostream>
#include "ejemplo.h"

using namespace std;

int main() {
    Ejemplo a1(10), *d1;
    d1 = new Ejemplo(100,5,6);
    (*d1).getA();
    d1->getA();
    delete d1;
    return 0;
}