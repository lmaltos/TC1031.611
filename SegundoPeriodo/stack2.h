#ifndef STACK2_H
#define STACK2_H
#include "node.h"

template <typename T>
class stack2 {
  private:
    node<T> *tope;
    int size;
  public:
    stack2();
    ~stack2();
    void push(T);
    void pop();
    T top();
    bool isEmplty();
    bool isFull();
};

template <typename T>
stack2<T>::stack2() {
    size = 0;
    tope = NULL;
}

template <typename T>
stack2<T>::~stack2() {
    node<T> *next;
    while (tope != NULL) {
        next = tope->getNext();
        delete tope;
        tope = next;
    }
}

template <typename T>
void stack2<T>::push(T data) {
    node<T> *newNode;
    newNode = new node<T>(data,tope);
    tope = newNode;
    size++;
}

template <typename T>
void stack2<T>::pop() {
    node<T> *next;
    next = tope->getNext();
    delete tope;
    tope = next;
    size--;
}

template <typename T>
T stack2<T>::top(){
    return tope->getData();
}

template <typename T>
bool stack2<T>::isEmplty(){
    return tope == NULL; // size == 0;
}

template <typename T>
bool stack2<T>::isFull() {
    return false;
}

#endif