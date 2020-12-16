#ifndef CALCULATOR_H
#define CALCULATOR_H
/* Ветров С.В.
*/


/* реализует логику калькулятора
*/
class Calculator
{
private:
    float op1, op2;  // операнды

public:
    Calculator();

    float plus();

    float sin(float op);
};

#endif // CALCULATOR_H
