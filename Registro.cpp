#include "Registro.h"

/// Recive un mes en formato de tres caracteres Aug, Sep, Oct, ...
/// y regresa un numero asociado
int mtoi(string month) {
    if (month == "Aug")
        return 8;
    else if (month == "Sep")
        return 9;
    else if (month == "Oct")
        return 10;
    else if (month == "Nov")
        return 11;
    return -1;
}

void paseHHMMSS(string hhmmss, int &h, int &m, int &s) {
    h = stoi(hhmmss.substr(0,2));
    m = stoi(hhmmss.substr(3,2));
    s = stoi(hhmmss.substr(6,2));
}

Registro::Registro(string _month, int _day, string _hhmmss, string _ip, string _message) {
    month = _month;
    day = _day;
    hhmmss = _hhmmss;
    ip = _ip;
    message = _message;
}

void Registro::process() {
    int h,m,s;
    paseHHMMSS(hhmmss,h,m,s);
    date = Date(mtoi(month),day,h,m,s);
}