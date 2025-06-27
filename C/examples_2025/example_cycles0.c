#include <stdio.h>      // ...
#include <stdlib.h>     // ...

#include <math.h>


/*

 Cycles:
 - цикл со счётчиком: for
 - цикл в предусловием: while
 - цикл в постусловием: do .. while


  while ( условие )     // заголовок цикла
  // тело цикла:
  {
  
  }

    int n = 0;
    puts("Введите натуральное число");
    scanf("%d", &n);

    while ( n <= 0 ){
        puts("Введите натуральное!!! число");
        scanf("%d", &n);
    }

    puts("Ok");


    int n = 0;
    
    do {
        puts("Введите натуральное число");
        scanf("%d", &n);
    } while ( n <= 0 );

    puts("Ok");
}


*/

int main(){

    // Задача: численно, методом прямоугольников, вычислить площадь под кривой y = sin(x);
    // Вход: a,b - отрезок на котором нужно вычислить интеграл
    //       n - количество отрезков (прямоугольников)

    // float a = 0, b = 3.1415;        // ..
    // unsigned n = 10'000;            // ..

    // float Sum = 0.0;              // ..
    // float s = 0;                  // ..
    // float h = (b-a)/n;            // ..

    // float x = a;
    // while( x < b ){
    //     s = h * sin(x+h/2);
    //     // Sum = Sum + s;
    //     Sum += s;
    //     // x = x + h;
    //     x += h;
    // }

    // printf("Integral from %6.4f to %6.4f (n = %d) = %6.7f\n", a, b, n, Sum );


}