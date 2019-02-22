#include "student.h"

Student::Student()
{

}

Programm Student::work(const Task &task){
    Programm p;
    //...
    cout << "Student working..." << endl;
    return p;}


void Student::set_age(char a){
    //проверка
    age_ = a;
}


char Student::age() const{
    return short(age_);
}
