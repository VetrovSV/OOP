#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <abstractprogrammer.h>
#include <coder1.h>
#include <coder2.h>

class University
{
public:
    University()=default; // реализация конструтора по-умолчанию компилятором.

    AbstractWorker* graduate();
};

#endif // UNIVERSITY_H
