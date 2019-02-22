#include "b.h"

B::B(QObject *parent) : QObject(parent)
{

}


void B::my_slot(){
    cout << "Hello from B!" << endl;
}
