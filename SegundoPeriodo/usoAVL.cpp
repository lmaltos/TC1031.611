#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL<int> arbol;
    AVL<int> arbol2;
    int a;
    // se van a necesitar rotaciones simple a la derecha
    for (int i = 100; i > 0; i--) {
        arbol.add(i);
        if (i % 20 == 0) {
            arbol.printPorNivel();
            cout << endl;
        }
    }

    // Si se agregan elementos en orden aleatorio se requieren todas las rotaciones implementadas
    for (int i = 0; i < 100; i++){
        a = rand() % 100;
        arbol2.add(a);
        if (i % 20 == 0) {
            arbol.printPorNivel();
            cout << endl;
        }
    }
}