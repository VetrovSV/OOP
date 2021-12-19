#include <stdexcept>
#include "calculator.h"

Calculator::Calculator()
{

}

float Calculator::plus()
{
    // ...
    return 0;
}

float Calculator::div()
{
    // ...
        throw std::logic_error("Zero Divizion!");
    //

}

float Calculator::sin(float op){
    this->op1 = op;
    this->op2 = sin(op);
    return op2;
}

