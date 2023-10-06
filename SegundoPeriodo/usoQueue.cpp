#include <iostream>
#include "queue2.h"

using namespace std;

int main() {
    queue2<char> fila;
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;
    fila.push('q');
    fila.push('w');
    fila.push('e');
    fila.push('r');
    fila.push('t');
    fila.push('y');
    fila.push('u');
    fila.push('i');
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;
    while (!fila.isEmpty()) {
        cout << fila.front() << endl;
        fila.pop();
    }
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    cout << "fila.isFull() = " << fila.isFull() << endl;
}