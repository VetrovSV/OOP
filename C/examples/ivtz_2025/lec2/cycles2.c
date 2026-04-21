#include <stdio.h>


// https://ivtipm.github.io/Programming/Glava04/index04.htm#z77 (В)
// 77 Дано натуральное число n. Вычислить (см. формулу по ссылке)
//
int main(){

    unsigned int n = 4;     // n - количество скобок в выражении


    // TODO: считывать значение в переменную n

    float a;        // результат вычисления одной скобки

    float P = 1.0;        // результат произведения скобок

    // Вариант решения с циклом while
    // //puts("Отчёт о работе цикла: ");
    // while ( i <= n ){
    //     a = 1.0 + 1.0 / (i*i) ;

    //     P = P * a;

    //     // printf("i=%u: a = %f;   P = %f\n", i, a, P);

    //     // i = i + 1;
    //     i++;
    // }

    // Вариант решения с циклом for
    puts("Отчёт о работе цикла: ");
    for ( unsigned int i = 1; i<= n; i++ )
    {
        a = 1.0 + 1.0 / (i*i) ;

        P = P * a;

        printf("i=%u: a = %f;   P = %f\n", i, a, P);

    }

    printf("Произведение: %.2f\n", P);

}
