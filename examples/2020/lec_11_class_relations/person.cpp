#include "person.h"

std::string Person::getName() const
{
    return name;
}

void Person::setName(const std::string &value)
{
    name = value;
}

std::string Person::getFname() const
{
    return fname;
}

void Person::setFname(const std::string &value)
{
    fname = value;
}

std::string Person::getMiddle_name() const
{
    return middle_name;
}

void Person::setMiddle_name(const std::string &value)
{
    middle_name = value;
}

std::string Person::getSex() const
{
    return sex;
}

void Person::setSex(const std::string &value){
// TODO: проверка пола
    sex = value;
}

Person::Person()
{
    sertificate = nullptr;
}

Person::Person(const std::string &name1, const std::string &fname1, const std::string &middle_name1, const std::string &sex1)
{
    setName(name1);
    setFname(fname1);
    setMiddle_name(middle_name1);
    setSex(sex1);
    sertificate = nullptr;

}
