#ifndef FIRMA_H
#define FIRMA_H
#include<list>
#include"student.h"



class Firm
{
    list <Student*> programmers;

public:

    Firm();
    void addProgrammer(Student *p);
    list <Student*> Programmers() const;
};

#endif // FIRMA_H
