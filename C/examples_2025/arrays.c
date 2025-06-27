#include <stdio.h>      // ...
#include <stdlib.h>     // ...

#include <math.h>

/*
Массивы

Найти сумму элементов массива a:
(a[0]/3)^2 + ... + (a[n-1] / 3)^2; 
*/

int main(){
    

    const unsigned n = 4;
    const unsigned m = 3;

    float matr[n][m];
    float sum_rows[n];

    //
    for (unsigned i = 0; i<n; i++)
        for (unsigned j = 0; j<m; j++)
            matr[i][j] = 1.0 * rand()/RAND_MAX;

    
    //
    for (unsigned i = 0; i<n; i++){
        for (unsigned j = 0; j<m; j++)
            printf("%5.2f", matr[i][j]);    
        puts("");
    }

    puts("");

    // сумма по строкам матрицы
    for (unsigned i = 0; i<n; i++){
        sum_rows[i] = 0;
        for (unsigned j = 0; j<m; j++)
            sum_rows[i] +=  matr[i][j];
    }

    
    // вывод суммы по строкам
    for (unsigned i = 0; i<n; i++){
        printf("%.2f\n", sum_rows[i]);}
    
    puts("");

}