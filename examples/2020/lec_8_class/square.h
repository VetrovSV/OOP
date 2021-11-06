#ifndef SQUARE_H
#define SQUARE_H

enum SquareExceptions { InvalidArgument };

class Square{
private: // закрытый раздел
    float a;    // поле - перем. внутри класса

public:  // открытый раздел

    // Конструкторы -- функции инициализирующие объект
    Square();  // конструктор без параметров
    Square(float a1);  // конструктор с параметром

    // методы - функции внутри класса
    void set_a(float a1);
    float get_a() const;    // const значит, что метод не меняет полей класса

    float perimeter() const;
    float area() const;

};


#endif // SQUARE_H
