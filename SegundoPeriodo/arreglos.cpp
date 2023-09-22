#include <iostream>

using namespace std;

int main() {
    int arreglo[40];
    int *p;
    p = arreglo;
    for (int i = 0; i < 40; i++) {
        //*p = rand() % 100;
        //p++;
        p[i] = rand() % 100;
    }
    for (int i = 0; i < 40; i++) {
        cout << arreglo[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    return 0;
}