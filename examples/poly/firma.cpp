#include "firma.h"

Firm::Firm()
{

}


void Firm::addProgrammer(AbstractWorker *p){
    programmers.push_back(p);
}


list <AbstractWorker*> Firm::Programmers()const{
    return programmers;
}
