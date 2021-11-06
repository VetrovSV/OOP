#include "date.h"

Date::Date()
{
    setDay(1);
    setMonth(1);
    setYear(0);
}

Date::Date(char day1, char month1, short year1)
{
    setDay(day1);
    setMonth(month1);
    setYear(year1);
}

short Date::getDay() const
{
    return day;
}


void Date::setDay(char value){
    if (value > 0 && value < 32)
    // TODO: проверка с учётом месяца и года
        day = value;
    // TODO: бросать исключение
}

short Date::getMonth() const
{
    return month;
}

void Date::setMonth(char value){
    if (month > 0 && month < 13)
        month = value;
    // TODO: бросать исключение

}

short Date::getYear() const
{
    return year;
}

void Date::setYear(short value)
{
    year = value;
}


