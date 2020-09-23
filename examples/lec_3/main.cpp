#include <iostream>
#include <vector>
#include "m42.h"
#include "array.h"

using namespace std;
using namespace m42;

int main()
{
    unsigned n = 10;
    int *arr = new int[n];
    for (unsigned i=0; i<n; i++)
        arr[i]=i;

    array2file(arr,n,"out.txt");



    // динамический массив из n элементов. все нули
    vector<int> v(n,0);

    for (unsigned i=0; i<v.size(); i++)
        v[i]=i;

    vector2file(v, "vec-out.txt");



    m42::print42();
//    cout << "Hello World!" << endl;
    return 0;
}
