#ifndef MATRIX_H
#define MATRIX_H

/* Модуль для работы с матрицами
 *
 *
 */

// n - rows count
// m - columns count
float ** create_matrix(unsigned n, unsigned m);

// зполняет матр сл. числами
void random_matrix(float ** matr, unsigned n, unsigned m);


void print_matrix(float ** matr, unsigned n, unsigned m);

#endif // MATRIX_H
