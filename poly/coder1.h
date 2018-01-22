#ifndef PROGR1_H
#define PROGR1_H

#include "abstractprogrammer.h"

class Coder1 : public AbstractWorker
{
public:
    Coder1();

    Programm work(const Task &task);
};

#endif // PROGR1_H
