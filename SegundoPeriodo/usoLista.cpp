#include "linkedList.h"
#include <string>

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

    linkedList<std::string> listaStr;
    listaStr.addFirst("Olla");
    listaStr.addFirst("Estufa");
    listaStr.addFirst("Jarra");
    listaStr.addFirst("Plato");
    listaStr.print();
}