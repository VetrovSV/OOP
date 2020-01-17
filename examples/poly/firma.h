#ifndef FIRMA_H
#define FIRMA_H
#include<vector>
#include"abstractprogrammer.h"



class Firm
{
    vector <AbstractWorker*> programmers;

public:

    Firm();
    void addProgrammer(AbstractWorker *p);
    vector <AbstractWorker*> Programmers() const;

    void do_smthng();
};

#endif // FIRMA_H
