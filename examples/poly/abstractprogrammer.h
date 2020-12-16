#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "task.h"
#include "programm.h"


using namespace std;

class AbstractWorker{
    unsigned char age_;

public:
    AbstractWorker();

    virtual Programm work(const Task& task);

    void set_age(char a);
    char age() const;


};

#endif // STUDENT_H
