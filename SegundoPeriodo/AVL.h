#ifndef AVL_H
#define AVL_H
#include "BST.h"

template <typename T>
class AVL : public BST<T> {
    public:
    void add(T);
    bool isBalanced(T);
    bool isBalanced(nodeT<T>*);
    int calcHeight(nodeT<T>*);
    nodeT<T>* getPivote(T);
    void swap(nodeT<T>*,nodeT<T>*);
    void RSI(nodeT<T>*);
    void RDI(nodeT<T>*);
    void RSD(nodeT<T>*);
    void RDD(nodeT<T>*);
};

template <typename T>
void AVL<T>::add(T data) {
    BST<T>::add(data); // se agrega nodo como en BST
    if (!isBalanced(data)) {
        nodeT<T> *pivote = getPivote(data);
        nodeT<T> *A;
        if (pivote->Data() < data) {
            A = pivote->Right();
            if (A->Data() < data) {
                RSI(pivote);
            }
            else {
                RSI(pivote);
            }
        }
        else {
            A = pivote->Left();
            if (A->Data() > data) {
                RSD(pivote);
            }
            else {
                RDD(pivote);
            }
        }
    }
}

template <typename T>
bool AVL<T>::isBalanced(T data){
    nodeT<T>* nodo = BST<T>::root;
    while (nodo->Data() != data) {
        if (!isBalanced(nodo))
            return false; // encontramos un nodo no balanceado :(
        nodo = nodo->Data() > data ? nodo->Left() : nodo->Right();
    }
    return true; // nuestro arbol esta balanceado :)
}

template <typename T>
bool AVL<T>::isBalanced(nodeT<T>* nodo) {
    int leftHeight = calcHeight(nodo->Left());
    int rightHeight = calcHeight(nodo->Right());
    if (rightHeight - leftHeight <= 1 && rightHeight - leftHeight >= -1)
        return true; // el nodo esta balanceado
    return false;
}

template <typename T>
int AVL<T>::calcHeight(nodeT<T>* nodo) {
    if (nodo == NULL)
        return 0;
    int leftHeight = calcHeight(nodo->Left());
    int rightHeight = calcHeight(nodo->Right());
    int height = leftHeight > rightHeight ? leftHeight : rightHeight; // Operador ternario (condicion) ? (valor si true) : (valor si false)
    return height + 1;
}

template <typename T>
nodeT<T>* AVL<T>::getPivote(T data){
    nodeT<T> *nodo = BST<T>::root, *pivote;
    while (nodo->Data() != data) {
        if (!isBalanced(nodo)) {
            pivote = nodo;
        }
        nodo = nodo->Data() > data ? nodo->Left() : nodo->Right();
    }
    return pivote;
}

template <typename T>
void AVL<T>::swap(nodeT<T> *pivote,nodeT<T> *nuevo) {
    if (pivote == BST<T>::root) {
        BST<T>::root = nuevo;
        return;
    }
    nodeT<T> *nodo = BST<T>::root, *padre;
    while (nodo != pivote) {
        padre = nodo;
        nodo = nodo->Data() > pivote->Data() ? nodo->Left() : nodo->Right();
    }
    // el pointer padre, es el padre de pivote
    if (padre->Data() > pivote->Data()) {
        padre->setLeft(nuevo);
    }
    else {
        padre->setRight(nuevo);
    }
}

template <typename T>
void AVL<T>::RSI(nodeT<T> *B) {
    nodeT<T> *A = B->Right();
    B->setRight(A->Left());
    A->setLeft(B);
    swap(B,A);
}

template <typename T>
void AVL<T>::RDI(nodeT<T> *B) {
    // ToDo
}

template <typename T>
void AVL<T>::RSD(nodeT<T> *B) {
    // ToDo
}

template <typename T>
void AVL<T>::RDD(nodeT<T> *B) {
    // ToDo
}

#endif