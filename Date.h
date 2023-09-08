#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
    private:
    //string month; // Aug, Sep, Oct, ...
    int month_i; // mes 1, 2, 3, 4, ...
    int day;
    int hour;
    int minute;
    int second;
    public:
    Date();
    Date(int,int); // mes y dia
    Date(int,int,int,int,int); // mes, dia, hh, mm, ss
    bool operator>(const Date&) const;
};

#endif