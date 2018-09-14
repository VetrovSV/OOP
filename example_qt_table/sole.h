#ifndef SOLE_H
#define SOLE_H

#include <vector>

// простой шаблон класса - Системы Линейных Алгебраических Уравнений
class SoLE{
public:
    // Эти поля представляют собой коэффициенты, cтолбец свободных членов и решение СЛАУ
    std::vector <std::vector <float> > A;
    std::vector <float> B;
    std::vector <float> X;
public:
    SoLE();

    // здесь методы ...
};

#endif // SOLE_H
