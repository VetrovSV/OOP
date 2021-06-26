#include <iostream>
#include <time.h>
#include "random_name.h"

int main(){
    srandom( time(nullptr) );
    std::cout << random_name() << std::endl;
    return 0;

}