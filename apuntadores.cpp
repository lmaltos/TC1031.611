#include <iostream>

using namespace std;

void test1() {
    int a = 5, *p;
    p = new int;
    *p = a;
    a = *p + 2;
    cout << a << " " << *p << endl;
    cout << "&a = " << &a << endl;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
    cout << "Despues de delete p" << endl;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
}

// Por cada new se requiere un delete
void Decalogo01() {
    int *p;
    cout << "Antes del new" << endl;
    cout << "p = " << p << endl;
    p = new int;
    *p = 42;
    cout << "Despues del new" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
    p = NULL;
    cout << "Despues del delete" << endl;
    cout << "p = " << p << endl;
    if (p != NULL) {
        cout << "*p = " << *p << endl;
        delete p;
        cout << "p = " << p << endl;
        cout << "*p = " << *p << endl;
    }
}


void Decalogo02() {
    int *p, *q, *r;
    cout << "Antes del new" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    p = new int;
    q = r = p;
    cout << "Despues del new" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    delete r;
    cout << "Despues del delete" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    //delete q;
}

int* test03() {
    int *p;
    p = new int;
    *p = 24;
    cout << "&p =" << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    return p;
}

void Decalogo03() {
    int *q;
    q = test03();
    cout << "&q =" << &q << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    delete q;
}

// Basura != Nada
void Decalogo04() {
    int *p, *q = NULL;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
}

void Decalogo05() {
    int a, *p;
    p = &a;
    cout << "p = &a = " << &a << endl;
    delete p;
}

void Decalogo06() {
    int *q = NULL;
    cout << "&q = " << &q << endl;
    cout << "q = " << q << endl;
    *q = 5;
}

void Decalogo07() {
    int *p;
    p = new int;
    *p = 12;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    p = new int(34);
    cout << "Despues de 2do new int" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
}

int main() {
    //test1();
    Decalogo07();
}