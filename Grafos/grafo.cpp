#include "grafo.h"
#include "../SegundoPeriodo/queue2.h"
#include "../SegundoPeriodo/stack2.h"
#include <iostream>

grafo::grafo(int n) {
    nodos = n;
    A = new bool*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new bool[n];
        for (int j = 0;j < n; j++) {
            A[i][j] = false;
        }
    }
}

grafo::~grafo() {
    for (int i = 0; i < nodos; i++) {
        delete[] A[i];
    }
    delete[] A;
}

int grafo::Nodos() {
    return nodos;
}

void grafo::setAdjacency(int i,int j) {
    if (i < 0 || i >= nodos || j < 0 || j > nodos)
        return;
    A[i][j] = true;
}

bool grafo::isAdjacent(int i,int j) {
    if (i < 0 || i >= nodos || j < 0 || j > nodos)
        return false;
    return A[i][j];
}

void grafo::BreadthFirst() {
    bool *visitado;
    queue2<int> fila;
    // inicializar el estatus de todos los nodos a "en espera"
    visitado = new bool[nodos];
    for (int i = 0; i < nodos; i++) {
        visitado[i] = false;
    }
    for (int nodo = 0;nodo < nodos; nodo++) {
        if (!visitado[nodo]) {
            fila.push(nodo);
            visitado[nodo] = true;
            while (!fila.isEmpty()) {
                int nodoActual = fila.front();
                std::cout << nodoActual << " ";
                fila.pop(); // removemos el primer nodo
                for (int j = 0; j < nodos; j++) {
                    if (isAdjacent(nodoActual,j)) {
                        if (!visitado[j]) {
                            fila.push(j);
                            visitado[j] = true;
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    delete[] visitado;
}

void grafo::DepthFirst(){
    bool *visitado;
    stack2<int> pila;
    // inicializar el estatus de todos los nodos a "en espera"
    visitado = new bool[nodos];
    for (int i = 0; i < nodos; i++) {
        visitado[i] = false;
    }
    for (int nodo = 0;nodo < nodos; nodo++) {
        if (!visitado[nodo]) {
            pila.push(nodo);
            while (!pila.isEmplty()) {
                int nodoActual = pila.top();
                pila.pop(); // removemos el primer nodo
                if (!visitado[nodoActual]) {
                    std::cout << nodoActual << " ";
                    visitado[nodoActual] = true;
                    for (int j = 0; j < nodos; j++) {
                        if (isAdjacent(nodoActual,j)) {
                            if (!visitado[j]) {
                                pila.push(j);
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    delete[] visitado;

}