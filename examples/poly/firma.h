#ifndef FIRMA_H
#define FIRMA_H
#include<list>
#include"abstractprogrammer.h"



class Firm
{
    list <AbstractWorker*> programmers;

public:

    Firm();
    void addProgrammer(AbstractWorker *p);
    list <AbstractWorker*> Programmers() const;
};

#endif // FIRMA_H
