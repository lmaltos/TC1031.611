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

int main() {
    test1();
}