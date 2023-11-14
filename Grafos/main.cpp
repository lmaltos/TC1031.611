#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo.h"
#include "grafoLA.h"

using namespace std;
int main_MA() {
    ifstream archivo;
    int n;
    bool b;
    archivo.open("grafoEjemplo.txt");
    archivo >> n;
    grafo G(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n; j++) {
            archivo >> b;
            if (b) {
                G.setAdjacency(i,j);
                //cout << "Adyacencia entre " << i << " y " << j << endl;
            }
        }
    }
    archivo.close();
    cout << "Breadth First: ";
    G.BreadthFirst();
    cout << "Depth First: ";
    G.DepthFirst();
    return 0;
}

int main() {
    grafoLA G;
    ifstream archivo;
    string id,linea;
    archivo.open("grafoEjemploLA.txt");
    while (!archivo.eof()) {
        archivo >> id;
        cout << "Agrega nodo " << id << endl;
        nodo *n = G.addNodo(id);
        getline(archivo,linea); //E| A B C H G
        stringstream ss(linea);
        while (!ss.eof()) {
            ss >> id;
            cout << "Agrega adyacencia " << id << endl;
            G.addAdyacencia(n,id);
        }
    }
    archivo.close();
    G.DepthFirst();
}