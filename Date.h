#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
    private:
    string month; // Aug, Sep, Oct, ...
    int month_i; // mes 1, 2, 3, 4, ...
    int day;
    int hour;
    int minute;
    int second;
    public:
    bool operator>(const Date&) const;
};

#endif