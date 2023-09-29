#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
    linkedList<int> listaInt;
    listaInt.addFirst(1);
    listaInt.addFirst(2);
    listaInt.addFirst(3);
    listaInt.addFirst(4);
    listaInt.addFirst(5);
    listaInt.addFirst(6);
    listaInt.addFirst(7);
    listaInt.print();
    listaInt.addLast(10);
    listaInt.addLast(11);
    listaInt.addLast(12);
    listaInt.addLast(13);
    listaInt.print();

    linkedList<std::string> listaStr;
    listaStr.addFirst("Olla");
    listaStr.addFirst("Estufa");
    listaStr.addFirst("Jarra");
    listaStr.addFirst("Plato");
    listaStr.print();
    listaStr.addLast("Tenedor");
    listaStr.addLast("Cuchara");
    listaStr.addLast("Cuchillo");
    listaStr.addFirst("Sarten");
    cout << "listaStr[5] = " << listaStr[5] << endl;
    listaStr.print();
}