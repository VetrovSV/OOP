#include <fstream>
#include <vector>

using namespace std;

void array2file(int *a, unsigned n, string filename){
    ofstream f(filename);

    for (unsigned i=0; i<n; i++) {
        f << a[i] << endl;
    }

    f.close();
}


void vector2file(std::vector<int> vec, string filename){
    ofstream f(filename);

    for (unsigned i=0; i<vec.size(); i++) {
        f << vec[i] << endl;
    }

    f.close();
}
