#include <iostream>

using namespace std;

// функция считат ИМТ
// m - mass - kg
// h - рост - метры
float bmi(float m, float h){
    return m / h / h;}

// n - rows count
// m - columns count
float ** create_matrix(unsigned n, unsigned m){
    float ** matr = new float* [n];
    for (unsigned i=0; i<n; i++)
        matr[i] = new float[m];
    return matr;
}

int main(){
    // Пример 1
//    float m = 90, h = 1.8;
//    float I = bmi(m, h);
//    cout << "BMI = " << I << endl;
    // Пример 2
    unsigned n = 5, m = 5;
    float ** mat = create_matrix(n, m);

    for (unsigned i =0; i<n; i++) {
        delete [] mat[i];
    }
    delete[] mat;


    return 0;
}


