#ifndef ADYACENCIA_H
#define ADYACENCIA_H
#include <string>

class adyacencia {
  private:
    std::string id;
    adyacencia *next = nullptr;
  public:
    adyacencia(std::string _id) {id = _id;}
    adyacencia* Next() {return next;}
    void setNext(adyacencia* _next) {next = _next;}
    std::string ID() {return id;}
};

#endif