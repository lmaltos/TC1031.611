#ifndef GRAFO_H
#define GRAFO_H

class grafo {
  private:
    int nodos; // numero de elementos
    bool **A;
  public:
    grafo(int);
    ~grafo();
    int Nodos();
    void setAdjacency(int,int);
    bool isAdjacent(int,int);
    void BreadthFirst();
};

#endif