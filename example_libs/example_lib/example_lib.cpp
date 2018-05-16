#include "example_lib.h"
#include <iostream>

ClassFromLib::ClassFromLib()
{
}


void ClassFromLib::foo() const{
    std::cout << "foo" << std::endl;
}


unsigned ClassFromLib::bar(const string& s) const{
    return s.size();
}
