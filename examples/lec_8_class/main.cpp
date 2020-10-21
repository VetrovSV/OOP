#include <iostream>

#include "square.h"

using namespace std;

int main()
{
    Square s;

    s.set_a(42.02);

    cout << s.get_a();

    cout << "Hello World!" << endl;
    return 0;
}
