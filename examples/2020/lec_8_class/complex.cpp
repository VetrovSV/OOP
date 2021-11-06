#include "complex.h"

Complex::Complex()
{

}

Complex::Complex(float a1, float b1){
    this->a = a1;
    this->b = b1;
}

Complex Complex::plus(const Complex &c2) const{
    Complex c3;
    c3.a = this->a + c2.a;
    c3.b = this->b + c2.b;

    return c3;
}

Complex Complex::operator +(const Complex &c2){
    return this->plus(c2);
}

Complex Complex::operator *(float x)
{
    return x * (*this);
}


//Complex operator +(const Complex &c1, const Complex &c2){
//    Complex c3;
//    c3.a = c1.a + c2.a;
//    c3.b = c1.b + c2.b;
//    return c3;
//}

Complex operator *(float x, const Complex &c)
{
    Complex b;
    b.a = c.a * x;
    b.b = c.b * x;
    return b;
}
