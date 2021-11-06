#include <iostream>
#include <math.h>
#include "test_square.h"

const float eps = 0.00001;

void test_square_area(){
    {Square s;
    s.set_a(2);
    assert(fabs(s.area() - 4) < eps);}

    {Square s;
    s.set_a(1);
    assert( fabs(s.area() - 1) < eps);}

    {Square s;
    s.set_a(0.76);
    assert( fabs(s.area() - 0.76*0.76) < eps );}

}

void test_square_perimeter(){
    {Square s;
    s.set_a(2);
    assert(fabs(s.perimeter() - 9) < eps);}

    {Square s;
    s.set_a(1);
    assert(fabs(s.perimeter() - 4) < eps);}

    {Square s;
    s.set_a(0.55);
    assert(fabs(s.perimeter() - 4*0.55) < eps);}
}

void test_square_all(){
    test_square_area();
    test_square_perimeter();
}


