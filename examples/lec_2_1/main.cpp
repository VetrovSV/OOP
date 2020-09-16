#include <iostream>
#include <time.h>
#include <iomanip>

#include "matrix.h"

using namespace std;

// функция считат ИМТ
// m - mass - kg
// h - рост - метры
float bmi(float m, float h){
    return m / h / h;}





int main(){
    // Пример 1
//    float m = 90, h = 1.8;
//    float I = bmi(m, h);
//    cout << "BMI = " << I << endl;
    // Пример 2

    srand(time(nullptr));
    cout << fixed  << setprecision(2);

    unsigned n = 5, m = 5;
    float ** mat = create_matrix(n, m);

    random_matrix(mat, n, m);

    print_matrix(mat, n, m);

    // освобождаю память
    for (unsigned i =0; i<n; i++) {
        delete [] mat[i];
    }
    delete[] mat;




    return 0;
}


