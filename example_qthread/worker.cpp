#include <math.h>
#include "worker.h"

Worker::Worker(QObject *parent):QObject(parent)
{
    n = 0;
    result = 0;

}

void Worker::set_param(unsigned long n){
    this->n = n;
}


void Worker::process(){
    this->result = 0;

    for ( unsigned long i = 0; i<=n; i++)
        this->result += sin(i);

    finished();
}


double Worker::get_result() const{
    return this->result;
}


Worker::~Worker(){

}
