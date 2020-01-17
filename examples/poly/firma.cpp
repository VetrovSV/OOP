#include "firma.h"

Firm::Firm()
{

}


void Firm::addProgrammer(AbstractWorker *p){
    programmers.push_back(p);
}


vector <AbstractWorker*> Firm::Programmers()const{
    return programmers;
}

void Firm::do_smthng(){
        for(unsigned i = 0; i<programmers.size(); i++){
            programmers[i]->work( Task() );
}
}




