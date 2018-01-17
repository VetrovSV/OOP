//Программа демонстрирует следующее:
// - динамический полиморфизм (виртуальные методы и классы),
// - фабрика классов,
// - реализация конструктора по умолчанию компилятром,
// - контроль постоянства,
// - проверка типа



#include <QCoreApplication>
#include <typeinfo>
#include <list>

#include "student.h"
#include "coder1.h"
#include "coder2.h"
#include "university.h"
#include "firma.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const Student s1;
    //s1.set_age(120); // контроль постоянтсва не позволить вызывать неконстантный метод
    cout<< int(s1.age()) << endl;



    Student *s = new Student(); // Виртуальный класс
    Coder1 *c1 = new Coder1();
    Coder2 *c2 = new Coder2();

    cout << "Coder1 age " << int(c1->age()) << endl;
    c1->set_age(22);
    cout << "Coder1"
            " age " << int(c1->age()) << endl;


    // один интерфейс
    s->work(Task());
    c1->work(Task());
    c2->work(Task());

    cout << endl;
    s = c1;
    // Динамическое определение типа и вызов соответствующего типу (классу) метода
    s->work(Task()); // Coder1::work()
    s = c2;
    s->work(Task()); // Coder2::work()

   // Проверка типа
   Student *x;
   x = c2;
   if (typeid(x) == typeid(Student))
       cout << "X is Student" << endl;
   else if (typeid(x) == typeid(Coder1))
            cout << "X is Coder1"<< endl;
        else cout << "X is Coder2"<< endl;


   Firm f;

// Выпуск программистов
   University U; //Генератор классов.
   list<Student*> coders;
   for (int i=0; i<15; i++){
       Student *s = U.graduate();
        coders.push_front(s);
        f.addProgrammer(s);

   }

   cout << endl;
   for (auto x : coders)
       if (typeid(*x) == typeid(Coder1))
          cout << "I am Coder1"<< endl;
       else cout << "Coder2 I am"<< endl;

   return a.exec();
}
