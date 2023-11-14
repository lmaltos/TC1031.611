#ifndef NODE_H
#define NODE_H
#include <string>
#include "adyacencia.h"

enum TipoEstatus {
    EnEspera,
    Procesado,
    Listo,
};

class nodo {
  private:
    std::string id;
    nodo *next = nullptr;
    adyacencia *head = nullptr; // lista de adyacencias
    TipoEstatus estatus;
  public:
    nodo(std::string);
    ~nodo();
    std::string ID();
    nodo *Next();
    TipoEstatus Estatus();
    adyacencia* listaAdyacencias();
    void setNext(nodo*);
    void setEstatus(TipoEstatus);
    void setAdyacencia(std::string);
};

nodo::nodo(std::string _id) {
    id = _id;
}

nodo::~nodo() {
    adyacencia *next;
    while (head != nullptr) {
        next = head->Next();
        delete head;
        head = next;
    }
}

std::string nodo::ID() {
    return id;
}
nodo *nodo::Next() {
    return next;
}

TipoEstatus nodo::Estatus() {
    return estatus;
}

adyacencia* nodo::listaAdyacencias(){
    return head;
}

void nodo::setNext(nodo* _next) {
    next = _next;
}

void nodo::setEstatus(TipoEstatus _estatus) {
    estatus = _estatus;
}

void nodo::setAdyacencia(std::string id) {
    adyacencia *p = new adyacencia(id);
    if (head == nullptr) {
        head = p;
        return;
    }
    adyacencia *v;
    v = head;
    while (v->Next() != nullptr) {
        v = v->Next();
    }
    v->setNext(p);
}

#endif