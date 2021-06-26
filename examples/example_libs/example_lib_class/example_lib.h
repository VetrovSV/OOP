#ifndef EXAMPLE_LIB_H
#define EXAMPLE_LIB_H

#include <string>

#include "example_lib_global.h"

using namespace std;

class EXAMPLE_LIBSHARED_EXPORT ClassFromLib
{

public:
    ClassFromLib();

    void foo() const;

    unsigned bar(const string& s) const;
};

#endif // EXAMPLE_LIB_H
