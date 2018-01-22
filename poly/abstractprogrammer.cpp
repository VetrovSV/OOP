#include "abstractprogrammer.h"

AbstractWorker::AbstractWorker()
{

}

Programm AbstractWorker::work(const Task &task){
    Programm p;
    //...
    cout << "Student working..." << endl;
    return p;}


void AbstractWorker::set_age(char a){
    //проверка
    age_ = a;
}


char AbstractWorker::age() const{
    return short(age_);
}
