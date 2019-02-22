#include "seconds.h"

Seconds::Seconds(){
    this->s = 0;}

Seconds::Seconds(SecType s1){
    setSeconds(s1);
}

void Seconds::setSeconds(SecType s1){
    if (s1 >= 0  && s1 < 60 ) // проверка предусловий
        this->s = s1;
    else
        throw InvalidValue;
}

SecType Seconds::seconds() const{
       return s;
}


std::string Seconds::toString() const{
    return std::to_string(s);
}


Seconds Seconds::operator +(const Seconds& s2) const{
    Seconds s3 = s2.s + *this;
    return s3;}


Seconds Seconds::operator +(SecType s2) const{
    Seconds s3 = s2 + *this;
    return s3;}


Seconds Seconds::operator ++(int){
    Seconds s3 = *this;
    this->s = (this->s + 1) % 60;
    return s3;
}


Seconds operator + (SecType s1, const Seconds &s2){
    Seconds s3;
    s3.s = (s1 + s2.s) % 60;
    return s3;
}
