#include "Date.h"

Date::Date() {
    month_i = 1;
    day = 1;
    hour = minute = second = 0;
}

Date::Date(int _month_i, int _day) {
    month_i = _month_i;
    day = _day;
    hour = minute = second = 0;
}

Date::Date(int _month_i, int _day, int _hour, int _minute, int _second) {
    month_i = _month_i;
    day = _day;
    hour = _hour;
    minute = _minute;
    second = _second;
}

bool Date::operator>(const Date& b) const{
    if (this->month_i != b.month_i)
        return this->month_i > b.month_i;
    else if (this->day != b.day)
        return this->day > b.day;
        // .....
    return false;
}