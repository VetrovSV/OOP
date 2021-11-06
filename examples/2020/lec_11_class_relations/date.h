#ifndef DATE_H
#define DATE_H

/* Класс - Дата */
class Date{
    char day, month;
    short year;
public:
    Date();
    Date(char day1, char month1, short year1);

    short getDay() const;
    void setDay(char value);

    short getMonth() const;
    void setMonth(char value);

    short getYear() const;
    void setYear(short value);
};

#endif // DATE_H
