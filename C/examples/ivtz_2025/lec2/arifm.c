/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    puts("Hello World");

    // вывод числа

    // пример арифметического выражения с целыми числами
    // результат будет округлён тоже до целого числа
    float a = 333 / 106 ;

    // пример арифметического выражения с вещественными числами (могут содержать дробную часть)
    // результат - вещественное число
    float b = 333.0 / 106.0 ;

    printf("a = %f", a);

    puts("");

    printf("b = %f", b);

    puts(""); puts("");




    // Приведение типов данных
    float b2 = 333.0 / 106 ;

    // приведение (автоматическое преобразование) вещественного типа (float) в целый тип
    int b3 = 333.96934;
    printf("c = %i", b3);

    float b4 = 333;


    // Преобразование данных C-style cast
    int x = 20;
    int y = 7;

    // (float)x -- преобразовать значение из переменной x в вещественное число
    float c = (float)x / y;

    printf("c = %f", c);

    puts("");



    // Литералы,
    // переменные,
    unsigned int z = -1;

    z = 50;
    printf("z = %u", z);

    puts("");



    // константы.
    const int q = 34;

}
