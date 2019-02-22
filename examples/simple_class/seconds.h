#ifndef SECONDS_H
#define SECONDS_H
#include <string>
// только подключение модуля. без using в заголовочном файле

// для удобства оперделим отдельно синоним для типа.
// чтобы было легко сменить при необходимости в будущем
typedef short SecType;

// Исключения
enum SecondsException { InvalidValue };


// Класс для работы с секундными интервалами от 0 до 59
// Класс не содержит всех необходимых (или содержит лишние) методы и операторы  методы и операторы
// его основная цель продемонстрировать особенности создания классов на С++

class Seconds{
    // закрытое поле
    SecType s;
public:

    Seconds();                              // конструктор по умолчанию
    Seconds(SecType s1);                    // конструктор с параметром (преобразования)

    void setSeconds(SecType s1);
    SecType seconds() const;

    std::string toString() const;                 // возвращает строковое представление данных класса. для примера

    Seconds operator + (const Seconds& s2) const;   // сложение Seconds и Seconds. при переполнении возвращает результат по модулю 60
    Seconds operator + (SecType s2) const;          // сложение Seconds и числа. при переполнении возвращает результат по модулю 60

                                              // постфиксный оператор (вида s++). int в параметрах - только для того, чтобы отличить от префиксного
    Seconds operator ++ (int);                // увеличение секунд на 1. при переполнении возвращает результат по модулю 60

    friend Seconds operator + (SecType s1, const Seconds &s2);
};

    Seconds operator + (SecType s1, const Seconds &s2);   // для соложения числа и секунд


#endif // SECONDS_H
