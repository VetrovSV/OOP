#include <iostream>
#include <vector>
#include "seconds.h"
#include "tests/test.h"

using namespace std;



int main(){
    test_SimpleClass_all(); // тесты. пример для второго семестра


    // ниже приведены различные примеры работы с объектами класса Seconds

    Seconds s1, s2(12);

    Seconds s1234 = 12; // к. преобразования

    Seconds s3 = s1 + s2++;
    cout << "секунды: " << s3.toString()  << endl;

    Seconds *s = new Seconds;   // динамическое создание
    s->setSeconds(10);
    delete s;

    vector<Seconds> vec1;   // набор из объектов
    vec1.push_back(s1);
    vec1.push_back(s2);

    for (int i=0; i<10; i++){
        Seconds s( rand() % 60 );
        vec1.push_back(s);
    }

    cout << "Секунды:"<< endl;
    for (Seconds s : vec1){
        cout << s.toString() << endl;
    }

    vec1[1].setSeconds(20); // обращение к отдельному элементу вектора. вызов метода
    Seconds s5 = vec1[1];


    vector<Seconds*> vec2;   // набор из указателей на объекты
    Seconds *s4 = new Seconds(42);
    vec2.push_back(s4);
    vec2.push_back(new Seconds(43));

    for (int i=0; i<10; i++){
        Seconds *s = new Seconds( rand() % 60 );
        vec2.push_back(s);
    }

    cout << "Секунды:"<< endl;
    for (Seconds *s : vec2){
        cout << s->toString() << endl;
    }

    vec2[1]->setSeconds(20); // обращение к отдельному элементу вектора. вызов метода
    Seconds *s6 = vec2[1];

    // удаление динамически созданных объектов
    for (int i=0; i<vec2.size(); i++){
        delete vec2[i];
    }


    return 0;

}
