#ifndef NO_POLY_H
#define NO_POLY_H

#include <iostream>

// Пример без полиморфизма
namespace no_poly {
using namespace std;

class Base{
public:
//    virtual
    void foo(){cout <<"I'am Base!"<<endl;}
};


class Derived: public Base{
public:
    void foo(){cout <<"I'am Derived!"<<endl;}
};



void run_me(){
    const unsigned n = 10;
    Base **v = new Base*[10];

    cout << "Добавленные в массив указателей классы: " << endl;
    for (unsigned i = 0; i < n; i++)
        if (rand() % 2){cout << "new Base" << endl;
            v[i] = new Base();}
        else{cout << "new Derived" << endl;
            v[i] = new Derived();}

    cout << endl << "'Прочитанные' из массива классы" << endl;
    for (unsigned i = 0; i < n; i++)
        v[i]->foo();

    // Без виртуальных функций в каждом случае вызван метод базового класса,
    // не смотря на то, были записаны указатели на разные классы
}
}

#endif // NO_POLY_H
