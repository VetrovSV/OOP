#include "firma.h"

Firm::Firm()
{

}


void Firm::addProgrammer(Student *p){
    programmers.push_back(p);
}


list <Student*> Firm::Programmers()const{
    return programmers;
}
