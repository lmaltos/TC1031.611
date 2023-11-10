#include <iostream>
#include <fstream>
#include "grafo.h"

using namespace std;
int main() {
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
    G.BreadthFirst();
    return 0;
}