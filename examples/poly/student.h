#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "task.h"
#include "programm.h"


using namespace std;

class Student{
    unsigned char age_;

public:
    Student();

    virtual Programm work(const Task& task);
    void set_age(char a);
    char age() const;


};

#endif // STUDENT_H
