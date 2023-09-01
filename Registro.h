#ifndef REGISTRO_H
#define REGISTRO_H

#include "Date.h"

class Registro {
    private:
    Date date;
    string ip;
    string message;
    public:
    Date getDate() {return date;}
    bool operator>(const Registro &b) {return date > b.date;}
};

#endif