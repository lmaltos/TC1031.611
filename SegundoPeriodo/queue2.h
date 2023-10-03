#ifndef QUEUE2_H
#define QUEUE2_H
#include "node.h"

template <typename T>
class queue2 {
  private:
    node<T> *tail;
  public:
    queue2();
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
void queue<T>::pop() {
    if (isEmpty()) {
        return;
    }
    if (Frente == Final) {
        Frente = Final = -1;
    }
    else {
        Frente++;
        //if (Frente == QUEUE_MAX_SIZE)
        //    Frente = 0;
        //Frente = Frente % QUEUE_MAX_SIZE;
        Frente %= QUEUE_MAX_SIZE;
        //++Frente %= QUEUE_MAX_SIZE;
    }
}

template <typename T>
T queue<T>::front() {
    return datos[Frente];
}

template <typename T>
bool queue<T>::isEmpty() {
    return (Frente == -1) && (Final == -1);
}

template <typename T>
bool queue<T>::isFull() {
    //return (Final + 1 == Frente) || (Frente == 0 && Final == QUEUE_MAX_SIZE - 1);
    return (Final + 1) % QUEUE_MAX_SIZE == Frente;
}

#endif