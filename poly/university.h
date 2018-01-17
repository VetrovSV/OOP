#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <student.h>
#include <coder1.h>
#include <coder2.h>

class University
{
public:
    University()=default; // реализация конструтора по-умолчанию компилятором.

    Student* graduate();
};

#endif // UNIVERSITY_H
