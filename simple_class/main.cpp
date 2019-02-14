#include <iostream>
#include <assert.h>
#include "seconds.h"

using namespace std;


int main(){

    Seconds s0;
    Seconds s1(55);
    Seconds s2(5);

    Seconds s3 = s1 + s2;
    assert(s3.seconds() == 0);

    try{
        s1.setSeconds(60);
    }

    catch (SecondsException e){
        cout << "Это должно сработать!" << endl;
    }

    s3.setSeconds(59);
    s3++;
    assert(s3.seconds() == 0);

    s0.setSeconds(11);
    s3 = s0 + 40;
    assert(s3.seconds() == 51);

    s3 = s0 + 80;
    assert(s3.seconds() == 31);

    s3 = 40 + s0;
    assert(s3.seconds() == 51);

    s3 = 80 + s0;
    assert(s3.seconds() == 31);


    return 0;

}
