#ifndef GRAFOLA_H
#define GRAFOLA_H
#include "nodo.h"
#include <stack>
#include <iostream>

class grafoLA {
  private:
    nodo *head = nullptr;
  public:
    ~grafoLA();
    nodo* addNodo(std::string);
    nodo* listaNodos();
    void addAdyacencia(nodo*,std::string);
    void BreadthFirst();
    void DepthFirst();
    nodo* getNodoByID(std::string);
};

grafoLA::~grafoLA() {
    nodo *next;
    while (head != nullptr) {
        next = head->Next();
        delete head;
        head = next;
    }
}

nodo* grafoLA::addNodo(std::string id) {
    nodo *v = new nodo(id);
    if (head == nullptr) {
        head = v;
    }
    else {
        nodo *u = head;
        while (u->Next() != nullptr) {
            u = u->Next();
        }
        u->setNext(v);
    }
    return v;
}

nodo* grafoLA::listaNodos(){
    return head;
}

void grafoLA::addAdyacencia(nodo* v,std::string id){
    v->setAdyacencia(id);
}

void grafoLA::BreadthFirst() {
    // ToDo
}

void grafoLA::DepthFirst() {
    nodo *v = listaNodos();
    while (v != nullptr) {
        v->setEstatus(EnEspera);
        v = v->Next();
    }
    std::stack<nodo*> pila;
    v = listaNodos();
    while (v != nullptr) {
        if (v->Estatus() == EnEspera) {
            pila.push(v);
            while (!pila.empty()) {
                nodo *u = pila.top();
                pila.pop();
                if (u->Estatus() != Procesado) {
                    std::cout << u->ID() << " ";
                    u->setEstatus(Procesado);
                    adyacencia* a = u->listaAdyacencias();
                    while (a != nullptr) {
                        nodo *w = getNodoByID(a->ID());
                        if (w->Estatus() != Procesado) {
                            pila.push(w);
                        }
                        a = a->Next();
                    }
                }
            }
        }
        v = v->Next();
    }
    std::cout << std::endl;
}

nodo* grafoLA::getNodoByID(std::string id) {
    nodo *v = head;
    while (v != nullptr) {
        if (v->ID() == id) {
            return v;
        }
        v = v->Next();
    }
    return nullptr;
}

#endif