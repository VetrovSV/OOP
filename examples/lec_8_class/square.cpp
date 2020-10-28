#include "square.h"

Square::Square(){
    a = 0;
}

Square::Square(float a1){
   set_a(a1);
}


void Square::set_a(float a1){
    if (a1 >= 0)
        a = a1;
    else throw InvalidArgument;
}

float Square::get_a(){
    return a;
}

float Square::perimeter(){
    return a*4;
}

float Square::area(){
    return a*a;
}
