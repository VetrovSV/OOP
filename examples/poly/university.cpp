#include "university.h"

//University::University()
//{

//}


AbstractWorker* University::graduate(){
    if (rand()%2)
        return new Coder1();
    else
        return new Coder2();
}
