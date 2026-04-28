#include <stdio.h>
#include <math.h>

// Дано положительное число Х
// Вычислить корень 4 степени из числа Х

int main(){

    float x;
    float x_root4;

    do {
        // тело цикла
        printf("Введите положительное число x = ");
        scanf("%f", &x);
        // условие цикла
    } while ( x < 0 );


    x_root4 = pow(x, 1.0 / 4.0 );
    printf("Корень 4-й степени из х: %.4f", x_root4);


    puts("");


}
