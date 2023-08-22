#ifndef MYCLASS_H
#define MYCLASS_H

template <class T>
class myClass {
  private:
    T a;
    T b;
  public:
    myClass(T _a, T _b) : a(_a), b(_b) {}
    T getA() {return a;}
    T getB() {return b;}
    void setA(T _a) {a = _a;}
    void setB(T _b) {b = _b;}
    T getFoo();
};

template <class T>
T myClass<T>::getFoo() {
    return a;
}

#endif