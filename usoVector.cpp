#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void fillVector(vector<int>&,int);
template <typename T>
void swap(vector<T>&,int,int);
void printVect(vector<int>&);

int main() {
    vector<int> myVect;
    int n = 1000;
    srand(time(0)); // semilla aleatoria
    fillVector(myVect,n);
    printVect(myVect);
    swap(myVect,32,128);
    cout << "Se realiza swap" << endl;
    printVect(myVect);
}

void fillVector(vector<int> &myVect, int n) {
    for (;n > 0;n--) {
        myVect.push_back(rand());
    }
}

template <typename T>
void swap(vector<T> &myVect,int a,int b) {
    T aux;
    aux = myVect[b];
    myVect[b] = myVect[a];
    myVect[a] = aux;
}

void printVect(vector<int> &myVect) {
    int n = myVect.size();
    for (int i = 1; i < n; i*=2) {
        cout << "myVect[" << i << "] = " << myVect[i] << endl;
    }
}