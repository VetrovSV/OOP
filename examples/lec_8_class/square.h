#ifndef SQUARE_H
#define SQUARE_H

enum SquareExceptions { InvalidArgument };

class Square{
private: // закрытый раздел
    float a;

public:  // открытый раздел
    Square();  // конструктор без параметров
    Square(float a1);  // конструктор с параметром

    // методы
    void set_a(float a1);
    float get_a();

    float perimeter();
    float area();

};


#endif // SQUARE_H
