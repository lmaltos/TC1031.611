#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
    private:
    string month;
    int day;
    int hour;
    int minute;
    int second;
    public:
    bool operator>(const Date&);
};

#endif