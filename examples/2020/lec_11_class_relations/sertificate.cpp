#include "sertificate.h"

std::string Sertificate::getId() const
{
    return id;
}

void Sertificate::setId(const std::string &value)
{
    id = value;
}

std::string Sertificate::getName() const
{
    return name;
}

void Sertificate::setName(const std::string &value)
{
    name = value;
}

std::string Sertificate::getFname() const
{
    return fname;
}

void Sertificate::setFname(const std::string &value)
{
    fname = value;
}

std::string Sertificate::getMiddle_name() const
{
    return middle_name;
}

void Sertificate::setMiddle_name(const std::string &value)
{
    middle_name = value;
}

std::string Sertificate::getQualification() const
{
    return qualification;
}

void Sertificate::setQualification(const std::string &value)
{
    qualification = value;
}

Sertificate::Sertificate()
{

}
