//Программа демонстрирует следующее:
// - динамический полиморфизм (виртуальные методы и классы),
// - фабрика классов,
// - реализация конструктора по умолчанию компилятором,
// - контроль постоянства,
// - проверка типа

#include <QCoreApplication>
#include <typeinfo>
#include <list>
#include "abstractprogrammer.h"
#include "coder1.h"
#include "coder2.h"
#include "university.h"
#include "firma.h"
#include "no_poly.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    // Контроль постоянтсва
//    const AbstractWorker a1;
//    //s1.set_age(120); // контроль постоянства не позволить вызывать не константный метод
//    // у объекта-константы можно вызывать можно только константные методы:
//    cout<< int(a1.age()) << endl;

//    // При использовании виртуальных классов следует использовать переменные-указатели на классы,
//    // вместо экземпляров класса непосредственно.
//    // Указатель на любой класс занимает фиксированное количество памяти.
//    // Но если записать в переменную базового класса производный, то потомок будет "обрезан" по размерам предка.
//    // Виртуальный класс
//    AbstractWorker *s = new AbstractWorker();
//    // Потомки...
//    Coder1 *c1 = new Coder1();
//    Coder2 *c2 = new Coder2();
//    // у них один интерфейс (метод  work) но работает он по-разному
//    s->work(Task());
//    c1->work(Task());
//    c2->work(Task());
//    cout << endl;
//    s = c1;

//    // Динамическое определение типа и вызов соответствующего типу (классу) метода
//    s->work(Task()); // Coder1::work()
//    s = c2;
//    s->work(Task()); // Coder2::work()
//
    // Проверка типа
//   AbstractWorker *x;
//   x = c2;
//   if (typeid(x) == typeid(AbstractWorker))
//       cout << "X is Student" << endl;
//   else if (typeid(x) == typeid(Coder1))
//            cout << "X is Coder1"<< endl;
//        else cout << "X is Coder2"<< endl;
   Firm f;
// Выпуск программистов
   University U; //Генератор классов.
   list<AbstractWorker*> coders; // Список для примера
   for (int i=0; i<15; i++){
       AbstractWorker *s = U.graduate();
        coders.push_front(s);
        f.addProgrammer(s);
}
    f.do_smthng();
//   cout << endl;
//   for (auto x : coders)
//       if (typeid(*x) == typeid(Coder1))
//          cout << "I am Coder1"<< endl;
//       else cout << "Coder2 I am"<< endl;
//   // Пример: без виртуальных функций ничего не работает
//   cout << endl;
//   no_poly::run_me();
   return a.exec();
}
