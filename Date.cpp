#include "Date.h"

bool Date::operator>(const Date& b) const{
    if (this->month != b.month)
        return this->month_i > b.month_i;
    else if (this->day != b.day)
        return this->day > b.day;
        // .....
    return false;
}