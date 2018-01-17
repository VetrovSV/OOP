#ifndef PROGR2_H
#define PROGR2_H

#include "student.h"

class Coder2 : public Student
{
public:
    Coder2();

    Programm work(const Task &task);
};

#endif // PROGR2_H
