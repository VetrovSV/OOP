#ifndef PROGR2_H
#define PROGR2_H

#include "abstractprogrammer.h"

class Coder2 : public AbstractWorker
{
public:
    Coder2();

    Programm work(const Task &task);
};

#endif // PROGR2_H
