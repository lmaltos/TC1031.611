#ifndef QUEUE2_H
#define QUEUE2_H
#include "node.h"

template <typename T>
class queue2 {
  private:
    node<T> *tail;
  public:
    queue2();
    ~queue2();
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
};

template <typename T>
queue2<T>::queue2() {
    tail = NULL;
}

template <typename T>
queue2<T>::~queue2() {
    node<T>* nodo, *next;
    if (isEmpty())
        return; // la fila esta vacia, no hay nada que borrar
    nodo = tail->getNext(); // primer elmento de la fila
    while (nodo != tail) {
        next = nodo->getNext(); // guardar la referencia al siguiente elemento antes de borrarlo
        delete nodo; // liberar memoria del nodo
        nodo = next; // actualizar siguiente nodo en la fila a borrar
    }
    delete tail; // eliminar ultimo nodo

    // forma alternativa
    //while (!isEmpty()) {
    //    pop();
    //}
}

template <typename T>
void queue2<T>::push(T dato) {
    node<T> *nodo;
    nodo = new node<T>(dato);
    if (isEmpty()) {
        nodo->setNext(nodo);
    }
    else {
        nodo->setNext(tail->getNext());
        tail->setNext(nodo);
    }
    tail = nodo;
}

template <typename T>
void queue2<T>::pop() {
    if (isEmpty()) {
        return;
    }
    if (tail->getNext() == tail) { //primer elemento == ultimo elemento, ie solo queda un elemento
        delete tail;
        tail = NULL;
    }
    else {
        node<T>* first = tail->getNext(); // primero elemento de la fila
        node<T>* second = first->getNext(); // segundo elemento de la fila
        tail->setNext(second); // se actualiza el primer elemento de la fila
        delete first;
    }
}

template <typename T>
T queue2<T>::front() {
    node<T>* first = tail->getNext(); // primero elemento de la fila
    return first->getData();
}

template <typename T>
bool queue2<T>::isEmpty() {
    return tail == NULL;
}

template <typename T>
bool queue2<T>::isFull() {
    return false;
}

#endif