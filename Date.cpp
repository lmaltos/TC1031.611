#include "Date.h"

bool Date::operator>(const Date& b) {
    if (this->month != b.month)
        return this->month > b.month;
    else if (this->day != b.day)
        return this->day > b.day;
        // .....
    return false;
}