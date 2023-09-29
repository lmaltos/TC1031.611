#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>

template <class T>
class linkedList {
  private:
    node<T> *head;
    int size;
    node<T>* getData(int);
  public:
    linkedList();
    ~linkedList();
    void addFirst(T);
    void addLast(T);
    T operator[](int);
    void print();
};

template <class D>
linkedList<D>::linkedList() {
    size = 0;
    head = NULL;
}

template <class T>
linkedList<T>::~linkedList() {
    node<T> *nodo,*next;
    nodo = head;
    while (nodo != NULL) {
        std::cout << nodo << "\t" << nodo->getData() << std::endl;
        next = nodo->getNext();
        delete nodo;
        nodo = next;
    }
    head = NULL;
    size = 0;
}

template <class S>
void linkedList<S>::addFirst(S data) {
    node<S> *nodo;
    nodo = new node<S>(data,head);
    //nodo->setNext(head); // se realiza en el constructor
    head = nodo;
    size++;
}

template <class S>
void linkedList<S>::addLast(S data) {
    node<S> *last,*newNodo;
    newNodo = new node<S>(data);
    last = head;
    if (last != NULL) {
        while (last->getNext() != NULL) {
            last = last->getNext();
        }
        last->setNext(newNodo);
    }
    else {
        head = newNodo;
    }
    size++;
}

template <class S>
node<S>* linkedList<S>::getData(int k) {
    node<S> *last;
    last = head;
    if (k >= size)
        throw std::out_of_range("Index k > size");
    while (k > 0) {
        last = last->getNext();
        k--;
    }
    return last;
}

template <class S>
S linkedList<S>::operator[](int k) {
    return getData(k)->getData();
}

template <class S>
void linkedList<S>::print() {
    node<S> *nodo;
    nodo = head;
    while (nodo != NULL) {
        std::cout << nodo->getData() << " ";
        nodo = nodo->getNext();
    }
    std::cout << std::endl;
}

#endif