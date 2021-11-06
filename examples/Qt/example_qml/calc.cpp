#include "calc.h"
#include <cmath>
#include <QDebug>
#include <random>

#include <boost/math/distributions/normal.hpp> // для математических вычислений
// boost устанавливается отдельно
// debian: sudo apt install libboost-math-dev
// https://www.boost.org/users/download/ (см. index.htm внутри архива)

using namespace boost::math;

Calc::Calc(QObject *parent) : QObject(parent)
{
}

double Calc::z() const{
    return this->_z;
}

double Calc::pvalue() const{
    return this->_p;
}


void Calc::setZ(double z1){
    this->_z = z1;
    this->_p = 0.5 * erfc(-_z * M_SQRT1_2) - 0.5;
    pvalueChanged();
    zChanged();
}


void Calc::setPvalue(double p1){
    this->_p = p1;
    this->_z = quantile(normal(0,1), _p);
    pvalueChanged();
    zChanged();
}
