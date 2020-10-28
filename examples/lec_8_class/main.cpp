#include <iostream>
#include <random>

#include "square.h"

using namespace std;

// Передавай объект всегда по ссылке
// если объект не меняется внутри функции, то добавь const
void print_square(const Square &s){
        cout << s.get_a() << endl;
}


void foo(Square s){
    //...
}


int main()
{
    Square s;

    s.set_a(42.02);

    cout << s.get_a();

    // Ссылки и указатель на объекты
    {
    // Указатель на класс Square
    Square *s1 = new Square();

    // Обращение к членам класса через указатель
    (*s1).set_a(8);

    // Обращение к членам класса через указатель
    s1->set_a(8);

    // Ссылка на экземпляр класса Square
    Square &s2 = s;
    // Обращение к членам класса через ссылку
    s2.set_a(43);

    // Ссылка на экземпляр класса Square
    Square &s3 = *s1;
    // Обращение к членам класса через ссылку
    s3.set_a(43);
}

    // Массивы из объектов
    {
    int arr1[128];
    int *arr2 = new int[128];

    // Массивы из объектов
    const unsigned n = 32;
    Square arr_s1[n];   // конструктор вызовется n раз
    Square *arr_s2 = new Square[n];  // конструктор вызовется n раз

    for (unsigned i =0; i<n; i++){
        arr_s1[i].set_a( rand() % 100 );

        arr_s2[i].set_a( rand() % 100 );
    }

    // Массив из указателей на объекты
    Square **arr_s3 = new Square*[n];  // конструктор вызовется 0 раз

    for (unsigned i =0; i<n; i++){
        // Создание объекта Sqaure
        arr_s3[i] = new Square( rand() % 100 );
        // Обращение к методу
        cout << arr_s3[i]->get_a() << " ";
    }

    delete[] arr2;
    delete[] arr_s2;

    for (unsigned i =0; i<n; i++){
        delete arr_s3[i];
    }
    delete[] arr_s3;


    Square **arr_s4 = new Square*[n];
    const unsigned m = 64;
    for (unsigned i =0; i<n; i++){
        // Создание массива из Sqaure
        arr_s4[i] = new Square[m];
    }

    for (unsigned i =0; i<n; i++){
        for (unsigned j = 0; j<n; j++)
            arr_s4[i][j].set_a( random()%10 );
    }


    for (unsigned i =0; i<n; i++){
        // Удаление массива из Sqaure
        delete[] arr_s4[i];
    }
    delete[] arr_s4;


   }

    print_square(s);

    const Square s4;
    s4.get_a();
    print_square(s4);


    Square s5; // вызывается конструктор Square()
    Square *s6; // не вызывается конструктор

    s6 = new Square();  // Выделение пямяти и вызов конустрктора Square()

    Square s51(); // вызывается конструктор Square()
    Square s7(42); // вызывается конструктор Square(float a1)

    Square s52 = Square(); // вызывается конструктор Square()
    Square s72 = Square(42); // вызывается конструктор Square(float a1)


    return 0;
}
