#include <stdio.h>
#include <math.h>

// Задание 424: https://ivtipm.github.io/Programming/Glava12/index12.htm#z424
// Даны действительные числа s, t. Получить .....

/// функция вычисляет по формуле из задания 424
#include <math.h>
float f(float a, float b, float c){
    // тип возвращаемого значения функции -- float (см. перед f)
    float r = ( 2.0*a - b * sin(c) ) / ( 5.0 + fabs(c) );

    // возврат значения
    return r;
}


int main(){

    float s = 1.0;
    float t = 2.0;

    float result = 0.0;

    result = f(t, -2.0*s, 1.17) + f(2.2, t, s-t);

    printf("%.2f", result);

    puts("");

    return 0;
}
