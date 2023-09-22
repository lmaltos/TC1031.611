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
    p = new int(34); // no se libero la referencia anterior :(
    cout << "Despues de 2do new int" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
}

void Decalogo09() {
    int *p, *q;
    int a = 12,b = 23,c = 34;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    cout << "a =\t" << a << "\tb =\t" << b << "\tc =\t" << c << endl;
    p = &a;
    q = &c;
    if (p == q) {
        cout << "p == q\t" << p << " == " << q << endl;
    }
    else {
        cout << "p != q\t" << p << " != " << q << endl;
    }
    p++;
    cout << "p++" << endl;
    if (p == q) {
        cout << "p == q\t" << p << " == " << q << endl;
    }
    else {
        cout << "p != q\t" << p << " != " << q << endl;
    }
    p++;
    cout << "p++" << endl;
    if (p == q) {
        cout << "p == q\t" << p << " == " << q << endl;
    }
    else {
        cout << "p != q\t" << p << " != " << q << endl;
    }
}

void Decalogo08() {
    int *p;
    int a = 12,b = 23,c = 34;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    cout << "a =\t" << a << "\tb =\t" << b << "\tc =\t" << c << endl;
    p = &a;
    *p = 45;
    cout << "p = &a; *p = 45" << endl;
    cout << "a =\t" << a << "\tb =\t" << b << "\tc =\t" << c << endl;
    cout << "p = " << p;
    p++;
    cout << "\tp++\t" << p << endl;
    *p = 56;
    cout << "a =\t" << a << "\tb =\t" << b << "\tc =\t" << c << endl;
    cout << "p = " << p;
    p++;
    cout << "\tp++\t" << p << endl;
    *p = 67;
    cout << "a =\t" << a << "\tb =\t" << b << "\tc =\t" << c << endl;
}

void Decalogo10() {
    int *p;
    p = new int;
    *p = 5;
    cout << "*p = 5;\t*p = " << *p << endl;
    *p = *p + 2;
    cout << "*p = *p + 2;\t*p = " << *p << endl;
    //*p++; // free(): invalid pointer
    (*p)++;
    cout << "(*p)++;\t*p = " << *p << endl;
    *p *= 7;
    cout << "*p *= 7;\t*p = " << *p << endl;
    *p /= 4;
    cout << "*p /= 4;\t*p = " << *p << endl;
    delete p;
}

int main() {
    //test1();
    Decalogo10();
}