#include <QCoreApplication>
#include "a.h"
#include "b.h"



int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    A *a = new A();
    B *b = new B();
    QObject::connect(a, SIGNAL(my_signal()), b, SLOT(my_slot()));
    a->my_signal();

    return app.exec();
}
