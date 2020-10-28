#include "square.h"

Square::Square(){
    // this - указатель на объект
    this->a = 0;
}

Square::Square(float a1){
   set_a(a1);
}


void Square::set_a(float a1){
    if (a1 >= 0)
        this->a = a1;
    else throw InvalidArgument;
}

float Square::get_a() const{
    return this->a;
}

float Square::perimeter() const{
    return this->a*4;
}

float Square::area() const{
    return this->a * this->a;
}
