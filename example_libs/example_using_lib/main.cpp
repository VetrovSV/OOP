#include <QCoreApplication>
#include <iostream>
#include <string>

// Заголовочный файл для библиотеки
#include "example_lib.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClassFromLib c;
    c.foo();
    cout << c.bar("qwerty") << endl;


    return a.exec();
}
