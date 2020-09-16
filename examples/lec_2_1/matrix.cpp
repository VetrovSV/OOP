#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// n - rows count
// m - columns count
float ** create_matrix(unsigned n, unsigned m){
    float ** matr = new float* [n];
    for (unsigned i=0; i<n; i++)
        matr[i] = new float[m];
    return matr;
}

// зполняет матр сл. числами
void random_matrix(float ** matr, unsigned n, unsigned m){
    for (unsigned i=0; i<n; i++)
        for (unsigned j=0; j<m; j++)
            matr[i][j] = rand() % 100;
}


void print_matrix(float ** matr, unsigned n, unsigned m){
    for (unsigned i=0; i<n; i++){
        for (unsigned j=0; j<m; j++)
            cout << setw(6)<< matr[i][j] << " ";
        cout << endl;
    }
}
