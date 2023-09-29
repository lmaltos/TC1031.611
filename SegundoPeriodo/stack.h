#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

template <typename T>
class stack {
  private:
    T datos[MAX_SIZE];
    int tope;
  public:
    stack();
    void push(T);
    void pop();
    T top();
    bool isEmplty();
    bool isFull();
};

template <typename T>
stack<T>::stack() {
    tope = -1;
}

template <typename T>
void stack<T>::push(T data) {
    if (tope < MAX_SIZE - 1)
        datos[++tope] = data;
}

template <typename T>
void stack<T>::pop(){
    --tope;
}

template <typename T>
T stack<T>::top(){
    return datos[tope];
}

template <typename T>
bool stack<T>::isEmplty(){
    return tope == -1;
}

template <typename T>
bool stack<T>::isFull(){
    return tope == MAX_SIZE - 1;
}

#endif