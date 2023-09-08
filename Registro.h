#ifndef REGISTRO_H
#define REGISTRO_H

#include "Date.h"

class Registro {
  private:
    Date date;
    string month, hhmmss;
    int day;
    string ip;
    string message;
  public:
    Registro(string,int,string,string,string);
    void process();
    Date getDate() {return date;}
    bool operator>(const Registro &b) {return date > b.date;}
};

#endif