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
    // TODO: поле - сколько операндов задано


public:
    Calculator();

    // TODO: метод записывающий значение в операнд

    float plus();
    float div();

    // TODO: остальные операции

    float sin(float op);
};

#endif // CALCULATOR_H
