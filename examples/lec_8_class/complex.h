#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
public:
    float a,b;

    Complex();
    Complex(float a1, float b1);

    Complex plus(const Complex &c2) const;
    Complex operator + (const Complex &c2);
    Complex operator *(float x);  // c * x, где c = this

};

Complex operator *(float x, const Complex& c);   // x * c
//Complex operator + (const Complex &c1, const Complex &c2);

#endif // COMPLEX_H
