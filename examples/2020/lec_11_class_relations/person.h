#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "sertificate.h"
#include "date.h"

/*
 * Класс - Человек. Для БД отдела кадров
*/
class Person{
    std::string name, fname, middle_name;
    std::string sex;    // male \ female

    // TODO: добавить другие поля

public:
    Person();
    Person(const std::string &name1, const std::string &fname1, const std::string &middle_name1, const std::string &sex1);

    std::string getName() const;
    void setName(const std::string &value);
    std::string getFname() const;
    void setFname(const std::string &value);
    std::string getMiddle_name() const;
    void setMiddle_name(const std::string &value);
    std::string getSex() const;
    void setSex(const std::string &value);

    Date birth_date;
    Sertificate *sertificate;

};

/* Person - Целое
 * Date - Часть
 *
 * класс Person включает в себя (композирует) Date
 * класс Person включает в себя (агрегирует) Sertificate
 * */

#endif // PERSON_H
